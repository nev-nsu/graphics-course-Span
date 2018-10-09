#pragma once

#include <QPainter>
#include <cstdint>

using ui32 = uint32_t;
using TPoint = std::pair<ui32, ui32>;
using TLine = std::pair<TPoint, TPoint>;
using TLineShape = std::vector<TPoint>;

namespace NGraphics {
    void DrawLine(QPainter* plot, const TLine& line);
}
