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

    auto StartsWith(const std::string& str, const std::string& what) {
        return str.substr(0, what.size()) == what;
    }

    auto IsSign(const std::string& str){
        for (const auto& sign : signs) {
            if (StartsWith(str, sign)) {
                return true;
            }
        }

        return false;
    }

    // Returns clean strings without empty or connected lines
    std::string ReadChunk(std::istream& stream) {
        static std::string line;
        std::cout << "readchunk " << line << std::endl;
        bool firstRun = line.empty();
        std::ostringstream output;
        if (!line.empty()) {
            output << line << ' '; // Chunk signature
        }
        while (!stream.eof() && stream.good()) {
            std::getline(stream, line);
            std::cout << "test " << line << std::endl;
            auto start = line.find_first_not_of(" \t\n");
            if (start == std::string::npos) {
                continue;
            }
            line = line.substr(start, std::string::npos);
            if (!StartsWith(line, "//")) {
                if (IsSign(line)) {
                    if (!firstRun) {
                        break;
                    }
                    firstRun = false;
                }
                output << line << " ";
            }
        }
        if (stream.eof()) {
            line.clear();
        }
        std::cout << output.str();
        return output.str();
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
                std::cout << "Try to parse: " << currentChunk << std::endl;
                auto result = reader(currentChunk);
                std::cout << "Try to parse: " << (result? "ok" : "fail")  << std::endl;
                if (result) {
                    auto shape = dynamic_cast<IShape*>(result.release());
                    temporaryData.emplace_back(shape);
                    std::cout << "Shape found: " << currentChunk << std::endl;
                    correctShape = true;
                    break;
                }
            }
            currentChunk = ReadChunk(input);
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
