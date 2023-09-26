#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include "myobject.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Tạo danh sách các đối tượng MyObject
    QList<QObject*> objectList;
    objectList.append(new MyObject("Item 1"));
    objectList.append(new MyObject("Item 2"));
    objectList.append(new MyObject("Item 3"));

    // Đưa danh sách đối tượng vào QML
    engine.rootContext()->setContextProperty("myObjectList", QVariant::fromValue(objectList));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
