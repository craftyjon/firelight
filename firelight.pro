QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firelight
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/ui/firelight_main.cpp \
    src/ui/simulator_scene.cpp \
    src/ui/simulator_view.cpp \
    src/ui/fixture_item.cpp

HEADERS += \
    src/version.h \
    src/ui/firelight_main.h \
    src/ui/simulator_scene.h \
    src/ui/simulator_view.h \
    src/python/firelight_python_module.h \
    src/python/preset.h \
    src/python/scene.h \
    src/thirdparty/boost_python_qstring.h \
    src/thirdparty/boost_python_stdout.h \
    src/ui/fixture_item.h

FORMS += \
    src/ui/firelight_main.ui

OTHER_FILES += \
    src/presets/hue_fade.py

INCLUDEPATH += src/ src/ui /usr/include/python2.7
#LIBS += -lboost_system -lboost_filesystem -lboost_python -lboost_numpy -lpython2.7

RESOURCES += \
    src/res/firelight.qrc
