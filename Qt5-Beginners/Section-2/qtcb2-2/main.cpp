#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Hello world";
    qInfo("Hello again!");
    return QCoreApplication::exec();
}
