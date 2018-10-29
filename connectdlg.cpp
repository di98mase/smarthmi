#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent, QList <Site> *listOfSites) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);

    tableModel = new TableModel(this, listOfSites);
    ui->tableView->setModel(tableModel);

}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}



