#include <QCoreApplication>
#include "test.h"
#include <QTimer>
#include <QSharedPointer>

static QSharedPointer<test> sptr;

void timeout() {
    if(!sptr.isNull()){
        qInfo() << "Timeout stopping thread";
        sptr.data()->quit();
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test thread;
    sptr.reset(&thread);
    thread.start();

    QTimer timer;
    timer.singleShot(5000, &timeout);
    
    

    return QCoreApplication::exec();
}
