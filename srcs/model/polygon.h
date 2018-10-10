#pragma once

#include "shape.h"

class TPolygon : public IShape {
public:
    enum EWidth {
        EW_THIN = 1,
        EW_NORMAL = 2,
        EW_BOLD = 3
    };

private:
    std::vector<TPoint> KeyPoints;
    EWidth Width = EW_NORMAL;

public:
    static constexpr const char* Signature = "POLYGON";

    TPolygon(TPoint point);
    TPolygon() = default;

    virtual void Draw(TPainter& painter, QImage& image) const override;

    static std::unique_ptr<ISerializable> Read(const std::string& data);
    virtual std::string Write() const override;

    void SetWidth(EWidth width);
    void MoveLastPoint(TPoint point);
    void FixKeyPoint();
    void FinishConstruction();

    virtual ~TPolygon() override = default;
};
