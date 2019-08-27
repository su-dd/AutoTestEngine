#-------------------------------------------------
#
# Project created by QtCreator 2019-06-27T13:49:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# ���user32.lib ��Ҫ�������WinApi
LIBS += user32.lib

TARGET = AutoTestEngine
TEMPLATE = lib

#release�汾������pdb
QMAKE_CXXFLAGS_RELEASE += /Zi /Fd
QMAKE_LFLAGS_RELEASE += /DEBUG

# ʹ��EasyHook��.lib�ļ�
#CONFIG(debug, debug|release){
#    contains(QMAKE_HOST.arch, x86_64) {
#        LIBS += -L$$PWD/3rdparty/easyhook/ \
#             -lEasyHook64
#    } else {
#        LIBS += -L$$PWD/3rdparty/easyhook/ \
#             -lEasyHook32
#    }
#}

#CONFIG(release, debug|release){
#    contains(QMAKE_HOST.arch, x86_64) {
#        LIBS += -L$$PWD/3rdparty/easyhook \
#             -lEasyHook64
#    } else {
#        LIBS += -L$$PWD/3rdparty/easyhook \
#             -lEasyHook32
#    }
#}

DESTDIR = $$PWD/../../../Release/Construction/Bin

#---------Qt�����ؼ�������--------
AUTOPLUGINS += QT_BASIC_CCONTROL

#---------GLD�ؼ�������--------
AUTOPLUGINS += GLD_CONTROL

#---------QRibbon�ؼ�������--------
AUTOPLUGINS += QRIBBON_CONTROL

# MinHook����
include($$PWD/3rdparty/MinHook/MinHook.pri)
include($(GLDRS)/Glodon/shared/QtitanRibbon.pri)
include($(GLDRS)/Glodon/shared/GLDStaticLib.pri)
include($(GLDRS)/Glodon/shared/GSPStaticLib.pri)

INCLUDEPATH += \
    $$PWD/src \
    $$PWD/src/View \
    $$PWD/plugins \
    $$PWD/3rdparty/easyhook

SOURCES += \
    src/main.cpp\
    src/AutoTestApp.cpp \
    src/AutoTestException.cpp \
    src/AutoTestCommonUtil.cpp \
    src/HookManager.cpp \
    src/AdapterManager.cpp \
    src/CaseManager.cpp \
    src/ControlManage.cpp \
# ����
    src/View/MainView.cpp \
# ���
    plugins/QtCase.cpp \
    plugins/QtAdapter.cpp


HEADERS  += \
    src/ICase.h \
    src/IAdapter.h \
    src/AutoTestSignalsIndexConst.h \
    src/AutoTestApp.h \
    src/AutoTestException.h \
    src/AutoTestCommonUtil.h \
    src/HookManager.h \
    src/AdapterManager.h \
    src/CaseManager.h \
    src/ControlManage.h \
# ����
    src/View/MainView.h \
# ���
    plugins/Plugins.h \
    plugins/QtCase.h \
    plugins/QtAdapter.h

##############################������Qt�����ؼ��������ļ�################################
contains(AUTOPLUGINS, QT_BASIC_CCONTROL){
# include
INCLUDEPATH += $$PWD/plugins/QtBasicControls
# QButtonAdapter
HEADERS  += $$PWD/plugins/QtBasicControls/QButtonAdapter.h
SOURCES  += $$PWD/plugins/QtBasicControls/QButtonAdapter.cpp
HEADERS  += $$PWD/plugins/QtBasicControls/QButtonCase.h
SOURCES  += $$PWD/plugins/QtBasicControls/QButtonCase.cpp
# QComboBoxAdpter
HEADERS  += $$PWD/plugins/QtBasicControls/QComboBoxAdpter.h
SOURCES  += $$PWD/plugins/QtBasicControls/QComboBoxAdpter.cpp
HEADERS  += $$PWD/plugins/QtBasicControls/QComboBoxCase.h
SOURCES  += $$PWD/plugins/QtBasicControls/QComboBoxCase.cpp
# QEditAdapter
HEADERS  += $$PWD/plugins/QtBasicControls/QEditAdapter.h
SOURCES  += $$PWD/plugins/QtBasicControls/QEditAdapter.cpp
HEADERS  += $$PWD/plugins/QtBasicControls/QEditCase.h
SOURCES  += $$PWD/plugins/QtBasicControls/QEditCase.cpp
# QTabBarAdapter
HEADERS  += $$PWD/plugins/QtBasicControls/QTabBarAdapter.h
SOURCES  += $$PWD/plugins/QtBasicControls/QTabBarAdapter.cpp
HEADERS  += $$PWD/plugins/QtBasicControls/QTabBarCase.h
SOURCES  += $$PWD/plugins/QtBasicControls/QTabBarCase.cpp
# QMenuAdapter
HEADERS  += $$PWD/plugins/QtBasicControls/QMenuAdapter.h
SOURCES  += $$PWD/plugins/QtBasicControls/QMenuAdapter.cpp
HEADERS  += $$PWD/plugins/QtBasicControls/QMenuCase.h
SOURCES  += $$PWD/plugins/QtBasicControls/QMenuCase.cpp
}


##############################������GLD�����ؼ��������ļ�################################
contains(AUTOPLUGINS, GLD_CONTROL){
# include
INCLUDEPATH += $$PWD/plugins/GLDControls
## GLDBaseMenuAdapter
#HEADERS  += $$PWD/plugins/GLDControls/GLDBaseMenuAdapter.h
#SOURCES  += $$PWD/plugins/GLDControls/GLDBaseMenuAdapter.cpp
#HEADERS  += $$PWD/plugins/GLDControls/GLDBaseMenuCase.h
#SOURCES  += $$PWD/plugins/GLDControls/GLDBaseMenuCase.cpp
}


##############################������QRibbon�����ؼ��������ļ�################################
contains(AUTOPLUGINS, QRIBBON_CONTROL){
# include
INCLUDEPATH += $$PWD/plugins/QRibbonControls

# QRibbonBarAdapter
HEADERS  += $$PWD/plugins/QRibbonControls/QRibbonBarAdapter.h
SOURCES  += $$PWD/plugins/QRibbonControls/QRibbonBarAdapter.cpp
HEADERS  += $$PWD/plugins/QRibbonControls/QRibbonBarCase.h
SOURCES  += $$PWD/plugins/QRibbonControls/QRibbonBarCase.cpp
# QRibbonGroup
HEADERS  += $$PWD/plugins/QRibbonControls/QRibbonGroupAdapter.h
SOURCES  += $$PWD/plugins/QRibbonControls/QRibbonGroupAdapter.cpp
HEADERS  += $$PWD/plugins/QRibbonControls/QRibbonGroupCase.h
SOURCES  += $$PWD/plugins/QRibbonControls/QRibbonGroupCase.cpp
# QRibbonButton
HEADERS  += $$PWD/plugins/QRibbonControls/QRibbonButtonAdapter.h
SOURCES  += $$PWD/plugins/QRibbonControls/QRibbonButtonAdapter.cpp
HEADERS  += $$PWD/plugins/QRibbonControls/QRibbonButtonCase.h
SOURCES  += $$PWD/plugins/QRibbonControls/QRibbonButtonCase.cpp
}
