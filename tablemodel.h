#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QVariant>
#include <QModelIndex>

#include "site.h"

class TableModel : public QAbstractTableModel
{

    Q_OBJECT

public:
    TableModel(QObject *parent);
    TableModel(QObject *parent, QList <Site> listSites);


    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    //void loadSistesFromFile();

//    bool insertRows(int position, int rows, const QModelIndex &index) override;
//    bool removeRows(int position, int rows, const QModelIndex &index) override;
//    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
//    Qt::ItemFlags flags(const QModelIndex &index) const override;
//    QList<Site> getSites() const;

private:

    QList <Site> listOfSites;
//    QString fName="sites.dat";

};

#endif // TABLEMODEL_H
