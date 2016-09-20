TEMPLATE = app

QT += qml quick testlib
CONFIG += c++11

SOURCES += test.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

include(src/src.pri)
include(test/test.pri)
include(Box2D/Box2D.pri)
