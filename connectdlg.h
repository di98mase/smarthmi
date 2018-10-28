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
    explicit ConnectDlg(QWidget *parent = 0);
    //ConnectDlg(QWidget *parent = 0, TableModel *tableMod = 0);
    ~ConnectDlg();
    void loadListOfSites();
    //void purgeTableView(void);
    //void connectTableModel(TableModel *tableMod);

private slots:
    void on_buttonBox_accepted();

private:
    TableModel *tableModel;
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
