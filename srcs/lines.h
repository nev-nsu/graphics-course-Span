#pragma once

#include "graphics.h"

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

struct TLines {
private:
    std::filesystem::path Filename;

public:
    std::vector<TLineShape> Lines;

    bool HasFilename() const;
    bool Load(std::string&& filename);
    bool Save(std::string&& filename);
};
