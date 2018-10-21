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
//    void on_pushButton_clicked();
    void on_setUpSiteButton_clicked();
    void addNewSite(QString siteName, QString ipAddress);
    void assignNewSite(Site newSite);

    void on_connectToSiteButton_clicked();
    void saveListOfSistesToFile();
    void loadListOfSistesFromFile();

private:
    Ui::MainWindow *ui;
    NewSiteDlg *newSiteDlg;
    Site *mySite;
    ConnectDlg *connectDlg;
    TableModel *sitesTable;

    QList <Site> listOfSites;

};

#endif // MAINWINDOW_H
