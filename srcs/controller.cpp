#include "controller.h"

#include "model/polygon.cpp"

TController::TController()
    : UI(*this)
{
    UI.show();
}

const std::vector<std::unique_ptr<IShape>>& TController::GetShapesToDraw() const {
    return CurrentShapes.Data;
}


void TController::NewShapesHandler() {
    CurrentShapes = TShapes();
    UI.Update();
}

void TController::SaveShapesHandler() {
    auto filename = CurrentShapes.HasFilename()? std::string() : UI.ShowFileChooseDialog(true);
    auto result = CurrentShapes.Save(std::move(filename));
    if (!result) {
        UI.ShowErrorMessage("Saving failed");
    }
}

void TController::LoadShapesHandler() {
    auto filename = UI.ShowFileChooseDialog(false);
    auto result = CurrentShapes.Load(std::move(filename));
    if (!result) {
        UI.ShowErrorMessage("Opening failed");
    } else {
        UI.Update();
    }
}

void TController::UndoHandler() {
    CurrentShapes.Data.pop_back();
    IsInDrawMode = false;
    UI.Update();
}

void TController::AddPointHandler(int x, int y) {
    if (!IsInDrawMode) {
        UI.Plot->setMouseTracking(true);
        CurrentShapes.Data.emplace_back(new TPolygon({x, y}));
        IsInDrawMode = true;
    } else {
        auto& current = *(dynamic_cast<TPolygon*>(CurrentShapes.Data.back().get()));
        current.FixKeyPoint();
    }

    UI.Update();
}

void TController::FinishLineHandler() {
    IsInDrawMode = false;
    UI.Plot->setMouseTracking(false);
    auto& current = *(dynamic_cast<TPolygon*>(CurrentShapes.Data.back().get()));
    current.FinishConstruction();
    UI.Update();
}

void TController::MouseMovementHandler(int x, int y) {
    if (IsInDrawMode) {
        auto& current = *(dynamic_cast<TPolygon*>(CurrentShapes.Data.back().get()));
        current.MoveLastPoint({x, y});
        UI.Update();
    }
}
