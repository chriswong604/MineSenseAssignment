#ifndef TESTDATA_H
#define TESTDATA_H

#include <QtTest/QtTest>
#include "data.h"

class TestData: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testGetXData();
};



#endif // TESTDATA_H
