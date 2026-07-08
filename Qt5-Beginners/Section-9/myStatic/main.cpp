#include <QCoreApplication>
#include <QDebug>

// Global scope - DO NOT USE!!
static QString name = "Suman";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    name = "Jane";
    qInfo() << name;

    bool ok = true;
    if(ok) {
        QString name = "Daniel";
        qInfo() << name;
    }
    qInfo() << name;

    return QCoreApplication::exec();
}
