#-------------------------------------------------
#
# Project created by QtCreator 2014-08-29T17:55:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app


SOURCES += main.cpp




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Source/release/ -lMineSenseApp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Source/debug/ -lMineSenseApp
else:unix: LIBS += -L$$OUT_PWD/../Source/ -lMineSenseApp

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../../Qwt-6.1.0/include
DEPENDPATH += $$PWD/../../../../../../Qwt-6.1.0/include
