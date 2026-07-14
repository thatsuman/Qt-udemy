#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include "counter.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    counter c;
    QMutex mutex(QMutex::Recursive);


    return a.exec();
}