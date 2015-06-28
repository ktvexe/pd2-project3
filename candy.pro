#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T11:24:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    result.cpp \
    board.cpp

HEADERS  += mainwindow.h \
    game.h \
    result.h \
    board.h

FORMS    += mainwindow.ui \
    game.ui \
    result.ui

RESOURCES += \
    pic.qrc \
    map.qrc \
    pic2.qrc
