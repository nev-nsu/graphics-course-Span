#pragma once

#include "shape.h"

class TCircle : public IShape {
private:
    TPoint Center;
    ui32 Radius = 0;

public:
    static constexpr const char* Signature = "CIRCLE";

    TCircle(TPoint point);

    virtual void Draw(TPainter& painter) const override;

    static std::unique_ptr<ISerializable> Read(const std::string& data);
    virtual std::string Write() const override;

    void MoveLastPoint(TPoint point);
};
