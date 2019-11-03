QT += quick quickwidgets
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/main.cpp \
    src/ChessbBoard.cpp

RESOURCES += \
    src/resources/qml.qrc \
    src/resources/icons.qrc

HEADERS += \
    src/ChessbBoard.h
