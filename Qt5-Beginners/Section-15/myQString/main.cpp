#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString name = "Suman Mondal";

    qInfo() << sizeof(name); // prints pointer size i.e 4 bytes stored in STACK
    qInfo() << name;
    qInfo() << name.mid(0,5);
    qInfo() << name.insert(0, "Mr. ");
    qInfo() << name.split(" ");

    int index = name.indexOf(".");
    qInfo() << name.remove(0, index+1).trimmed();

    QString greet = "Hey,";
    QString sentence = greet + " " + name.trimmed();
    qInfo() << sentence;

    return QCoreApplication::exec();
}
