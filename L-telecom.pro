QT -= gui
QT += network

CONFIG += c++17 console
CONFIG -= app_bundle



SOURCES += \
        analyzer.cpp \
        main.cpp \
        server.cpp \
        textanalysis.cpp

# Default rules for deployment.

HEADERS += \
    analyzer.h \
    server.h \
    textanalysis.h

