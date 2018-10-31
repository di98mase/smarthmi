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

    newSitesAdded=false;

    // setup the new Site Dialog
    newSiteDlg = new NewSiteDlg(this);
    newSiteDlg->setModal(true);
    connectDlg = new ConnectDlg(this);
    connectDlg->setModal(true);

    loadSistesFromFile();

    // connect signals and slots
    connect(newSiteDlg, &NewSiteDlg::newSiteConfigured, this, &MainWindow::assignNewSite);

}

MainWindow::~MainWindow()
{
    if (newSitesAdded == true)
    {
        saveSistesToFile();
    }
    delete ui;
}

void MainWindow::loadSistesFromFile()
{
    listOfSites.clear();
    qDebug() << "loadListOfSistesFromFile\n";
    QFile file(thePersistantFile);

    if (file.open(QIODevice::ReadOnly))
    {
        /* Read and load Sites from file */
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

void MainWindow::saveSistesToFile()
{
    qDebug() <<"saveListOfSistesToFile\n";
    QFile file(thePersistantFile);

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

//void MainWindow::saveSiteToFile(Site site, QString fName)
//{

//    qDebug() <<"saveSiteToFile\n";

//    QFile file(fName);

//    if (file.open(QIODevice::Append))
//    {
//        QDataStream stream(&file);
//        stream << site;
//        file.close();
//        qDebug() <<"file closed\n";
//    }
//    else
//    {
//        // TODO add Messagebox
//        qDebug() <<"Failed to save sites to file\n";
//    }

//}

void MainWindow::assignNewSite(Site newSite)
{
    listOfSites.append(newSite);
    newSitesAdded = true;
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
