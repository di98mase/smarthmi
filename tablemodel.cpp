#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
{
   Q_UNUSED(parent);
}

TableModel::TableModel(QList <Site> sites, QObject *parent)
    : QAbstractTableModel(parent)
    , sites(sites)
{

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return sites.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    // TODO...fixa resten
    Q_UNUSED(parent);
    return 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();

    if (index.row() >= sites.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &site = sites.at(index.row());

        if (index.column() == 0)
            return site.siteName;
        else if (index.column() == 1)
            return site.siteIpAddress;
        // TODO...fixa resten
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
                // TODO fixa resten

            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);

    Site aSite;
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        //sites.insert(position, { QString(), QString() }); vad gör denna funktion?
        sites.insert(position, aSite);

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        sites.removeAt(position);

    endRemoveRows();
    return true;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        auto site = sites.value(row);
        //TODO fixa resten
        if (index.column() == 0)
            site.siteName = value.toString();
        else if (index.column() == 1)
            site.siteIpAddress = value.toString();
        else
            return false;

        sites.replace(row, site);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList<Site> TableModel::getSites() const
{
    return sites;
}
