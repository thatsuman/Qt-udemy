#include <QCoreApplication>
#include "animal.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "Jake";
    qInfo() << "My name is: " << name << " = " << &name;

    animal cat("fluffy", &a);
    animal dog("tommy", &a);
    animal human(name,&a);

    return QCoreApplication::exec();
}
