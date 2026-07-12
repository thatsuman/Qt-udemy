/*
 * QLinkedList<T> is one of Qt's generic container classes
 * It stores a list of values and provides iterator-based access as well as constant time insertions and removals
 *
 * If you need a real linked list, with guarantees of constant time insertions in the middle
 * of the list and iterators to items rather than indexes , use QLinkedList
 */


#include <QCoreApplication>
#include <QLinkedList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<QString> list;
    list << "one" << "two" << "three" << "four" << "five";

    qInfo() << "Is the list is empty: " << list.isEmpty();
    qInfo() << list.size();

    // Loop through each item in the list automatically
    // To print all the items in a QLinkedList, you should use an iterator or
    // a range-based for loop instead of a regular for loop with an index i
    for (const QString &item : list)
        qInfo() << item;

    return QCoreApplication::exec();
}
