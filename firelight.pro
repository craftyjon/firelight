TEMPLATE = app
CONFIG += qt debug
TARGET = firelight
QT += core gui network
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL QT_NETWORK_LIB

SOURCES += 	src/main.cpp \
			src/ui/firelight_main.cpp \
			src/ui/simulator_view.cpp \
			src/ui/simulator_scene.cpp

HEADERS += 	src/version.h \
			src/python/preset.h \
			src/python/scene.h \
			src/python/firelight_python_module.h \
			src/ui/firelight_main.h \
			src/ui/simulator_view.h \
			src/ui/simulator_scene.h \
			src/thirdparty/boost_python_qstring.h \
			src/thirdparty/boost_python_stdout.h

FORMS += 	src/ui/firelight_main.ui

RESOURCES +=	src/res/firelight.qrc

INCLUDEPATH += /usr/include/python2.7
LIBS += -lboost_python -lpython2.7 -lboost_filesystem

UI_DIR = src/ui/
RCC_DIR = src/res/