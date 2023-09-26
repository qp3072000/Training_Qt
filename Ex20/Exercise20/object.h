#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Object(QString name, QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // OBJECT_H
