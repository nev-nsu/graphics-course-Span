#pragma once

#include "interface/gui.h"
#include "model/shape.h"

class TController {
private:
    enum class EShapeType {
        EST_Lines,
        EST_Circle,
        EST_Fill
    };

    struct {
        bool IsInDrawMode = false;
        EShapeType LastShape = EShapeType::EST_Lines;
    } State;

    TShapes CurrentShapes;
    TUserInterface UI;

public:
    TController();

    const std::vector<std::unique_ptr<IShape>>& GetShapesToDraw() const;
    // Buttons events
    void NewShapesHandler();
    void SaveShapesHandler();
    void LoadShapesHandler();
    void UndoHandler();
    void AboutHandler();

    // Mouse events
    void AddPointHandler(int x, int y, bool circleSpecific);
    void FinishDrawHandler();
    void MouseMovementHandler(int x, int y);
};
