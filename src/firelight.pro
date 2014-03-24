QT += core gui widgets
TARGET = firelight
TEMPLATE = app

SOURCES += \
    main.cpp \
    ui/firelight_main.cpp \
    ui/simulator_scene.cpp \
    ui/simulator_view.cpp \
    ui/fixture_item.cpp \
    preset_manager.cpp \
    audio_manager.cpp \
    scene_file.cpp

HEADERS += \
    version.h \
    ui/firelight_main.h \
    ui/simulator_scene.h \
    ui/simulator_view.h \
    python/firelight_python_module.h \
    python/preset.h \
    python/scene.h \
    thirdparty/boost_python_qstring.h \
    thirdparty/boost_python_stdout.h \
    ui/fixture_item.h \
    preset_manager.h \
    python/parameters.h \
    colorspace.h \
    ndarray_wrapper.h \
    audio_manager.h \
    scene_file.h

FORMS += \
    ui/firelight_main.ui

INCLUDEPATH +=  ui /usr/include/python2.7
LIBS += -lboost_system -lboost_filesystem -lboost_python -lboost_numpy -lpython2.7 -lportaudio

RESOURCES += \
    res/firelight.qrc
