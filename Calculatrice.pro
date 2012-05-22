#-------------------------------------------------
#
# Project created by QtCreator 2012-05-15T15:23:07
#
#-------------------------------------------------

QT       += core gui

TARGET = Calculatrice
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Calculateur.cpp \
    afficheur.cpp

HEADERS += \
    Calculateur.h \
    Exception.h \
    afficheur.h

FORMS += \
    afficheur.ui
