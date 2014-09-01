#include "tst_testtablemodel.h"

TestTableModel::TestTableModel()
{
}

void TestTableModel::initTestCase()
{
    QString source(":/rsc/testdata.csv");
    testTable = new CustomTableModel(0, source);
}

void TestTableModel::testRowCount()
{
    QVERIFY(testTable->rowCount() == 7);
}

void TestTableModel::testGetDataValidInput()
{
    QModelIndex index = testTable->index(2,1, QModelIndex());
    QVERIFY(testTable->data(index, Qt::DisplayRole) == 0);
}

void TestTableModel::testGetDataIndexOutOfBounds()
{
    QModelIndex index = testTable->index(2, 2, QModelIndex());
    QVERIFY(testTable->data(index, Qt::DisplayRole) == QVariant::Invalid);
}

void TestTableModel::testSetDataValidInput()
{
    QModelIndex index = testTable->index(2, 1);
    testTable->setData(index, QVariant(10), Qt::EditRole );
    QVERIFY(testTable->data(index, Qt::DisplayRole) == 10);
}

void TestTableModel::testSetDataInvalidIndex()
{
    QVERIFY(testTable->setData(QModelIndex(), QVariant(10), Qt::EditRole) == false);

}






