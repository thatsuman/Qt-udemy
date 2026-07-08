#include "animal.h"

animal::animal(QString name, QObject *parent): QObject{parent}
{
    this->name = name;
    qInfo() << "Animal name param: " << name << " = " << &name;
    qInfo() << "Animal name: " << this->name << " = " << &this->name;
}
