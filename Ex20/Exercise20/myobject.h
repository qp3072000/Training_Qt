#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    MyObject(const QString& name, QObject* parent = nullptr);

    QString name() const;
    void setName(const QString& name);

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // MYOBJECT_H
