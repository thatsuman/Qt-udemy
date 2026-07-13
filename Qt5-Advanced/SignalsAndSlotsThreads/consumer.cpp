#include "consumer.h"

Consumer::Consumer(QObject *parent)
    : QObject{parent}
{

    qInfo() << "Created on: " << QThread::currentThread();
    thread.setObjectName("Timer Thread");

    // Qt::AutoConnection - runs on both (default)
    // Qt::QueuedConnection - runs on main thread
    // Qt::DirectConnection - runs on thread
    // Qt::BlockingQueuedConnection - blocks until slot returns
    // Qt::UniqueConnection - combined with others to prevent duplicate connections

    connect(&timer, &Timer::timeout, this, &Consumer::timeout, Qt::QueuedConnection);
    connect(&thread, &QThread::started, &timer, &Timer::started, Qt::QueuedConnection);
    connect(&thread, &QThread::finished, this, &Consumer::finished, Qt::QueuedConnection);
}


void Consumer::start()
{
    qInfo() << "Consumer started on " << QThread::currentThread();
    timer.setInterval(500);
    timer.moveToThread(&thread);
    thread.start();
}

void Consumer::timeout()
{
    qInfo() << "Consumer timeout on " << QThread::currentThread(); 
    thread.quit(); 
}

void Consumer::finished()
{
    qInfo() << "Thread finished on " << QThread::currentThread();
}
