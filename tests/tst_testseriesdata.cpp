#include "tst_testseriesdata.h"

/**
 * Class Constructor
 */
TestSeriesData::TestSeriesData()
{
    QString source(":/rsc/testdata.csv");
    CustomTableModel *testTable = new CustomTableModel(0, source);
    testSeriesData = new CustomSeriesData(testTable);
}

/**
 * Test Case: testSize() - Tests that the seriesdata is the same size as the table
 */
void TestSeriesData::testSize()
{
    QVERIFY(testSeriesData->size() == 7);
}

/**
 * Test Case: testSampleValidIndex() - Tests if the seriesdata gets the same data from the specified index on the table.
 */
void TestSeriesData::testSampleValidIndex()
{
    QVERIFY(testSeriesData->sample(1).x() == 2 && testSeriesData->sample(1).y() == 5);
}


/**
 * Test Case: testSampleInvalidIndex() - Tests if the seriesdata returns an invalid QPointF for a invalid index
 */
void TestSeriesData::testSampleInvalidIndex()
{
    QVERIFY(testSeriesData->sample(100) == QPointF());
}

/**
 * Test Case: testBoundingRect() - Tests if boundingRect() sets the correct bounding rect
 */
void TestSeriesData::testBoundingRect()
{
    QVERIFY(testSeriesData->boundingRect() == QRectF(QPointF(0, 0), QPointF(7,5)));
}
