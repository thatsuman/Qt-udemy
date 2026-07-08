#include <QCoreApplication>
#include <QDebug>

void foo(QString name) {
    qInfo() << "Name normal way: Size: " << name.length();
}

void fooPtr(QString *name) {
    qInfo() << "Name using Pointer: Size: " << name->length();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "India"; // QString constructor called here

    foo(name);
    fooPtr(&name);

    return QCoreApplication::exec();

    // Destructor called here
}
