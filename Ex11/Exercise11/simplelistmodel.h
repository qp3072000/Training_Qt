#ifndef SIMPLELISTMODEL_H
#define SIMPLELISTMODEL_H
#include <QAbstractListModel>

class SimpleListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SimpleListModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void addItem();

private:
    QList<int> m_data;
};

#endif // SIMPLELISTMODEL_H
