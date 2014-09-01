/**
  * Class: TableGraph - The TableGraph class sets up the GUI for viewing the table and graph.
  */


#include "tablegraph.h"
#include "ui_tablegraph.h"

/**
 * Class Constructor
 * @param parent
 * @param sourceFile
 */
TableGraph::TableGraph(QWidget *parent, QString sourceFile) : QDialog(parent),
    ui(new Ui::TableGraph)
{
    ui->setupUi(this);

    this->sourceFile = sourceFile;
    setTable();
    setPlot();

}

/**
 * Class Deconstructor
 */
TableGraph::~TableGraph()
{
    delete ui;
}

/**
 * GUI Event: on_buttonBox_accepted() - This event is tied to the Save button on the GUI dialog.
 *                                      When the button is pressed a file writter is created to save any edited data back to the file.
 */
void TableGraph::on_buttonBox_accepted()
{
    FileWritter(myTable, sourceFile);
}

/**
 * Method: setTable() - setTable() sets up the table view used in the GUI.
 */
void TableGraph::setTable()
{
    myTable = new CustomTableModel(0, sourceFile);
    ui->tableView->setModel(myTable);
}

/**
 * Method setPlot() - setPlot() sets up the plot view used in the GUI.
 */
void TableGraph::setPlot()
{
    //set up the plot
    QwtPlot *plot = new QwtPlot(ui->graphView);
    plot->setCanvasBackground( Qt::white );
    plot->setAxisAutoScale(QwtPlot::yLeft, true);
    plot->setAxisTitle(QwtPlot::yLeft, myTable->headerData(0, Qt::Horizontal, Qt::DisplayRole).toString());
    plot->setAxisTitle(QwtPlot::xBottom, myTable->headerData(1, Qt::Horizontal, Qt::DisplayRole).toString());
    plot->insertLegend( new QwtLegend() );

    //set up the grid
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( plot );

    //set up the curve
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setPen( Qt::blue, 3 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    //set up the data symbol
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 1, 1 ) );
    curve->setSymbol( symbol );
    //replots the plot when tablemodel is changed
    QObject::connect(myTable, SIGNAL(dataChanged(QModelIndex,QModelIndex)), plot, SLOT(replot()));

    //set up where the data comes from
    CustomSeriesData *data = new CustomSeriesData(myTable);
    curve->setSamples( data );
    curve->attach( plot );

    plot->resize( ui->graphView->width(), ui->graphView->height() );
}
