#include "test.h"

test::test(QObject *parent) : QObject{parent}
{
    qInfo() << this << "Constructed";
}

test::~test()
{
    qInfo() << this << "Destructed";
}

void test::makeChild(QString name)
{
    test* child = new test(this);
    child->setObjectName(name);
}









