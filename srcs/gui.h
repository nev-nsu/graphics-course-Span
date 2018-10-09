#pragma once

#include "lines.h"
#include "ui_designer.h"

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

signals:
    void MouseLeftClick(int x, int y);
    void MouseRightClick();
    void MouseMovement(int x, int y);
};

class TUserInterface : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow ui;

public:
    QPaintWidget* Plot;

public:
    TUserInterface (TController& controller);
    ~TUserInterface();

    void Update() const;
    void ShowErrorMessage(const std::string& message) const;
    void ShowAboutMessage() const;

    std::string ShowFileChooseDialog(bool toSave) const;
};
