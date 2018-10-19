#ifndef CONNECTDLG_H
#define CONNECTDLG_H

#include <QDialog>
#include "site.h"

namespace Ui {
class ConnectDlg;
}

class ConnectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDlg(QWidget *parent = 0);
    ~ConnectDlg();
    void loadListOfSites(Site *aListOfSites);
    void purgeTableView(void);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
