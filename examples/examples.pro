TEMPLATE = subdirs
SUBDIRS += \
helloworld\
#greeting\
#bodydata\

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lqhttpserver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lqhttpserver
else:unix: LIBS += -L$$PWD/../lib/ -lqhttpserver

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
