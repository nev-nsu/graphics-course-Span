#include "gui.h"

#include <controller.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <string>

QPaintWidget::QPaintWidget(QWidget* parent, TController& controller)
    : QWidget(parent)
    , Controller(controller)
{}

void QPaintWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::white);
    const auto& shapes = Controller.GetShapesToDraw();
    for (const auto& shape : shapes) {
        shape->Draw(painter);
    }
}

void QPaintWidget::mousePressEvent (QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        MouseLeftClick(event->x(), event->y());
    } else if (event->button() == Qt::RightButton) {
        MouseRightClick();
    }
}

void QPaintWidget::mouseMoveEvent (QMouseEvent* event) {
    MouseMovement(event->x(), event->y());
}

TUserInterface::TUserInterface (TController& controller) {
    ui.setupUi(this);

    Plot = new QPaintWidget(this, controller);
    ui.gridLayout->addWidget(Plot);

    connect(ui.actionNew, &QAction::triggered, [&](bool) {
        controller.NewShapesHandler();
    });
    connect(ui.actionSave, &QAction::triggered, [&](bool) {
        controller.SaveShapesHandler();
    });
    connect(ui.actionOpen, &QAction::triggered, [&](bool) {
        controller.LoadShapesHandler();
    });
    connect(ui.actionAbout_LineEditor, &QAction::triggered, [&](bool) {
        ShowAboutMessage();
    });
    connect(ui.actionUndo, &QAction::triggered, [&](bool) {
        controller.UndoHandler();
    });
    connect(Plot, &QPaintWidget::MouseLeftClick, [&](int x, int y) {
        controller.AddPointHandler(x, y);
    });
    connect(Plot, &QPaintWidget::MouseRightClick, [&]() {
        controller.FinishLineHandler();
    });
    connect(Plot, &QPaintWidget::MouseMovement, [&](int x, int y) {
        controller.MouseMovementHandler(x, y);
    });
}

TUserInterface::~TUserInterface() {
    Plot->deleteLater();
}

void TUserInterface::Update() const {
    Plot->update();
}

void TUserInterface::ShowErrorMessage(const std::string& message) const {
    QMessageBox::warning(0, "Error", QString::fromStdString(message));
}

void TUserInterface::ShowAboutMessage() const {
    QMessageBox::information(nullptr, "About LineEditor",
        #include "about.h"
    );
}

std::string TUserInterface::ShowFileChooseDialog(bool toSave) const {
    QString filename = toSave? QFileDialog::getSaveFileName() : QFileDialog::getOpenFileName();
    return {filename.toUtf8().constData()};
}
