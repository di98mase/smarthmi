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
    void saveListOfSistesToFile();
    void saveSiteToFile(Site site);
    void loadListOfSistesFromFile();

private:
    Ui::MainWindow *ui;
    NewSiteDlg *newSiteDlg;
    //Site *mySite;
    ConnectDlg *connectDlg;
    //TableModel *tableModel;

    QList <Site> listOfSites;

};

#endif // MAINWINDOW_H
