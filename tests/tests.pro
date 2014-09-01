#-------------------------------------------------
#
# Project created by QtCreator 2014-08-29T19:25:01
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_testtablemodel.cpp \
    main.cpp \
    tst_testseriesdata.cpp



DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    tst_testtablemodel.h \
    tst_testseriesdata.h



RESOURCES += resources.qrc







win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../../Qwt-6.1.0/include
DEPENDPATH += $$PWD/../../../../../../Qwt-6.1.0/include



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Source/release/ -lMineSenseApp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Source/debug/ -lMineSenseApp
else:unix: LIBS += -L$$OUT_PWD/../Source/ -lMineSenseApp

INCLUDEPATH += $$PWD/../Source
DEPENDPATH += $$PWD/../Source
