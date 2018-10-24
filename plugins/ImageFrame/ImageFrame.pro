CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(imageframeplugin)
TEMPLATE    = lib

HEADERS     = src/imageframeplugin.h
SOURCES     = src/imageframeplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(imageframe.pri)
