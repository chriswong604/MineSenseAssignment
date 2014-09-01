#ifndef TABLEGRAPH_H
#define TABLEGRAPH_H

#include <QDialog>
#include <Qt>
#include <QTableView>
#include <QtGui>
#include <QBoxLayout>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QFileDialog>
#include "CustomTableModel.h"
#include "CustomSeriesData.h"
#include "FileWritter.h"


namespace Ui {
class TableGraph;
}

class TableGraph : public QDialog
{
    Q_OBJECT

public:
    explicit TableGraph(QWidget *parent = 0, QString sourceFile = NULL);
    ~TableGraph();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TableGraph *ui;
    CustomTableModel *myTable;
    QString sourceFile;
    void setTable();
    void setPlot();
};

#endif // TABLEGRAPH_H
