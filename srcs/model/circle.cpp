#include "circle.h"

#include <cmath>
#include <sstream>
#include <iostream>

namespace {
    ui32 GetDistance(TPoint a, TPoint b) {
        auto x = (int) a.first - (int) b.first;
        auto y = (int) a.second - (int) b.second;
        return (ui32) (std::hypot(x, y));
    }
}

TCircle::TCircle(TPoint point)
    : Center(point)
{}

void TCircle::Draw(TPainter& painter) const {
    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
    std::cout << "DrawCircle: " << Center.first << " " << Center.second << " " << Radius << std::endl;

    int x0 = Center.first;
    int y0 = Center.second;
    int r = Radius;

    int x = r - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - 2*r;

    while (x >= y) {
        painter.drawPoint(x0 + x, y0 + y);
        painter.drawPoint(x0 + y, y0 + x);
        painter.drawPoint(x0 - y, y0 + x);
        painter.drawPoint(x0 - x, y0 + y);
        painter.drawPoint(x0 - x, y0 - y);
        painter.drawPoint(x0 - y, y0 - x);
        painter.drawPoint(x0 + y, y0 - x);
        painter.drawPoint(x0 + x, y0 - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        // } else if (err > 0) {
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - 2*r;
        }
    }
}

std::unique_ptr<ISerializable> TCircle::Read(const std::string& data) {
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
        TCircle* newCirclePtr = new TCircle(center);
        TCircle& newCircle = *newCirclePtr;

        // 3. Read radius
        input >> newCircle.Radius;

        return std::unique_ptr<ISerializable>(newCirclePtr);
    } catch (...) {
        return {};
    }
}

std::string TCircle::Write() const {
    std::ostringstream output;
    output << Signature << std::endl;
    output << Center.first << ' ' << Center.second << ' ' << Radius << std::endl;
    return output.str();
}

void TCircle::MoveLastPoint(TPoint point) {
    Radius = GetDistance(Center, point);
    std::cout << "Radius: " << Radius << std::endl;
}
