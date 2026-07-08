#include "animal.h"

animal::animal(QObject *parent, QString name) : QObject{parent}
{
    this->name = name;
    qInfo() << name;
}

