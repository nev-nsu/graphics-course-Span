#include "fill.h"

TFill::TFill(TPoint point)
    : Center(point)
{}


void TFill::Draw(TPainter& painter) const {
    // TODO: do sth (like span algo)
}

std::unique_ptr<ISerializable> TFill::Read(const std::string& data) {
    try {
        std::istringstream input(data);

        // 1. Check signature
        {
            std::string sign;
            input >> sign;
            if (sign != Signature) {
                return {};
            }
        }

        // 2. Read center
        TPoint center;
        input >> center.first >> center.second;
        TFill* newFillPtr = new TFill(center);
        TFill& newFill = *newFillPtr;

        // 3. Read mode and color
        int color, mode;
        input >> color >> mode;
        newFill.Color = static_cast<EColor>(color);
        newFill.Mode = static_cast<EMode>(mode);

        return std::unique_ptr<ISerializable>(newFillPtr);
    } catch (...) {
        return {};
    }
}

std::string TFill::Write() const {
    std::ostringstream output;
    output << Signature << std::endl;
    output << Center.first << ' ' << Center.second << ' '
           << Color << ' ' << Mode << std::endl;
    return output.str();
}

void TFill::SetMode(EMode mode) {
    Mode = mode;
}

void TFill::SetColor(EColor color) {
    Color = color;
}
