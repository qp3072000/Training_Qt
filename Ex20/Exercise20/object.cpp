#include "object.h"

Object::Object(QString name, QObject *parent) : QObject(parent), m_name(name)
{
}

QString Object::name() const
{
    return m_name;
}

void Object::setName(const QString &name)
{
    if (name != m_name)
    {
        m_name = name;
        emit nameChanged();
    }
}
