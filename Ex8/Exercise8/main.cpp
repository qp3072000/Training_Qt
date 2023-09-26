#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQmlContext>
#include <QDebug>

class SignalEmitter : public QObject {
    Q_OBJECT
public:
    SignalEmitter() {}
signals:
    void mySignal();
};

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SignalEmitter signalEmitter;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    SignalEmitter signalEmitter;
    engine.rootContext()->setContextProperty("signalEmitter", &signalEmitter);

    //Emit signals from C++
    QTimer::singleShot(2000, &signalEmitter, SIGNAL(mySignal()));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#include"main.moc"
