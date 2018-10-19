#include "newsitedlg.h"
#include "ui_newsitedlg.h"

NewSiteDlg::NewSiteDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSiteDlg)
{
    ui->setupUi(this);

}

NewSiteDlg::~NewSiteDlg()
{
    delete ui;
}



void NewSiteDlg::on_btnBox_accepted()
{
    // Get the parameter values from the dialog and send it as a signal

    QString sName = ui->lneditSiteName->text();
    QString sIp = ui->lnedtSiteIp->text();
    QString sPin = ui->lnedtSitePin->text();
    QString sLang = ui->cbxSiteLang->currentText();
    QString sDesc = ui->ptxtedtSiteDes->toPlainText();

    Site aSite(sName,sIp,sPin,sLang,sDesc);

  //emit sendNewSiteDetails(sName,sIp);
    emit sendNewSiteProperties(aSite);

}
