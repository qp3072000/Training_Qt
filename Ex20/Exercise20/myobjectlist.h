#ifndef MYOBJECTLIST_H
#define MYOBJECTLIST_H

#include <QObject>

class MyObjectList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<MyObject*> objects READ objects NOTIFY objectsChanged)
public:
    explicit MyObjectList(QObject *parent = nullptr);
    QList<MyObject*> objects() const;

signals:
    QList<MyObject*> objects() const;

private:
    QList<MyObject*> m_objects;
};

#endif // MYOBJECTLIST_H
