#include "mylib.h"

Mylib::Mylib() {}

void Mylib::test()
{
    qInfo() << "This is a test message from my shared library!";
}
