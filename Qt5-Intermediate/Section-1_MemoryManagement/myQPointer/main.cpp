/*
* QPointer class is a template class that provides guarded pointers to QObject.
* Remember we might not control the pointer in the consumer class
*/


#include <QCoreApplication>
#include <QDebug>
#include <QPointer>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *obj = new QObject(nullptr);
    obj->setObjectName("My Object");

    QPointer<QObject> p(obj);

    test t;
    t.widget = p;

    // accessed that pointer using useWidget
    t.useWidget();

    if(p.data()) qInfo() << p.data();

    delete obj;
    // after deleting object
    t.useWidget();

    return QCoreApplication::exec();
}
