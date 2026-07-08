#include <QCoreApplication>
#include "fenine.h"
#include "canine.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Inheritance hierarchy:
    // Animal -> Mammal -> Canine and Fenine
    animal anyAnimal;

    fenine kitten;
    canine puppy;

    return QCoreApplication::exec();
}
