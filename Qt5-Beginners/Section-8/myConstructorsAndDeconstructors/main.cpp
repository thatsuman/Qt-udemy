#include <QCoreApplication>
#include "laptop.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // constructor requires nullpointer so passing 0 or NULL anything works
    laptop mine(0,"Lenovo LOQ");
    laptop yours(NULL, "ASUS ROG");

    mine.weight = 3;
    yours.weight = 5;


    mine.test();
    yours.test();

    return 0;
    // Stack (LIFO) will delete varibles here that's why destructor will be in reverse order
}
