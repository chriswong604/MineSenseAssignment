/**
  * Class : CustomTableModel - A Subclass of QAbstractTableModel, the CustomTableModel class
  *                            provides a a way to represent data from a file in table form.
  */

#include "customtablemodel.h"

/**
 * Class Constructor
 * @param parent
 * @param source
 */
CustomTableModel::CustomTableModel(QObject *parent, QString source)
{
    Q_UNUSED ( parent );
    setModel(source);
}


/**
 * Method: setModel() - setModel() reads data from a file and saves the data in a
 *                      list to be used for creating the table.
 * @param source - The file to be read
 */
void CustomTableModel::setModel(QString source)
{
    FileReader reader(source);

    QStringList dataByLine = reader.getText();
    header = dataByLine.value(HEADER_LINE).split(',');
    for(int i = 1; i < dataByLine.size(); i++){
        QStringList linesSplit = dataByLine.value(i).split(',');
        Data data(linesSplit.value(X_DATA).toDouble(), linesSplit.value(1).toDouble());
        datapoints << data;
    }
}

/**
 * Method: rowCount() - A subclass of QAbstractTableModel must implement this method.
 *                      rowCount() returns the number of rows in the table.
 * @param parent
 * @return  - Returns the number of rows in the table
 */
int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED ( parent );
    return datapoints.size();
}

/**
 * Method: columnCount() - A subclass of QAbstractTableModel must implement this method.
 *                        columnCount() returns the number of columns in the table.
 * @param parent
 * @return - Returns the number of columns in the table.
 */
int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED ( parent );
    return COLUMN_SIZE;
}

/**
 * Method: data() - A subclass of QAbstractTableModel must implement this method.
 *                  data() is used to return the data at a given index on the table.
 * @param index
 * @param role
 * @return        - Returns the data at the given index. If the given index is out of bounds it will return a invalid QVariant
 */
QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole){
        Data point = datapoints.value(index.row());

        if(index.column() == X_DATA){
            return point.getXData();
        }
        else if(index.column() == Y_DATA){
            return point.getYData();
        }
    }
    return QVariant(); //return a invalid QVariant
}

/**
 * Method: setData() - This method must be implemented to enable editing of the table.
 *                     setData() is used to set the data at the given index.
 * @param index
 * @param value
 * @param role
 * @return - Returns true if the data was set, false if it was not.
 */
bool CustomTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if(role == Qt::EditRole){
        if(index.column() < 2 && index.isValid()){
            if(index.column() == X_DATA){
                datapoints[index.row()].setXData(value.toDouble());
            }
            else if(index.column() == Y_DATA){
                datapoints[index.row()].setYData(value.toDouble());
            }

            emit dataChanged(QAbstractItemModel::createIndex(0,0), QAbstractItemModel::createIndex(COLUMN_SIZE, datapoints.length()));
            return true;
        }
    }
    return false;
}

/**
 * These flags must be set to enable editing of the table.
 */
Qt::ItemFlags CustomTableModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled ;
}

/**
 * Method: headerData() - headerData returns the headers that are used for the coulums/rows
 * @param section
 * @param orientation
 * @param role
 * @return
 */
QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
        if(section == X_DATA && orientation == Qt::Horizontal){
            return header.value(X_DATA);
        }
        else if(section == Y_DATA && orientation == Qt::Horizontal){
            return header.value(Y_DATA);
        }
    }
    return QVariant();
}
