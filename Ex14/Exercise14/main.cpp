#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "mythread.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    qDebug() << "Main thread ID: " << QThread::currentThreadId();

    // Tạo và bắt đầu một đối tượng MyThread trong một thread riêng biệt.
    MyThread t;
    t.start();

    // QTimer vẫn nằm trong main thread, không cần phải kết nối nó với thread của MyThread.
    QTimer mainTimer;
    mainTimer.setInterval(2000);
    mainTimer.start();

    QObject::connect(&mainTimer, &QTimer::timeout, []() {
        qDebug() << "Main timer fired in thread ID:" << QThread::currentThreadId();
    });

    return app.exec();
}
