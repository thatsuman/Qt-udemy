#include "laptop.h"

laptop::laptop(QObject *parent, QString name) : QObject{parent}
{
    // When constructor created - "this" is automatically created
    this->name = name; // data member "name" in laptop class = parameter "name" passing through constructor, that's why used "this"

    qInfo() << "Memory Location: " << this << name << "constructed";
}

laptop::~laptop()
{
    // When destroyed

    qInfo() << "Memory Location:  " << this << name << "deconstructed";
}

double laptop::asKilograms()
{
    return this->weight * 0.453592;
}

void laptop::test()
{
    // this is a pointer that'll give us memory location
    // print name variable
    // print asKilograms()
    qInfo() << "Memory Location: " << this << name << "Weight: " << asKilograms();
}
