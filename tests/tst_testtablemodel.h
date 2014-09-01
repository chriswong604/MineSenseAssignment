#ifndef TST_TESTTABLEMODEL_H
#define TST_TESTTABLEMODEL_H

#include <QString>
#include <QtTest>
#include "customtablemodel.h"


class TestTableModel : public QObject
{
    Q_OBJECT

public:
    TestTableModel();

private Q_SLOTS:
    void initTestCase();
    void testRowCount();
    void testGetDataValidInput();
    void testGetDataIndexOutOfBounds();
    void testSetDataValidInput();
    void testSetDataInvalidIndex();
private:
    CustomTableModel *testTable;
};


#endif // TST_TESTTABLEMODEL_H
