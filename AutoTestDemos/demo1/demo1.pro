#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T10:54:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo1
TEMPLATE = app
DESTDIR = $$PWD/../../../../Release/Construction/Bin

SOURCES += \
    $$PWD/../../AutoTestEngine/AutoTestEngine.cpp\
    main.cpp\
    widget.cpp

HEADERS  += \
    $$PWD/../../AutoTestEngine/AutoTestEngine.h \
    widget.h

FORMS    += widget.ui
