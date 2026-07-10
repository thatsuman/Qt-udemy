/*
 * QSet<T> is one of Qt's generic container classes.
 * It stores values in unspecified(random) order and provides very fast lookup of the values
 */

#include <QCoreApplication>
#include <QSet>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> family;
    family << "Poseidon" << "Zeus" << "Athena" << "Apollo";
    family.insert("Helios");

    for(QString person : family) {
        qInfo() << person; // shows output in random order
    }

    // item lookup in Set
    qInfo() << "Is Zeus in the family: " << family.contains("Zeus");


    return QCoreApplication::exec();
}
