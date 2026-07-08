#include "lion.h"
#include <QDebug>

lion::lion(QObject *parent): animal{parent}
{}

void lion::sound()
{
    qInfo() << "ROAR!!";
    // calling base class function
    animal::sound();
}
