#include "animal.h"
#include <QDebug>

animal::animal(QObject *parent): QObject{parent}
{}

void animal::sound()
{
    qInfo() << "Any animal can speak";
}
