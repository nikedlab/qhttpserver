TARGET = helloworld

QT += network
QT -= gui

CONFIG += debug

INCLUDEPATH += ../../src

SOURCES = helloworld.cpp
HEADERS = helloworld.h



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/release/ -lqhttpserver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/debug/ -lqhttpserverd
else:unix: LIBS += -L$$PWD/../../lib/debug/ -lqhttpserver

INCLUDEPATH += $$PWD/../../
DEPENDPATH += $$PWD/../../

RESOURCES += \
    certs.qrc
