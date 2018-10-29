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
    // själva pekaren borde vara const.
    QList <Site> *listOfSites = new QList <Site>;

    // load it from file
    loadListOfSistesFromFile(listOfSites, thePersistantFile);


    // setup the new Site Dialog
    newSiteDlg = new NewSiteDlg(this);
    newSiteDlg->setModal(true);
    connectDlg = new ConnectDlg(this, listOfSites);
    connectDlg->setModal(true);


    // connect signals and slots
    connect(newSiteDlg, &NewSiteDlg::sendNewSiteProperties, this, &MainWindow::assignNewSite);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadListOfSistesFromFile(QList <Site> *listOfSitesPtr, QString fName)
{
    listOfSitesPtr->clear();

    qDebug() <<"loadListOfSistesFromFile\n";

    QFile file(fName);

    if (file.open(QIODevice::ReadOnly))
    {

        /* Read from file*/
        QDataStream stream(&file);

        stream >> (*listOfSitesPtr);  // blir detta rätt?

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

void MainWindow::saveListOfSistesToFile(QString fName)
{

    qDebug() <<"saveListOfSistesToFile\n";

    QFile file(fName);

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

void MainWindow::saveSiteToFile(Site site, QString fName)
{

    qDebug() <<"saveSiteToFile\n";

    QFile file(fName);

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
    listOfSites->append(newSite);
    saveSiteToFile(newSite,thePersistantFile);


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

    if(connectDlg->exec())
    {

    }
    else
    {
        qDebug() <<"Failed to load dialog\n";
    }
}
