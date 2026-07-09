#include "source.h"

source::source(QObject *parent)
    : QObject{parent}
{

}

void source::test()
{
    // emitting the message as signal
    emit mySignal("Hello world");
}
