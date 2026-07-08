#include "fenine.h"

fenine::fenine(QObject *parent): mammal{parent}
{
    qInfo() << this << "constructed";
}
