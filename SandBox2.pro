

QT  += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SomeLib
TEMPLATE = lib
CONFIG += staticlib

#QT  += core gui widgets

#CONFIG += c++11

#TARGET = SandBox2
#CONFIG += console
##CONFIG -= app_bundle

#TEMPLATE = app

SOURCES += main.cpp \
    congratulator.cpp \
    scorehandler.cpp \
    scoremanager.cpp \
    congratulatorui.cpp \
    gameengine.cpp \
    puzzleform.cpp \
    puzzlemanager.cpp \
    scorekeeper.cpp

HEADERS += \
    congratulator.h \
    scorehandler.h \
    scoremanager.h \
    congratulatorui.h \
    gameengine.h \
    puzzleform.h \
    puzzlemanager.h \
    scorekeeper.h

FORMS += \
    congratswindow.ui \
    puzzleform.ui
