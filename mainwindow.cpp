#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsitedlg.h"

#include <QDebug>


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


    // setup the widgets of main window

    connect(newSiteDlg, &NewSiteDlg::sendNewSiteDetails, this, &MainWindow::addNewSite);
    connect(newSiteDlg, &NewSiteDlg::sendNewSiteProperties, this, &MainWindow::assignNewSite);

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->connectToSiteButton->setEnabled(true);
    mySite->setAllParameters(newSite.siteName, newSite.siteIpAddress,
                               newSite.sitePin, newSite.siteLang, newSite.siteDescription);
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
