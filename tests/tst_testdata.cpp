#include "tst_testdata.h"



TestData::TestData()
{
    data = new Data(1.2, 5);
}


void TestData::testgetXData()
{

    QVERIFY(data->getXData() == 1.2);
}

void TestData::cleanupTestCase()
{
    delete(data);
}


