#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T09:53:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo2
TEMPLATE = app
DESTDIR = $$PWD/../../../../Release/Construction/Bin

SOURCES += $$PWD/../../AutoTestEngine/AutoTestEngine.cpp
SOURCES +=main.cpp
SOURCES +=mainwindow.cpp

HEADERS  += $$PWD/../../AutoTestEngine/AutoTestEngine.h
HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
