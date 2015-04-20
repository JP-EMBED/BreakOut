TEMPLATE = app

QT += qml quick bluetooth

win32{
QT += serialport
}

SOURCES += main.cpp \
    ball.cpp \
    breakout.cpp \
    connectionmanager.cpp \
    cordinate.cpp \
    fotonledmessagefactory.cpp \
    ledboardmanager.cpp \
    random.cpp \
    serialconnectionmanager.cpp

RESOURCES += qml.qrc

CONFIG += C++11

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    BreakOut.qml \
    FindDeviceMenu.qml

HEADERS += \
    ball.h \
    breakout.h \
    connectionmanager.h \
    cordinate.h \
    fotonledmessagefactory.h \
    iConnection.h \
    ledboardmanager.h \
    random.h \
    serialconnectionmanager.h
