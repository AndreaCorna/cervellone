#-------------------------------------------------
#
# Project created by QtCreator 2013-09-13T10:56:40
#
#-------------------------------------------------

QT       += core gui phonon network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cervellone
TEMPLATE = app


SOURCES += main.cpp\
        cervellone.cpp \
    database_controller.cpp

HEADERS  += cervellone.h \
    database_controller.h

FORMS    += cervellone.ui
