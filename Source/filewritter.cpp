/**
  Class: FileWritter - FileWritter writes data from a table model to a file.
  */

#include "filewritter.h"

FileWritter::FileWritter(CustomTableModel *table, QString source)
{
    QFile sourceFile(source);
    if(!sourceFile.open( QFile::WriteOnly|
                  QFile::Text))
    {
        qDebug() << " Could not open the file for writting";
    }
    QTextStream out(&sourceFile);
    out << table->headerData(0, Qt::Horizontal, Qt::DisplayRole).toString() << ',' << table->headerData(1, Qt::Horizontal, Qt::DisplayRole).toString() << endl;
    for(int i = 0; i < table->rowCount(); i++){
        QModelIndex y = table->index(i, 0, QModelIndex());
        QModelIndex y2 = table->index(i, 1, QModelIndex());
        out << table->data(y, Qt::DisplayRole).toString() << ',' << table->data(y2, Qt::DisplayRole).toString() << endl;
    }
}
