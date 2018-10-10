/********************************************************************************
** Form generated from reading UI file 'designerUCkaJE.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERUCKAJE_H
#define DESIGNERUCKAJE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionUndo;
    QAction *actionAbout_LineEditor;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QRadioButton *size1;
    QRadioButton *size2;
    QRadioButton *size3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *toolCircle;
    QRadioButton *toolLine;
    QRadioButton *toolFill;
    QCheckBox *mode8;
    QCheckBox *colorDark;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(808, 624);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/list-add.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/document-open.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/document-save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon2);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/edit-undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon3);
        actionAbout_LineEditor = new QAction(MainWindow);
        actionAbout_LineEditor->setObjectName(QStringLiteral("actionAbout_LineEditor"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/help-faq.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAbout_LineEditor->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        size1 = new QRadioButton(groupBox_2);
        size1->setObjectName(QStringLiteral("size1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(size1->sizePolicy().hasHeightForWidth());
        size1->setSizePolicy(sizePolicy1);
        size1->setChecked(true);

        gridLayout_3->addWidget(size1, 1, 0, 1, 1);

        size2 = new QRadioButton(groupBox_2);
        size2->setObjectName(QStringLiteral("size2"));
        sizePolicy.setHeightForWidth(size2->sizePolicy().hasHeightForWidth());
        size2->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(size2, 1, 1, 1, 1);

        size3 = new QRadioButton(groupBox_2);
        size3->setObjectName(QStringLiteral("size3"));
        sizePolicy.setHeightForWidth(size3->sizePolicy().hasHeightForWidth());
        size3->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(size3, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        toolCircle = new QRadioButton(groupBox);
        toolCircle->setObjectName(QStringLiteral("toolCircle"));
        sizePolicy.setHeightForWidth(toolCircle->sizePolicy().hasHeightForWidth());
        toolCircle->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(toolCircle, 0, 2, 1, 1);

        toolLine = new QRadioButton(groupBox);
        toolLine->setObjectName(QStringLiteral("toolLine"));
        sizePolicy.setHeightForWidth(toolLine->sizePolicy().hasHeightForWidth());
        toolLine->setSizePolicy(sizePolicy);
        toolLine->setChecked(true);

        gridLayout_2->addWidget(toolLine, 0, 1, 1, 1);

        toolFill = new QRadioButton(groupBox);
        toolFill->setObjectName(QStringLiteral("toolFill"));
        sizePolicy.setHeightForWidth(toolFill->sizePolicy().hasHeightForWidth());
        toolFill->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(toolFill, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        mode8 = new QCheckBox(centralwidget);
        mode8->setObjectName(QStringLiteral("mode8"));
        sizePolicy.setHeightForWidth(mode8->sizePolicy().hasHeightForWidth());
        mode8->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(mode8);

        colorDark = new QCheckBox(centralwidget);
        colorDark->setObjectName(QStringLiteral("colorDark"));
        sizePolicy.setHeightForWidth(colorDark->sizePolicy().hasHeightForWidth());
        colorDark->setSizePolicy(sizePolicy);
        colorDark->setChecked(true);
        colorDark->setTristate(false);

        horizontalLayout->addWidget(colorDark);


        verticalLayout_3->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        // scrollAreaWidgetContents = new QWidget();
        // scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        // scrollAreaWidgetContents->setGeometry(QRect(0, 0, 790, 486));
        // QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        // sizePolicy2.setHorizontalStretch(0);
        // sizePolicy2.setVerticalStretch(0);
        // sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        // scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        // scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 808, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuEdit->addAction(actionUndo);
        menuHelp->addAction(actionAbout_LineEditor);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout_LineEditor);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Span", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Create new document", nullptr));
#endif // QT_NO_TOOLTIP
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open existing document", nullptr));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save current lines info a file", nullptr));
#endif // QT_NO_TOOLTIP
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "Remove last line", nullptr));
#endif // QT_NO_TOOLTIP
        actionAbout_LineEditor->setText(QApplication::translate("MainWindow", "About LineEditor", nullptr));
        groupBox_2->setTitle(QString());
        size1->setText(QApplication::translate("MainWindow", "Size: 1", nullptr));
        size2->setText(QApplication::translate("MainWindow", "Size: 2", nullptr));
        size3->setText(QApplication::translate("MainWindow", "Size: 3", nullptr));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        toolCircle->setToolTip(QApplication::translate("MainWindow", "Circle", nullptr));
#endif // QT_NO_TOOLTIP
        toolCircle->setText(QApplication::translate("MainWindow", "Circle", nullptr));
#ifndef QT_NO_TOOLTIP
        toolLine->setToolTip(QApplication::translate("MainWindow", "Closed multiline", nullptr));
#endif // QT_NO_TOOLTIP
        toolLine->setText(QApplication::translate("MainWindow", "Polygon", nullptr));
#ifndef QT_NO_TOOLTIP
        toolFill->setToolTip(QApplication::translate("MainWindow", "Fill an area with some color", nullptr));
#endif // QT_NO_TOOLTIP
        toolFill->setText(QApplication::translate("MainWindow", "Fill", nullptr));
#ifndef QT_NO_TOOLTIP
        mode8->setToolTip(QApplication::translate("MainWindow", "Use 8-directions algo", nullptr));
#endif // QT_NO_TOOLTIP
        mode8->setText(QApplication::translate("MainWindow", "Use strict fill", nullptr));
#ifndef QT_NO_TOOLTIP
        colorDark->setToolTip(QApplication::translate("MainWindow", "Dark/light fill", nullptr));
#endif // QT_NO_TOOLTIP
        colorDark->setText(QApplication::translate("MainWindow", "Use dark fill", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERUCKAJE_H
