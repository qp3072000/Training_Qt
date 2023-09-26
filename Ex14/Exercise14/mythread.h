#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QTimer>
#include <QThread>


class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

public slots:
    void doIt();
protected:
    void run() override;
};

#endif // MYTHREAD_H
