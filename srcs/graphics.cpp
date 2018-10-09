#include "graphics.h"

#include <cmath>

void NGraphics::DrawLine(QPainter* plot, const TLine& line) {
    int x1 = line.first.first, y1 = line.first.second;
    int x2 = line.second.first, y2 = line.second.second;

    // Bresenham's line algorithm
    const bool reversed = (abs(y2 - y1) > abs(x2 - x1));
    if (reversed) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const auto dx = x2 - x1;
    const auto dy = abs(y2 - y1);

    auto error = dx;
    const auto ystep = (y1 < y2) ? 1 : -1;
    auto y = y1;

    for (auto x = x1; x < x2; x++) {
        plot->drawPoint(reversed? y : x, reversed? x : y);
        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}
