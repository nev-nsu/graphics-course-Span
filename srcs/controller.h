#pragma once

#include "gui.h"
#include "lines.h"

class TController {
private:
    TLines CurrentLines;
    TUserInterface UI;
    bool IsInDrawMode = false;

public:
    TController();

    const std::vector<TLineShape>& GetLinesToDraw() const;
    // Buttons events
    void NewLinesHandler();
    void SaveLinesHandler();
    void LoadLinesHandler();
    void UndoHandler();
    void AboutHandler();

    // Mouse events
    void AddPointHandler(int x, int y);
    void FinishLineHandler();
    void MouseMovementHandler(int x, int y);
};
