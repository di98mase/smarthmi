#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

void ConnectDlg::loadListOfSites(Site *aListOfSites)
{
    //for (int i=0; i<)
    ui->listSites->insertItem(0, aListOfSites->getName());
}

void ConnectDlg::on_buttonBox_accepted()
{

}

void ConnectDlg::purgeTableView(void)
{
    ui->listSites->clear();
}
