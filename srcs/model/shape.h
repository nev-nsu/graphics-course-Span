#pragma once

#include <QPainter>
#include <string>
#include <optional>
#include <filesystem>

using ui32 = uint32_t;
using TPoint = std::pair<ui32, ui32>;
using TPainter = QPainter;

class ISerializable {
public:
    // Don't know how to declare it propely
    // static std::unique_ptr<ISerializable> Read(const std::string& data);

    virtual std::string Write() const = 0;
};

class IShape : public ISerializable {
public:
    // TODO: as there not contructor anymore make implementations more useful
    virtual void Draw(TPainter& painter) const = 0;
};

class TShapes {
private:
    std::filesystem::path Filename;

public:
    std::vector<std::unique_ptr<IShape>> Data;

    bool HasFilename() const;
    bool Load(std::string&& filename);
    bool Save(std::string&& filename);
};
