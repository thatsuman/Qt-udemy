#include <QCoreApplication>
#include <QDebug>
#include "appliance.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    appliance myKitchen;
    qInfo() << "Can freeze: " << myKitchen.freeze();
    qInfo() << "Can cook: " << myKitchen.cook();
    qInfo() << "Can grill: " << myKitchen.grill();

    return QCoreApplication::exec();
}
