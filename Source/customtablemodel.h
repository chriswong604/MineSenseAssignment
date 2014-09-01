#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H
#include <QAbstractTableModel>
#include <QStringList>
#include <string>
#include <sstream>
#include "data.h"
#include "filereader.h"
using namespace std;

#define HEADER_LINE 0
#define X_DATA 0
#define Y_DATA 1
#define COLUMN_SIZE 2


class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomTableModel(QObject *parent, QString source);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
    void setModel(QString source);
    QList<Data> datapoints;
    QStringList header;
};

#endif // CUSTOMTABLEMODEL_H
