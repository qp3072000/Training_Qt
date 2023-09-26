#include "myobject.h"

MyObject::MyObject(const QString& name, QObject* parent)
    : QObject(parent), m_name(name)
{
}

QString MyObject::name() const
{
    return m_name;
}

void MyObject::setName(const QString& name)
{
    if (m_name != name)
    {
        m_name = name;
        emit nameChanged();
    }
}
