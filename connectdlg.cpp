#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);

    dataModelPtr = new TableModel(this);
    ui->tableView->setModel(dataModelPtr);


//    connect(this, &MainWindow::newSiteConfigured, connectDlg, ConnectDlg::assignNewSite);

}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

void ConnectDlg::assignNewSite(Site newSite)
{
    ;
}



