#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsitedlg.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    // setup the new Site Dialog
    newSiteDlg = new NewSiteDlg(this);
    newSiteDlg->setModal(true);

    mySite = new Site();

    connectDlg = new ConnectDlg(this);
    connectDlg->setModal(true);

    sitesTable = new TableModel(this);

    // The list of all configured sites.
    QList <Site> listOfSites;

    // setup the widgets of main window

    connect(newSiteDlg, &NewSiteDlg::sendNewSiteDetails, this, &MainWindow::addNewSite);
    connect(newSiteDlg, &NewSiteDlg::sendNewSiteProperties, this, &MainWindow::assignNewSite);

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadListOfSistesFromFile()
{
    listOfSites.clear();

    qDebug() <<"loadListOfSistesFromFile\n";

//    QString filename = "sites.dat";
//    QFile file(filename);

//    if (file.open(QIODevice::ReadOnly))
//    {
//        /*for Reading line by line from text file*/
//        while (!file.atEnd()) {
//            QByteArray line = file.readLine();
//            QString aRow = line.toStdString();

//            QStringList list = aRow.split(QRegExp(","), QString::SkipEmptyParts);

//        QTextStream stream(&file);
//        stream << mySite->getName() << ","
//               << mySite->getIp() << ","
//               << mySite->getLang() << ","
//               << mySite->getPin() << ","
//               << mySite->getDescription() << endl;
//        stream.flush();
//        file.close();
//        qDebug() <<"file closed\n";
 //   }
//    else
//    {
//        // TODO add Messagebox
//        qDebug() <<"Failed to save sites to file\n";
//    }



}

void MainWindow::saveListOfSistesToFile()
{


    //qDebug() <<"saveListOfSistesToFile\n";

    QString filename = "sites.dat";
    QFile file(filename);

    if (file.open(QIODevice::Append))
    {
        QTextStream stream(&file);
        stream << (*mySite); //overlaod of << requires objects and not pointers, thus convert pointer to object.
        stream.flush();
        file.close();
        qDebug() <<"file closed\n";
    }
    else
    {
        // TODO add Messagebox
        qDebug() <<"Failed to save sites to file\n";
    }

}

void MainWindow::addNewSite(QString siteName, QString ipAddress)
{
    //  Check new site parameters and store them if ok
    mySite->setAllParameters(siteName, ipAddress, "0","0","0");
    //mySite->

    ui->connectToSiteButton->setEnabled(true);

}

void MainWindow::assignNewSite(Site newSite)
{

    mySite->setAllParameters(newSite.siteName, newSite.siteIpAddress,    
                             newSite.sitePin, newSite.siteLang, newSite.siteDescription);

    // save the new site to file
    saveListOfSistesToFile();

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

    connectDlg->purgeTableView();
    connectDlg->loadListOfSites(mySite);

    if(connectDlg->exec())
    {

    }
    else
    {
        qDebug() <<"Failed to load dialog\n";
    }
}
