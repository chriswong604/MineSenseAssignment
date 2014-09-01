#ifndef TST_TESTSERIESDATA_H
#define TST_TESTSERIESDATA_H

#include <QString>
#include <QtTest>
#include "customseriesdata.h"

class TestSeriesData : public QObject
{
    Q_OBJECT
public:
    TestSeriesData();

private Q_SLOTS:
    void testSize();
    void testSampleValidIndex();
    void testSampleInvalidIndex();
    void testBoundingRect();
private:
    CustomSeriesData *testSeriesData;
};

#endif // TST_TESTSERIESDATA_H
