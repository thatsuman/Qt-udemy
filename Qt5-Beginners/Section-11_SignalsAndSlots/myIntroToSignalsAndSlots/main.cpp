#include <QCoreApplication>
#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // creating objects
    source objSource;
    destination objDestination;

    // connecting signals and slots
    // connect(sender,signal,receiver,slot)
    // Syntax: QObject::connect(sender, &SenderClass::signalName, receiver, &ReceiverClass::slotName);

    QObject::connect(&objSource,&source::mySignal,&objDestination,&destination::onMessage);

    objSource.test();

    return QCoreApplication::exec();
}
