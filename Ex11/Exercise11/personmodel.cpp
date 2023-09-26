#include "personmodel.h"

PersonModel::PersonModel(QObject *parent) : QAbstractListModel(parent)
{

}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()) {
        return 0;
    }
    return m_people.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row() >= m_people.size())
        return QVariant();

    const Person& person = m_people.at(index.row());

    if(role == Qt::DisplayRole)
        return person.name;
    else if (role == Qt::UserRole)
        return person.email;

    return QVariant();
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "name";
    roles[Qt::UserRole] = "email";

    return roles;
}

void PersonModel::addPerson(const QString &name, const QString &email)
{
    int newIndex = rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), newIndex, newIndex);
    m_people.append({name, email});
    endInsertRows();

}
