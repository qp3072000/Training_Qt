#ifndef PERSONMODEL_H
#define PERSONMODEL_H
#include <QAbstractListModel>
#include <QObject>

//Inheritance
class PersonModel : public QAbstractListModel
{
public:
    explicit PersonModel(QObject* parent = nullptr); //Constructor

    //Abstract Methods (Abstraction)
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QHash<int, QByteArray> roleNames() const; //Template class - Hash table QHash<Key, T>

    void addPerson(const QString& name, const QString& email);

private:
    struct Person
    {
        QString name;
        QString email;
    };

    QList<Person> m_people;//Encapsulation
};

#endif // PERSONMODEL_H
