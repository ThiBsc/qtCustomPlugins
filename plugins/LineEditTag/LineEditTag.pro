CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(lineedittagplugin)
TEMPLATE    = lib

HEADERS     = src/lineedittagplugin.h
SOURCES     = src/lineedittagplugin.cpp
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

include(lineedittag.pri)
