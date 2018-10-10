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
    QImage image(3072, 2048, QImage::Format_ARGB32);
    {
        QPainter painter;
        painter.begin(&image);
        painter.fillRect(0, 0, 3072, 2048, Qt::white);
        painter.end();
        const auto& shapes = Controller.GetShapesToDraw();
        for (const auto& shape : shapes) {
            painter.begin(&image);
            shape->Draw(painter, image);
            painter.end();
        }
    }
    QPainter painterCopy(this);
    painterCopy.fillRect(0, 0, width(), height(), Qt::white);
    painterCopy.drawImage(0, 0, image);
}

void QPaintWidget::mousePressEvent (QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        MouseLeftClick(event->x(), event->y(), false);
    } else if (event->button() == Qt::RightButton) {
        MouseRightClick();
    }
}

void QPaintWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        MouseLeftClick(event->x(), event->y(), true);
    }
}

void QPaintWidget::mouseMoveEvent (QMouseEvent* event) {
    MouseMovement(event->x(), event->y());
}

TUserInterface::TUserInterface (TController& controller) {
    ui.setupUi(this);

    Plot = new QPaintWidget(this, controller);
    Plot->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
    Plot->setGeometry(QRect(0, 0, 3072, 2048));
    Plot->setMinimumWidth(3072);
    Plot->setMaximumWidth(3072);
    Plot->setMinimumHeight(2048);
    Plot->setMaximumHeight(2048);
    // QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // sizePolicy2.setHorizontalStretch(0);
    // sizePolicy2.setVerticalStretch(0);
    // sizePolicy2.setHeightForWidth(Plot->sizePolicy().hasHeightForWidth());
    // Plot->setSizePolicy(sizePolicy2);
    ui.scrollArea->setWidget(Plot);

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
    connect(Plot, &QPaintWidget::MouseLeftClick, [&](int x, int y, bool released) {
        controller.AddPointHandler(x, y, released);
    });
    connect(Plot, &QPaintWidget::MouseRightClick, [&]() {
        controller.FinishDrawHandler();
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
