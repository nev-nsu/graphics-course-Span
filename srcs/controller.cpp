#include "controller.h"

TController::TController()
    : UI(*this)
{
    UI.show();
}

const std::vector<TLineShape>& TController::GetLinesToDraw() const {
    return CurrentLines.Lines;
}


void TController::NewLinesHandler() {
    CurrentLines = TLines();
    UI.Update();
}

void TController::SaveLinesHandler() {
    auto filename = CurrentLines.HasFilename()? std::string() : UI.ShowFileChooseDialog(true);
    auto result = CurrentLines.Save(std::move(filename));
    if (!result) {
        UI.ShowErrorMessage("Saving failed");
    }
}

void TController::LoadLinesHandler() {
    auto filename = UI.ShowFileChooseDialog(false);
    auto result = CurrentLines.Load(std::move(filename));
    if (!result) {
        UI.ShowErrorMessage("Opening failed");
    } else {
        UI.Update();
    }
}

void TController::UndoHandler() {
    CurrentLines.Lines.pop_back();
    IsInDrawMode = false;
    UI.Update();
}

void TController::AddPointHandler(int x, int y) {
    if (!IsInDrawMode) {
        UI.Plot->setMouseTracking(true);
        CurrentLines.Lines.emplace_back();
        IsInDrawMode = true;
        CurrentLines.Lines.back().push_back({x, y}); // For floating
    }

    CurrentLines.Lines.back().push_back({x, y});
    UI.Update();
}

void TController::FinishLineHandler() {
    IsInDrawMode = false;
    UI.Plot->setMouseTracking(false);
    CurrentLines.Lines.back().pop_back();
    if (CurrentLines.Lines.back().size() < 2) {
        CurrentLines.Lines.pop_back();
    }
    UI.Update();
}

void TController::MouseMovementHandler(int x, int y) {
    if (IsInDrawMode) {
        CurrentLines.Lines.back().back() = {x, y};
        UI.Update();
    }
}
