#include "lines.h"

#include <cctype>
#include <fstream>
#include <iostream>

namespace {
    const char* fileExt = ".le";
    const char* tempExt = ".letmp";
    const char* polylineSign = "Polyline";

    TLineShape ParseLineShape(std::ifstream& input) {
        std::string signature;
        input >> signature;
        if (signature != polylineSign) {
            throw std::exception();
        }

        TLineShape result;
        std::string line;
        std::getline(input, line);
        while (input.good() && !input.eof()) {
            std::getline(input, line);
            if (line.empty() || !std::isdigit(line.front())) {
                break;
            }
            std::istringstream lineInput(line);
            ui32 x, y;
            lineInput >> x >> y;
            result.emplace_back(x, y);
        }

        return result;
    }
}

bool TLines::HasFilename() const {
    return !Filename.empty();
}

bool TLines::Load(std::string&& filename) {
    Filename = std::move(filename);
    Filename.replace_extension(fileExt);
    std::vector<TLineShape> temporaryData;

    std::ifstream input(Filename);
    if (!input.is_open() || !input.good()) {
        return false;
    }

    try {
        ui32 count;
        input >> count;
        temporaryData.reserve(count);

        for (; count > 0; count--) {
            temporaryData.push_back(ParseLineShape(input));
        }
    } catch (...) {
        return false;
    }

    Lines = std::move(temporaryData);
    return true;
}

bool TLines::Save(std::string&& filename) {
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
        output << Lines.size() << std::endl;
        for (const auto& line: Lines) {
            output << polylineSign << std::endl;
            for (const auto& point: line) {
                output << point.first << " " << point.second << std::endl;
            }
            output << std::endl;
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
