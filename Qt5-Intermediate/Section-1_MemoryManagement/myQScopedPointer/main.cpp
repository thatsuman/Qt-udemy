/*
    QScopedPointer class stores a pointer to a dynamically allocated object, and deletes it upon destruction!!
*/


#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include "test.h"

void useIt(test* obj) {
    if(!obj) return;

    qInfo() << "Using" << obj;
}

void doStuff() {
    // test *t = new test(); <- DO NOT DO THIS WAY!! creates dangling pointer
    QScopedArrayPointer<test> myPointer(new test());

    useIt(myPointer.data());
    // pointer is automatically deleted!!
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int i = 0; i < 10; i++) {
        doStuff();
    }


    return QCoreApplication::exec();
}
