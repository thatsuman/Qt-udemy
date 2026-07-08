#include <QCoreApplication>
#include "animal.h"

// Global memory
QString animal::name = "";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    animal dog(&a, "kitty");


    return QCoreApplication::exec();
}
