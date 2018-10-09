#pragma once

#include "interface/gui.h"
#include "model/shape.h"

class TController {
private:
    TShapes CurrentShapes;
    TUserInterface UI;
    bool IsInDrawMode = false;

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
    void AddPointHandler(int x, int y);
    void FinishLineHandler();
    void MouseMovementHandler(int x, int y);
};
