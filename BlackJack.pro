#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T17:04:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++14

TARGET = CardGames
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    base/card.cpp \
    base/deck.cpp \
    hand.cpp \
    blackjackhandevaluator.cpp

HEADERS  += mainwindow.h \
    base/card.h \
    base/deck.h \
    hand.h \
    blackjackhandevaluator.h

FORMS    += mainwindow.ui
