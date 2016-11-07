#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T23:18:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Laboratorio5
TEMPLATE = app


SOURCES += main.cpp\
        fisica.cpp \
    mainw.cpp \
    intro.cpp

HEADERS  +=\
            fisica.h \
    mainw.h \
    intro.h

FORMS    += \
    mainw.ui \
    intro.ui

RESOURCES += \
    resources.qrc
