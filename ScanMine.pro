#-------------------------------------------------
#
# Project created by QtCreator 2016-12-31T10:32:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScanMine
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    thunder.cpp \
    customthunderdialog.cpp

HEADERS  += mainwindow.h \
    thunder.h \
    customthunderdialog.h

FORMS    += mainwindow.ui

RESOURCES += \
    assets.qrc
