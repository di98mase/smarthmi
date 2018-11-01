#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
    dataModelPtr = new TableModel(this);
    ui->tableView->setModel(dataModelPtr);
}

ConnectDlg::ConnectDlg(QWidget *parent, QList <Site> listOfSites) :
    QDialog(parent),
    ui(new Ui::ConnectDlg),
    dataModelPtr(new TableModel(nullptr))
{
    ui->setupUi(this);

    dataModelPtr = new TableModel(this, listOfSites);
    ui->tableView->setModel(dataModelPtr);
}


ConnectDlg::~ConnectDlg()
{
    delete ui;
}

void ConnectDlg::assignNewSite(Site newSite)
{
    ;
}



