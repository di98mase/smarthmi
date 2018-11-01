#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

#include "newsitedlg.h"
#include "site.h"
#include "connectdlg.h"
#include "tablemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_setUpSiteButton_clicked();
    void assignNewSite(Site newSite);
    void on_connectToSiteButton_clicked();
    void saveSistesToFile();
//    void saveSiteToFile(Site site, QString fName);
    void loadSistesFromFile();

signals:
      void newSiteConfigured(Site newSite);

private:
    Ui::MainWindow *ui;
    NewSiteDlg *newSiteDlg;
    ConnectDlg *connectDlg;

    bool newSitesAdded;
    QString thePersistantFile = "sites.dat";
    QList <Site> listOfSites;
    TableModel *tableModel;

};

#endif // MAINWINDOW_H
