#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <QDebug>
#include <iostream>

using namespace std;

// inserting elements to collection
template<class T>
void fill(T &container){
    for(int i = 0; i < 5; i++)
        container.append(i);
}

template<class T>
void display(T &container) {

    // calculating distance between two locations
    for(int i = 0; i < container.length(); i++) {
        if(i>0) {
            auto current = reinterpret_cast<uintptr_t>(&container.at(i));
            auto previous = reinterpret_cast<uintptr_t>(&container.at(i-1));

            auto distance = current - previous;

            qInfo() << i << "At: " << current << " Previous: " << previous << " Distance: " << distance;
        }
        else {
            qInfo() << &container.at(i) << "Distance: 0";
        }
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vect = QVector<int>();
    QList<int> list = QList<int>();

    fill(vect);
    fill(list);

    qInfo() << "Int takes: " << sizeof(int) << " bytes of RAM!";
    qInfo() << "QVector uses continuous memory location in memory";
    display(vect);
    qInfo("");

    cout << "\n";

    qInfo() << "QList uses heap memory to store items and in random location";
    display(list);
    qInfo("");

    /*
    * QVector will give better performance than QList because QVector always stores its items sequentially in memory
    */

    return QCoreApplication::exec();
}
