/**
  * Class TestTableModel - Test Class for CustomTableModel
  */

#include "tst_testtablemodel.h"

/**
 * Class constructor
 */
TestTableModel::TestTableModel()
{
    QString source(":/rsc/testdata.csv");
    testTable = new CustomTableModel(0, source);
}

/**
 * Test Case: testRowCount() - Tests to ensure that the table is set up with the correct row count
 */
void TestTableModel::testRowCount()
{
    QVERIFY(testTable->rowCount() == 7);
}

/**
 * Test Case: testGetDataValidInput() - Tests to ensure that the data that is stored in the table is the same as on the file
 */
void TestTableModel::testGetDataValidInput()
{
    QModelIndex index = testTable->index(2,1, QModelIndex());
    QVERIFY(testTable->data(index, Qt::DisplayRole) == 0);
}

/**
 * Test Case: testGetDataIndexOutOfBounds() - Tests getting data using an invalid index
 */
void TestTableModel::testGetDataIndexOutOfBounds()
{
    QModelIndex index = testTable->index(2, 2, QModelIndex());
    QVERIFY(testTable->data(index, Qt::DisplayRole) == QVariant::Invalid);
}

/**
 * Test Case: testSetDataValidInput() - Tests the editing of data in the table.
 */
void TestTableModel::testSetDataValidInput()
{
    QModelIndex index = testTable->index(2, 1);
    testTable->setData(index, QVariant(10), Qt::EditRole );
    QVERIFY(testTable->data(index, Qt::DisplayRole) == 10);
}

/**
 * Test Case: testSetDataInvalidIndex() - Tests editing of data using an invalid index
 */
void TestTableModel::testSetDataInvalidIndex()
{
    QVERIFY(testTable->setData(QModelIndex(), QVariant(10), Qt::EditRole) == false);

}






