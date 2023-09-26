#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "personmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PersonModel personModel;
    personModel.addPerson("John Doe", "john.doe@example.com");
    personModel.addPerson("Jane Smith", "jane.smith@example.com");
    personModel.addPerson("Bob Johnson", "bob.johnson@example.com");

    engine.rootContext()->setContextProperty("personModel", &personModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
