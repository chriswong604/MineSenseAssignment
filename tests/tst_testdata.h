#ifndef TST_TESTDATA_H
#define TST_TESTDATA_H

#include <QString>
#include <QtTest>
#include "data.h"


class TestData : public QObject
{
    Q_OBJECT

public:
    TestData();

private Q_SLOTS:
    void testgetXData();
    void cleanupTestCase();
private:
    Data *data;

};





#endif // TST_TESTDATA_H
