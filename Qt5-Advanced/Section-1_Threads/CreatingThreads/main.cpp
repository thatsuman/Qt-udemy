#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "test.h"
#include <QSharedPointer>
#include <QTimer>


// creating and using threads

static QSharedPointer<QThread> sptr;

void timeout() {
    if(!sptr.isNull()){
        qInfo() << "Timeout stopping other thread from: " << QThread::currentThread();
        sptr->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Application thread:" << a.thread();
    qInfo() << "Creating threads!" << QThread::currentThread();

    test t;
    qInfo() << "Test object thread:" << t.thread();

    QThread thread;
    sptr.reset(&thread);
    t.moveToThread(&thread);
    qInfo() << "Test object thread after move:" << t.thread();

    t.start();

    qInfo() << "Thread state:" << thread.isRunning();
    thread.start();

    QTimer timer;
    timer.singleShot(5000,&timeout);

    

    return QCoreApplication::exec();
}
