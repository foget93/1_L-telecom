QT -= gui
QT += network

CONFIG += c++17 console
CONFIG -= app_bundle



SOURCES += \
        abstractAlgorithm.cpp \
        analyzer.cpp \
        main.cpp \
        server.cpp

# Default rules for deployment.

HEADERS += \
    abstractAlgorithm.h \
    analyzer.h \
    server.h

