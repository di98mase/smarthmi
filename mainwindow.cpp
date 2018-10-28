#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsitedlg.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <QDataStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // The list that will store all configured sites.
    QList <Site> listOfSites;

    // load it from file
    loadListOfSistesFromFile();


    // setup the new Site Dialog
    newSiteDlg = new NewSiteDlg(this);
    newSiteDlg->setModal(true);
    connectDlg = new ConnectDlg(this);
    connectDlg->setModal(true);


    // connect signals and slots
    connect(newSiteDlg, &NewSiteDlg::sendNewSiteProperties, this, &MainWindow::assignNewSite);






//    tableModelSites = new TableModel(listOfSites, this);
//    tableModelSites->headerData(0, Qt::Horizontal, Qt::DisplayRole);
//    tableModelSites->headerData(1, Qt::Horizontal, Qt::DisplayRole);
//    tableModelSites->headerData(2, Qt::Horizontal, Qt::DisplayRole);
//    tableModelSites->headerData(3, Qt::Horizontal, Qt::DisplayRole);
//    tableModelSites->headerData(4, Qt::Horizontal, Qt::DisplayRole);


    //connectDlg->loadListOfSites();
    //connectDlg->connectTableModel(tableModelSites);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadListOfSistesFromFile()
{
    listOfSites.clear();

    qDebug() <<"loadListOfSistesFromFile\n";

    QString filename = "sites.dat";
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly))
    {

        /* Read from file*/
        QDataStream stream(&file);

        stream >> listOfSites;

        file.close();
        qDebug() <<"file closed\n";
        ui->connectToSiteButton->setEnabled(true);

    }
    else
    {
        // TODO add Messagebox
        qDebug() <<"Failed to load sites from file\n";
    }

}

void MainWindow::saveListOfSistesToFile()
{

    qDebug() <<"saveListOfSistesToFile\n";

    QString filename = "sites.dat";
    QFile file(filename);

    if (file.open(QIODevice::Append))
    {
        QDataStream stream(&file);
        //push the entire list in one go...
        stream << listOfSites;

        file.close();
        qDebug() <<"file closed\n";
    }
    else
    {
        // TODO add Messagebox
        qDebug() <<"Failed to save sites to file\n";
    }

}

void MainWindow::saveSiteToFile(Site site)
{

    qDebug() <<"saveSiteToFile\n";

    QString filename = "sites.dat";
    QFile file(filename);

    if (file.open(QIODevice::Append))
    {
        QDataStream stream(&file);
        stream << site;
        file.close();
        qDebug() <<"file closed\n";
    }
    else
    {
        // TODO add Messagebox
        qDebug() <<"Failed to save sites to file\n";
    }

}

void MainWindow::assignNewSite(Site newSite)
{

    // save the new site to file
    listOfSites.append(newSite);
    saveSiteToFile(newSite);
    //saveListOfSistesToFile();

    ui->connectToSiteButton->setEnabled(true);
}

void MainWindow::on_setUpSiteButton_clicked()
{

    if(newSiteDlg->exec())
    {

    }
    else
    {
        qDebug() <<"Failed to load dialog\n";
    }

}

void MainWindow::on_connectToSiteButton_clicked()
{

    //connectDlg->purgeTableView();
   // connectDlg->loadListOfSites();

    if(connectDlg->exec())
    {

    }
    else
    {
        qDebug() <<"Failed to load dialog\n";
    }
}
