#include <QCoreApplication>
#include <QDebug>
#include "cat.h"
#include "dog.h"

void printObj(QObject* obj) {
    //qInfo() << obj; // Prints the QObject itself

    /*
        qInfo() << obj->objectName();          // "fluffy"
        qInfo() << obj->parent();              // Parent object
        qInfo() << obj->children();            // List of child objects
        qInfo() << obj->metaObject()->className(); // "cat"
    */
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // creating objects
    cat kitty;
    dog puppy;

    // setting names of each objects
    kitty.setObjectName("fluffy");
    puppy.setObjectName("jackie");

    // passing object reference to the function
    printObj(&kitty);
    printObj(&puppy);


    return QCoreApplication::exec();
}
