TEMPLATE = app

QT += qml quick bluetooth

win32{
QT += serialport
}

SOURCES += main.cpp \
    snake.cpp \
    fotonledmessagefactory.cpp \
    ledboardmanager.cpp \
    serialconnectionmanager.cpp \
    random.cpp \
    connectionmanager.cpp \
    cordinate.cpp

RESOURCES += qml.qrc

CONFIG += C++11

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    snake.h \
    fotonledmessagefactory.h \
    iConnection.h \
    ledboardmanager.h \
    serialconnectionmanager.h \
    random.h \
    connectionmanager.h \
    cordinate.h
