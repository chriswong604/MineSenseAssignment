#ifndef CUSTOMSERIESDATA_H
#define CUSTOMSERIESDATA_H
#include <qwt_series_data.h>
#include "customtablemodel.h"

class CustomSeriesData : public QwtSeriesData<QPointF>
{
public:
    CustomSeriesData(CustomTableModel *model);
    size_t size() const;
    QRectF boundingRect() const;
    QPointF sample(size_t index) const;
private:
    CustomTableModel *model;
};

#endif // CUSTOMSERIESDATA_H
