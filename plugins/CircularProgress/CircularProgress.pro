CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(circularprogressplugin)
TEMPLATE    = lib

HEADERS     = src/circularprogressplugin.h
SOURCES     = src/circularprogressplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
    CONFIG += c++11
} else {
    CONFIG += designer
    QMAKE_CXXFLAGS += -std=c++11
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(circularprogress.pri)
