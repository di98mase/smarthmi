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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_setUpSiteButton_clicked();
    void assignNewSite(Site newSite);
    void on_connectToSiteButton_clicked();
    void saveListOfSistesToFile(QString fName);
    void saveSiteToFile(Site site, QString fName);
    void loadListOfSistesFromFile(QList <Site> *listOfSitesPtr, QString fName);

private:
    Ui::MainWindow *ui;
    NewSiteDlg *newSiteDlg;
    ConnectDlg *connectDlg;

    QList <Site> *listOfSites;
    QString thePersistantFile = "sites.dat";

};

#endif // MAINWINDOW_H
