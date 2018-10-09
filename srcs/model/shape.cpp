#include "shape.h"

#include "circle.h"
#include "fill.h"
#include "polygon.h"

#include <cctype>
#include <fstream>
#include <iostream>

namespace {
    const char* fileExt = ".spn";
    const char* tempExt = ".tmp";

    // Declare all new shapes here!
    const auto readers = {&TPolygon::Read, &TFill::Read, &TCircle::Read};
    const auto signs = {TPolygon::Signature, TFill::Signature, TCircle::Signature};

    // Returns clean strings without empty or connected lines
    std::string ReadChunk(std::istream& stream) {
        return {}; //TODO: write an implementation
    }
}

bool TShapes::HasFilename() const {
    return !Filename.empty();
}

bool TShapes::Load(std::string&& filename) {
    Filename = std::move(filename);
    Filename.replace_extension(fileExt);
    std::vector<std::unique_ptr<IShape>> temporaryData;

    std::ifstream input(Filename);
    if (!input.is_open() || !input.good()) {
        return false;
    }

    try {
        auto correctShape = true;
        auto currentChunk = ReadChunk(input);

        while (correctShape && !currentChunk.empty()) {
            correctShape = false;
            for (auto reader : readers) {
                auto result = reader(currentChunk);
                if (result) {
                    auto shape = dynamic_cast<IShape*>(result.release());
                    temporaryData.emplace_back(shape);
                    correctShape = true;
                    break;
                }
            }
        }

        if (!correctShape) {
            return false;
        }
    } catch (...) {
        return false;
    }

    Data = std::move(temporaryData);
    return true;
}

bool TShapes::Save(std::string&& filename) {
    auto useTemporaryFile = false;
    if (!filename.empty()) {
        Filename = std::move(filename);
        Filename.replace_extension(tempExt);
        useTemporaryFile = true;
    }

    std::ofstream output(Filename);
    if (!output.is_open() || !output.good()) {
        return false;
    }

    try {
        output << Data.size() << std::endl;
        for (const auto& shape: Data) {
            output << shape->Write() << std::endl;
        }
    } catch (...) {
        return false;
    }

    if (useTemporaryFile) {
        auto TempFile = Filename;
        Filename.replace_extension(fileExt);
        try {
            std::filesystem::rename(TempFile, Filename);
        } catch (...) {
            return false;
        }
    }

    return true;
}
