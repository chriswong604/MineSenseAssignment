/**
  * Class: CustomSeriesData - A Subclass of QwtSeriesData, the CustomSeriesData class
  *                           iterates over a sample(The Table Model) to be plotted.
  */

#include "customseriesdata.h"

/**
 * Class Constructor
 * @param model
 */
CustomSeriesData::CustomSeriesData(CustomTableModel *model)
{
    this->model = model;
}

/**
 * Method: size() - A subclass of QwtSeriesData must implement this method.
 *                  size() is used to return the number of samples.
 * @return
 */
size_t CustomSeriesData::size() const
{
    return model->rowCount();
}

/**
 * Method : sample() - A subclass of QwtSeriesData must implement this method.
 *                     sample() is used to return a sample at the given index.
 * @param index
 * @return
 */
QPointF CustomSeriesData::sample(size_t index) const
{
    if(index < size()){
        QModelIndex i = model->index(index, 0, QModelIndex()); //get X Data
        QModelIndex i2 = model->index(index, 1, QModelIndex()); //get Y Data

        return QPointF(model->data(i, Qt::DisplayRole).toDouble(), model->data(i2, Qt::DisplayRole).toDouble());
    }
    return QPointF();
}

/**
 * Method : boundingRect() - A subclass of QwtSeriesData must implement this method.
 *                           boundingRect() calculates the bounding rect of all samples.
 *                           The bounding rect is needed for autoscaling of the plot.
 * @return
 */
QRectF CustomSeriesData::boundingRect() const
{
    double minX, minY, maxX, maxY;
    minX = minY = maxX = maxY = 0;
    //determine the min and max values of the X and Y axis.
    for(int i = 0; i < model->rowCount(); i++){
       QModelIndex j = model->index(i, 0, QModelIndex());
       QModelIndex j2 = model->index(i, 1, QModelIndex());
       if(model->data(j, Qt::DisplayRole).toDouble() > maxX){
           maxX = model->data(j, Qt::DisplayRole).toDouble();
       }
       else if(model->data(j, Qt::DisplayRole).toDouble() < minX){
           minX = model->data(j, Qt::DisplayRole).toDouble();
       }

       if(model->data(j2, Qt::DisplayRole).toDouble() > maxY){
           maxY = model->data(j2, Qt::DisplayRole).toDouble();
       }
       else if(model->data(j2, Qt::DisplayRole).toDouble() < minY){
           minY = model->data(j2, Qt::DisplayRole).toDouble();
       }
    }
     QwtSeriesData::d_boundingRect = QRectF(QPointF(minX, minY), QPointF(maxX, maxY));
     return QwtSeriesData::d_boundingRect;
}


