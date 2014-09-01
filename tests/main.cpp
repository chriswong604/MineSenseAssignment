#include "tst_testdata.h"
#include "tst_testtablemodel.h"


int main(int argc, char** argv)
{
    TestData test1;
    QTest::qExec(&test1, argc, argv);

    TestTableModel test2;
    QTest::qExec(&test2, argc, argv);
}


