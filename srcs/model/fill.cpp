#include "fill.h"

#include <QPoint>
#include <iostream>
#include <queue>
#include <unordered_set>

namespace {
    const constexpr int MaxY = 2048;
    const constexpr int MaxX = 3072;

    static QPoint buffer[MaxX*MaxY]; // really dirty hack
    static bool visited[MaxX][MaxY]; // really dirty hack
}

TFill::TFill(TPoint point)
    : Center(point)
{}

void TFill::Draw(TPainter& painter, QImage& image) const {
    QPixmap tempBuf;
    QRgb replacedColor = image.pixel(Center.first, Center.second);
    auto color = Color? Qt::white : Qt::blue;
    std::queue<TPoint> q;

    for (int i = 0; i < MaxX; i++){
        for (int j = 0; j < MaxY; j++){
            visited[i][j] = false;
        }
    }

    int n = 0;
    auto addPoint = [&](int x, int y) {
        // if (x >= 100 || y >= 100 || x < 0 || y < 0) {
        if (x >= MaxX || y >= MaxY || x < 0 || y < 0) {
            return;
        }

        if (image.pixel(x, y) != replacedColor) {
            return;
        }

        if (visited[x][y]) {
            return;
        }

        visited[x][y] = true;
        q.push({x, y});
        buffer[n++] = QPoint(x, y);
    };

    addPoint((int)Center.first, (int)Center.second);
    while (!q.empty()) {
        auto p = q.front();
        // std::cout << "BFS: " << p.first << " " << p.second << std::endl;
        q.pop();
        addPoint((int)p.first - 1, p.second);
        addPoint(p.first + 1, p.second);
        addPoint(p.first, (int)p.second - 1);
        addPoint(p.first, p.second + 1);
        if (Mode == EM_EIGHT_CONNECTED) {
            addPoint((int)p.first - 1, (int)p.second - 1);
            addPoint(p.first + 1, p.second + 1);
            addPoint(p.first + 1, (int)p.second - 1);
            addPoint((int)p.first - 1, p.second + 1);
        }
    }
    painter.setPen(color);
    painter.drawPoints(buffer, n);
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
