#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);

    tableModel = new TableModel(this);
    ui->tableView->setModel(tableModel);

    tableModel->insertRow(0);

    QModelIndex ix;
    ix = tableModel->index(0,0,QModelIndex());
    tableModel->data(ix, Qt::DisplayRole);
    ix = tableModel->index(0,1,QModelIndex());
    tableModel->data(ix, Qt::DisplayRole);
    //ui->tableView->




}

//ConnectDlg::ConnectDlg(QWidget *parent, TableModel *tableMod) :
//    QDialog(parent),
//    ui(new Ui::ConnectDlg)
//{
//    ui->setupUi(this);

//    ui->tableView->setModel(tableMod);

//    tableMod->headerData(0, Qt::Horizontal, Qt::DisplayRole);
//    tableModel->headerData(1, Qt::Horizontal, Qt::DisplayRole);
//    tableModel->headerData(2, Qt::Horizontal, Qt::DisplayRole);
//    tableModel->headerData(3, Qt::Horizontal, Qt::DisplayRole);
//    tableModel->headerData(4, Qt::Horizontal, Qt::DisplayRole);

//}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

//void ConnectDlg::connectTableModel(TableModel *tableMod)
//{
//   // ui->tableWidgetSites->setModel(tableMod);
//}

//void ConnectDlg::loadListOfSites()
//{
//    for (int i=0; i<ui->tableViewSites->size(); i++)
//    {
//;

//    }

//    }
   // ui->tableWidgetSites->

//}

void ConnectDlg::on_buttonBox_accepted()
{

}

//void ConnectDlg::purgeTableView(void)
//{
//    //
//}
