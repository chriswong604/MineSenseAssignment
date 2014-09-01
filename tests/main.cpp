#include "tst_testtablemodel.h"
#include "tst_testseriesdata.h"


int main(int argc, char** argv)
{

    TestTableModel test1;
    QTest::qExec(&test1, argc, argv);

    TestSeriesData test2;
    QTest::qExec(&test2, argc, argv);


}


