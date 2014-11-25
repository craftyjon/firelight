TEMPLATE = app

QT += quick qml

SUBDIRS += \
    src/firelight.pro

HEADERS += \
    #src/audio_manager.h \
    #src/colorspace.h \
    src/fixture.h \
    #src/ndarray_wrapper.h \
    #src/preset_manager.h \
    src/scene.h \
    #src/version.h
    src/python/firelight_python_module.h \
    src/python/parameters.h \
    src/python/preset.h \
    src/python/scene.h \
    src/preset_manager.h \
    src/colorspace.h \
    src/ndarray_wrapper.h

SOURCES += \
    #src/audio_manager.cpp \
    src/fixture.cpp \
    src/main.cpp \
    #src/preset_manager.cpp \
    src/scene.cpp \
    src/preset_manager.cpp

OTHER_FILES += \
    README.md \
    LICENSE.txt \
    src/qml/styles/qmldir.txt \
    src/qml/styles/ButtonStyle.qml \
    src/qml/styles/qmldir \
    src/qml/Viewport.qml \
    src/qml/Firelight.qml \
    src/qml/components/Surface.qml

RESOURCES += \
    firelight.qrc

LIBS += -lboost_system -lboost_filesystem -lboost_python -lboost_numpy -lpython2.7
