#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T18:22:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Laboratorio6
TEMPLATE = app


SOURCES += main.cpp\
        mainw.cpp \
    fisica.cpp \
    intro.cpp \
    qvista.cpp \
    objetos.cpp \
    pend.cpp \
    refresh.cpp

HEADERS  += mainw.h \
    fisica.h \
    intro.h \
    qvista.h \
    objetos.h \
    pend.h \
    refresh.h

FORMS    += mainw.ui \
    intro.ui

RESOURCES += \
    resources.qrc
