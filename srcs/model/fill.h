#pragma once

#include "shape.h"


class TFill : public IShape {
public:
    enum EMode {
        EM_FOUR_CONNECTED = 4,
        EM_EIGHT_CONNECTED = 8
    };

    enum EColor {
        EC_DARK = 0,
        EC_LIGHT = 1,
    };

private:
    TPoint Center;
    EMode Mode = EM_FOUR_CONNECTED;
    EColor Color = EC_DARK;

public:
    static constexpr const char* Signature = "FILL";

    TFill(TPoint point);

    virtual void Draw(TPainter& painter, QImage& image) const override;

    static std::unique_ptr<ISerializable> Read(const std::string& data);
    virtual std::string Write() const override;

    void SetMode(EMode mode);
    void SetColor(EColor color);

    virtual ~TFill() override = default;
};
