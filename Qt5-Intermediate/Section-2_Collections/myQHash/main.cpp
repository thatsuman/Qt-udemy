/*
 * QHash - QHash<Key,T> is one of Qt's generic container class
 * It stores (key, value) pairs and provides very fast lookup of the value associated with a key
 *
 * Works great with static info that wont change much
 */

#include <QCoreApplication>
#include <QHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, int> personAge; // <Key, value> where QString = Key type and int = value type

    personAge.insert("Adam", 26);
    personAge.insert("Apollo", 24);
    personAge.insert("Athena", 25);
    personAge.insert("Zeus", 65);
    personAge.insert("Poseidon", 45);

    qInfo() << "Athena is " << personAge["Athena"] << "years old!";
    qInfo() << "Keys: " << personAge.keys();
    qInfo() << "Items in Hash: " << personAge.size();

    for(QString key: personAge.keys()){
        qInfo() << key << " -> " << personAge[key] << "years old!";
    }

    return QCoreApplication::exec();
}
