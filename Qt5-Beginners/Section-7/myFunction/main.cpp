#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

int calc(int offSet, int age) {
    return offSet * age;
}

int dogYears(int age) {
    return calc(9, age);
}

int catYears(int age) {
    return calc(7, age);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int yourAge;
    qInfo() << "Enter your age: ";
    cin >> yourAge;

    qInfo() << "You are about " << dogYears(yourAge) << " Dog Years old!!" << "\n";
    qInfo() << "You are about " << catYears(yourAge) << " Cat Years old!!";

    // return QCoreApplication::exec();
    return a.exec();
}
