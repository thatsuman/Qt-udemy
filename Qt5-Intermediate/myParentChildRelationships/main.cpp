#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test *p = new test(&a); // should have parent &a
    p->setObjectName("Parent");
    for (int i = 0; i < 5; i++)
        p->makeChild(QString::number(i));

    /*QCoreApplication (a)
            │
            ▼
          Parent (p)
        ┌──┬──┬──┬──┬
        0  1  2  3  4
    */

    delete p; // delete parent p
    p = nullptr;

    return QCoreApplication::exec();
    //return a.exec();
}
