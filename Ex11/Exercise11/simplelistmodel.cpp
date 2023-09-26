#include "simplelistmodel.h"

SimpleListModel::SimpleListModel(QObject *parent) : QAbstractListModel(parent)
{

}

int SimpleListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return m_data.count();

}

QVariant SimpleListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row() >= m_data.count())
        return QVariant();
    if(role == Qt::DisplayRole)
        return m_data[index.row()];
    return QVariant();

}

void SimpleListModel::addItem()
{
    int nextValue = m_data.isEmpty() ? 1 : m_data.last() +1;
    int row = rowCount();
    beginInsertRows(QModelIndex(), row, row);
    m_data.append(nextValue);
    endInsertRows();

}
