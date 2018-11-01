#ifndef CONNECTDLG_H
#define CONNECTDLG_H

#include <QDialog>
#include "site.h"
#include "tablemodel.h"

namespace Ui {
class ConnectDlg;
}

class ConnectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDlg(QWidget *parent = nullptr);
    ConnectDlg(QWidget *parent, QList <Site> listOfSites);
    ~ConnectDlg();

private slots:
    //void on_buttonBox_accepted();
    void assignNewSite(Site newSite);

signals:
      void newSiteConfigured(Site newSite);

private:
    TableModel *dataModelPtr;
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
