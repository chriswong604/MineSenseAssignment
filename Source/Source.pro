
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = MineSenseApp
TEMPLATE = lib

SOURCES +=  customseriesdata.cpp\
            customtablemodel.cpp\
            data.cpp\
            filereader.cpp\
            filewritter.cpp\
            mainwindow.cpp\
            tablegraph.cpp\

HEADERS +=  customseriesdata.h\
            customtablemodel.h\
            data.h\
            filereader.h\
            filewritter.h\
            mainwindow.h\
            tablegraph.h\

FORMS +=    mainwindow.ui\
            tablegraph.ui




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../../../../../../Qwt-6.1.0/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../../Qwt-6.1.0/include
DEPENDPATH += $$PWD/../../../../../../Qwt-6.1.0/include
