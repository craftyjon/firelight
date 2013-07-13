TEMPLATE = app
CONFIG += qt debug console
TARGET = firelight
QT += core gui network
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL QT_NETWORK_LIB

SOURCES += src/main.cpp

HEADERS += 	src/version.h \
			src/preset.h \
			src/preset_helper.h \
			src/scene.h

INCLUDEPATH += /usr/include/python2.7
LIBS += -lboost_python -lpython2.7 -lboost_filesystem