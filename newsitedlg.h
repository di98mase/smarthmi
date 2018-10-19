#ifndef NEWSITEDLG_H
#define NEWSITEDLG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>

#include "site.h"

namespace Ui {
class NewSiteDlg;
}

class NewSiteDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NewSiteDlg(QWidget *parent = 0);
    ~NewSiteDlg();

private slots:

    void on_btnBox_accepted();

signals:
      void sendNewSiteDetails(QString name, QString address);
      void sendNewSiteProperties(Site newSite);

private:
    Ui::NewSiteDlg *ui;

};

#endif // NEWSITEDLG_H
