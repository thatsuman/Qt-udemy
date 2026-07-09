#include "test.h"

test::test(QObject *parent)
    : QObject{parent}
{}

void test::useWidget()
{
    // check if there is a pointer
    if(!widget.data()) {
        qInfo() << "No Pointer!!";
        return;
    }

    qInfo() << "Widget = " << widget.data();

    // access the pointer
    widget.data()->setObjectName("used widget!");
}
