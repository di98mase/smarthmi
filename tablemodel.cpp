#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
{
   Q_UNUSED(parent);
}

TableModel::TableModel(QObject *parent, QList <Site> listSites) :
    listOfSites(listSites)
{
   Q_UNUSED(parent);
}


int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfSites.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    // TODO...fixa resten
    Q_UNUSED(parent);
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();

    if (index.row() >= listOfSites.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {

            int row = index.row();

        if (index.column() == 0)
            return listOfSites.at(row).siteName;
        else if (index.column() == 1)
            return listOfSites.at(row).siteIpAddress;
        else if (index.column() == 2)
            return listOfSites.at(row).siteLang;
        else if (index.column() == 3)
            return listOfSites.at(row).sitePin;
        else if (index.column() == 4)
            return listOfSites.at(row).siteDescription;

    }
    return QVariant();

}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Site name");
            case 1:
                return tr("Site IP address");
            case 2:
                return tr("Site Language");
            case 3:
                return tr("Site Pin");
            case 4:
                return tr("Site Description");
        default:
                return QVariant();
        }
    }
    return QVariant();
}

//void TableModel::loadSistesFromFile()
//{
//    listOfSites.clear();

//    qDebug() <<"loadListOfSistesFromFile\n";

//    QFile file(fName);

//    if (file.open(QIODevice::ReadOnly))
//    {

//        /* Read and load Sites from file */
//        QDataStream stream(&file);
//        stream >> listOfSites;

//        file.close();
//        qDebug() <<"file closed\n";
//    }
//    else
//    {
//        // TODO add Messagebox
//        qDebug() <<"Failed to load sites from file\n";
//    }


//bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
//{
//    Q_UNUSED(index);

//    Site aSite;
//    beginInsertRows(QModelIndex(), position, position + rows - 1);

//    for (int row = 0; row < rows; ++row)
//        //sites.insert(position, { QString(), QString() }); vad gör denna funktion?
//        sites.insert(position, aSite);

//    endInsertRows();
//    return true;
//}

//bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
//{
//    Q_UNUSED(index);
//    beginRemoveRows(QModelIndex(), position, position + rows - 1);

//    for (int row = 0; row < rows; ++row)
//        sites.removeAt(position);

//    endRemoveRows();
//    return true;
//}

//bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{

//    if (index.isValid() && role == Qt::EditRole) {
//        int row = index.row();

//        auto site = sites.value(row);
//        //TODO fixa resten
//        if (index.column() == 0)
//            site.siteName = value.toString();
//        else if (index.column() == 1)
//            site.siteIpAddress = value.toString();
//        else
//            return false;

//        sites.replace(row, site);
//        emit(dataChanged(index, index));

//        return true;
//    }

//    return false;
//}

//Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid())
//        return Qt::ItemIsEnabled;

//    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
//}

//QList<Site> TableModel::getSites() const
//{
//    return sites;
//}
