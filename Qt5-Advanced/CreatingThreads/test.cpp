#include "test.h"
#include <QThread>

test::test(QObject *parent)
    : QObject{parent}
{

}

void test::start()
{
    qInfo() << QDateTime::currentDateTime().toString() << " on " << QThread::currentThread();
}

void test::timeout()
{
    connect(&timer, &QTimer::timeout, this, &test::timeout);
    timer.setInterval(1000);
    timer.start();
}
