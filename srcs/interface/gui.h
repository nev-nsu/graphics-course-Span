#pragma once

#include "model/shape.h"
#include "ui_designer.h"

#include <set>

class TController;
class QPaintEvent;

class QPaintWidget : public QWidget {
    Q_OBJECT
private:
    TController& Controller;

public:
    QPaintWidget(QWidget* parent, TController& controller);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent (QMouseEvent* event) override;
    void mouseMoveEvent (QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void MouseLeftClick(int x, int y, bool released);
    void MouseRightClick();
    void MouseMovement(int x, int y);
};

class TUserInterface : public QMainWindow {
    Q_OBJECT
public:
    Ui::MainWindow ui;
    QPaintWidget* Plot;

public:
    TUserInterface (TController& controller);
    ~TUserInterface();

    void Update() const;
    void ShowErrorMessage(const std::string& message) const;
    void ShowAboutMessage() const;

    std::string ShowFileChooseDialog(bool toSave) const;
};
