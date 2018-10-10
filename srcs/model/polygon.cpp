#include "polygon.h"

#include <iostream>

TPolygon::TPolygon(TPoint point)
    : KeyPoints({point, point})
{}


void TPolygon::Draw(TPainter& painter, QImage& image) const {
    painter.setPen(QPen(Qt::blue, (int) Width, Qt::SolidLine));
    for (auto i = 1; i < KeyPoints.size(); i++) {
        const auto& prevPoint = KeyPoints[i - 1];
        const auto& curPoint = KeyPoints[i];
        painter.drawLine(prevPoint.first, prevPoint.second, curPoint.first, curPoint.second);
    }
}

std::unique_ptr<ISerializable> TPolygon::Read(const std::string& data) {
    try {
        std::istringstream input(data);
        std::cout << "Try to read as TPolygon" << std::endl;

        // 1. Check signature
        {
            std::string sign;
            input >> sign;
            if (sign != Signature) {
                return {};
            }
        }

        // 2. Read count of lines and lines width
        int linesCount, width;
        input >> linesCount >> width;
        if (linesCount < 2) {
            return {};
        }
        TPolygon* newPolPtr = new TPolygon;
        TPolygon& newPol = *newPolPtr;
        newPol.Width = static_cast<EWidth>(width);

        // 3. Read lines
        for (; linesCount > 0; linesCount--) {
            TPoint point;
            input >> point.first >> point.second;
            newPol.KeyPoints.push_back(point);
        }
        newPol.KeyPoints.push_back(newPol.KeyPoints.front());
        return std::unique_ptr<ISerializable>(newPolPtr);
    } catch (...) {
        return {};
    }
}

std::string TPolygon::Write() const {
    std::ostringstream output;
    output << Signature << std::endl;
    output << KeyPoints.size() - 1 << ' ' << Width << std::endl;
    for (auto i = 0; i < KeyPoints.size() - 1; i++) {
        const auto& point = KeyPoints[i];
        output << point.first << ' ' << point.second << std::endl;
    }
    return output.str();
}

void TPolygon::SetWidth(EWidth width) {
    Width = width;
}

void TPolygon::MoveLastPoint(TPoint point) {
    KeyPoints.back() = point;
}

void TPolygon::FixKeyPoint() {
    KeyPoints.push_back(KeyPoints.back());
}

void TPolygon::FinishConstruction() {
    MoveLastPoint(KeyPoints.front());
}
