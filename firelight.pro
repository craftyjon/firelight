TEMPLATE = app

QT += quick qml

SUBDIRS += \
    src/firelight.pro

HEADERS += \
    #src/audio_manager.h \
    #src/colorspace.h \
    #src/fixture.h \
    #src/ndarray_wrapper.h \
    #src/preset_manager.h \
    #src/scene.h \
    #src/version.h

SOURCES += \
    #src/audio_manager.cpp \
    #src/fixture.cpp \
    src/main.cpp \
    #src/preset_manager.cpp \
    #src/scene.cpp

OTHER_FILES += \
    src/qml/firelight.qml \
    README.md \
    LICENSE.txt

RESOURCES += \
    firelight.qrc
