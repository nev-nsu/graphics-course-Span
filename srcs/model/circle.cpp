#include "circle.h"

#include <cmath>
#include <sstream>

namespace {
    ui32 GetDistance(TPoint a, TPoint b) {
        auto x = a.first - b.first;
        auto y = a.second - b.second;
        return (ui32) (std::sqrt(x*x+y*y));
    }
}

TCircle::TCircle(TPoint point)
    : Center(point)
{}

void TCircle::Draw(TPainter& painter) const {
    // TODO: real algo
    painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
    painter.drawEllipse(Center.first, Center.second, Radius, Radius);
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
}
