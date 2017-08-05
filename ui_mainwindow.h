/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStartGame;
    QAction *actionExitGame;
    QAction *actionLowLevel;
    QAction *actionMidLevel;
    QAction *actionHighLevel;
    QAction *actionCustomLevel;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblFlag;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblTime;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuStartAction;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(642, 354);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        actionStartGame = new QAction(MainWindow);
        actionStartGame->setObjectName(QStringLiteral("actionStartGame"));
        actionExitGame = new QAction(MainWindow);
        actionExitGame->setObjectName(QStringLiteral("actionExitGame"));
        actionLowLevel = new QAction(MainWindow);
        actionLowLevel->setObjectName(QStringLiteral("actionLowLevel"));
        actionMidLevel = new QAction(MainWindow);
        actionMidLevel->setObjectName(QStringLiteral("actionMidLevel"));
        actionHighLevel = new QAction(MainWindow);
        actionHighLevel->setObjectName(QStringLiteral("actionHighLevel"));
        actionCustomLevel = new QAction(MainWindow);
        actionCustomLevel->setObjectName(QStringLiteral("actionCustomLevel"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblFlag = new QLabel(centralWidget);
        lblFlag->setObjectName(QStringLiteral("lblFlag"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lblFlag->setFont(font);
        lblFlag->setAutoFillBackground(false);
        lblFlag->setWordWrap(false);

        horizontalLayout->addWidget(lblFlag);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lblTime = new QLabel(centralWidget);
        lblTime->setObjectName(QStringLiteral("lblTime"));
        lblTime->setFont(font);
        lblTime->setAutoFillBackground(false);
        lblTime->setWordWrap(false);

        horizontalLayout->addWidget(lblTime);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 642, 23));
        menuStartAction = new QMenu(menuBar);
        menuStartAction->setObjectName(QStringLiteral("menuStartAction"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuStartAction->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuStartAction->addAction(actionStartGame);
        menuStartAction->addAction(actionExitGame);
        menu->addAction(actionLowLevel);
        menu->addAction(actionMidLevel);
        menu->addAction(actionHighLevel);
        menu->addSeparator();
        menu->addAction(actionCustomLevel);
        menu_2->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\211\253\351\233\267\344\270\223\344\270\232\347\211\210", Q_NULLPTR));
        actionStartGame->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionStartGame->setToolTip(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionExitGame->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\346\270\270\346\210\217", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExitGame->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLowLevel->setText(QApplication::translate("MainWindow", "\345\210\235\347\272\247", Q_NULLPTR));
        actionMidLevel->setText(QApplication::translate("MainWindow", "\344\270\255\347\272\247", Q_NULLPTR));
        actionHighLevel->setText(QApplication::translate("MainWindow", "\351\253\230\347\272\247", Q_NULLPTR));
        actionCustomLevel->setText(QApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "\346\211\253\351\233\267\344\270\223\344\270\232\347\211\210", Q_NULLPTR));
        lblFlag->setText(QApplication::translate("MainWindow", "\346\240\207\350\256\260: 2", Q_NULLPTR));
        lblTime->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264: 23s", Q_NULLPTR));
        menuStartAction->setTitle(QApplication::translate("MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\347\255\211\347\272\247", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
