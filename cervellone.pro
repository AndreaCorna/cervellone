#-------------------------------------------------
#
# Project created by QtCreator 2013-09-13T10:56:40
#
#-------------------------------------------------

QT       += core gui phonon network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cervellone
TEMPLATE = app


SOURCES += main.cpp\
        cervellone.cpp \
    database_controller.cpp \
    question.cpp \
    hello_window.cpp

HEADERS  += cervellone.h \
    database_controller.h \
    question.h \
    hello_window.h

FORMS    += cervellone.ui \
    hello_window.ui
