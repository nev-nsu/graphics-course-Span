#include "controller.h"

#include "model/polygon.h"
#include "model/circle.h"
#include "model/fill.h"

#include <iostream>

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
    State.IsInDrawMode = false;
    UI.Update();
}

void TController::AddPointHandler(int x, int y, bool circleSpecific) {
    std::cout << "AddPointHandler " << x << " " << y << " " << circleSpecific << std::endl;
    if (!State.IsInDrawMode) {
        if (UI.ui.toolLine->isChecked()) {
            State.LastShape = EShapeType::EST_Lines;
        } else if (UI.ui.toolCircle->isChecked()) {
            State.LastShape = EShapeType::EST_Circle;
        } else if (UI.ui.toolFill->isChecked()) {
            State.LastShape = EShapeType::EST_Fill;
        }
        switch (State.LastShape) {
            case EShapeType::EST_Lines:
                if (circleSpecific) {
                    return;
                }
                UI.Plot->setMouseTracking(true);
                CurrentShapes.Data.emplace_back(new TPolygon(TPoint({x, y})));
                State.IsInDrawMode = true;
                break;
            case EShapeType::EST_Circle:
                CurrentShapes.Data.emplace_back(new TCircle({x, y}));
                State.IsInDrawMode = true;
                break;
            case EShapeType::EST_Fill:
                // TODO: mine params
                if (circleSpecific) {
                    return;
                }
                CurrentShapes.Data.emplace_back(new TFill({x, y}));
        }
    } else {
        switch (State.LastShape) {
            case EShapeType::EST_Lines:
                if (circleSpecific) {
                    return;
                }
                (dynamic_cast<TPolygon*>(CurrentShapes.Data.back().get()))->FixKeyPoint();
                break;
            case EShapeType::EST_Circle:
                State.IsInDrawMode = false;
            // Can't be EShapeType::EST_Fill here
        }
    }

    UI.Update();
}

void TController::FinishDrawHandler() {
    std::cout << "FinishDrawHandler " << std::endl;

    if (!State.IsInDrawMode || State.LastShape != EShapeType::EST_Lines) {
        return;
    }
    State.IsInDrawMode = false;
    UI.Plot->setMouseTracking(false);
    auto& current = *(dynamic_cast<TPolygon*>(CurrentShapes.Data.back().get()));
    current.FinishConstruction();
    UI.Update();
}

void TController::MouseMovementHandler(int x, int y) {
    std::cout << "MouseMovementHandler " << x << " " << y << std::endl;
    if (State.IsInDrawMode) {
        switch (State.LastShape) {
            case EShapeType::EST_Lines:
                (dynamic_cast<TPolygon*>(CurrentShapes.Data.back().get()))->MoveLastPoint({x, y});
                break;
            case EShapeType::EST_Circle:
                (dynamic_cast<TCircle*>(CurrentShapes.Data.back().get()))->MoveLastPoint({x, y});
            // Can't be EShapeType::EST_Fill here
        }
        UI.Update();
    }
}
