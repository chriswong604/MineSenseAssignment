/**
  * Class: MainWindow - The main GUI of the application.
  */

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * Class Constructor
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * Class Deconstructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * GUI Event: on_pushButton_clicked() - This button press opens up a FileDialog so that the user may select a CSV file for reading.
 */
void MainWindow::on_pushButton_clicked()
{
    QString sourceFile = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::rootPath(), "CSV Files (*.csv)");
    if(sourceFile != NULL){
        TableGraph *test = new TableGraph(0, sourceFile);
        test->setModal(true);
        test->setAttribute( Qt::WA_DeleteOnClose, true );
        test->show();
    }
}
