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
    explicit ConnectDlg(QWidget *parent = 0, QList <Site> *listOfSites=0);
    ~ConnectDlg();

private slots:
    //void on_buttonBox_accepted();

private:
    TableModel *tableModel;
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
