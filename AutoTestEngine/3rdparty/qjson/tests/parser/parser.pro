SOURCES = testparser.cpp
CONFIG  += qtestlib
CONFIG += link_prl
DEFINES += QMAKE_BUILD

win32 {
  LIBS += -L../../lib -qjson0
} macx {
  QMAKE_LFLAGS += -F../../lib
  LIBS += -framework qjson
} unix:!macx {
  LIBS += -L../../lib -lqjson
}
INCLUDEPATH +=  . \
                ../../include
