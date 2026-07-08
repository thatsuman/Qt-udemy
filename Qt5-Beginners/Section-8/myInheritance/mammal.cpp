#include "mammal.h"

mammal::mammal(QObject *parent): animal{parent} // Inherits animal
{
    qInfo() << this << "constructed";
}
