#include "mythread.h"
#include <QDebug>

MyThread::MyThread()
{
    QTimer* timer = new QTimer();
    timer->setInterval(1000);

    connect(timer, &QTimer::timeout, this, &MyThread::doIt);

    qDebug() << "Timer started in thread ID: " << QThread::currentThreadId();

    timer->start();
}

void MyThread::doIt()
{
    qDebug() << "Timer fired in thread ID: " << QThread::currentThreadId();
}

void MyThread::run()
{
    qDebug() << "Thread ID in run(): " << QThread::currentThreadId();
}
