#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    tblModPtr(new TableModel(parent)),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
    ui->tableView->setModel(tblModPtr);
}

ConnectDlg::ConnectDlg(QWidget *parent, QList <Site> listOfSites) :
    QDialog(parent),
    tblModPtr(new TableModel(parent)),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);

    tblModPtr = new TableModel(this, listOfSites);
    ui->tableView->setModel(tblModPtr);
}

ConnectDlg::ConnectDlg(QWidget *parent, TableModel *tblModel) :
    QDialog(parent),
    tblModPtr(tblModel),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
    ui->tableView->setModel(tblModel);
}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

void ConnectDlg::assignNewSite(Site newSite)
{
    ;
}



