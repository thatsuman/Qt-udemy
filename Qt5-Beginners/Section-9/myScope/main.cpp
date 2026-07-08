#include <QCoreApplication>
#include <QDebug>

// Passing by value
void passVal(int number) {
    // int number = 70;
    qInfo() << "2. Number is at: " << &number << ", Value = " << number;
}

// Passing value by reference(&number)
void passRef(int &number) {
    qInfo() << "4. Number is at: " << &number << ", Value = " << number;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number = 50;
    qInfo() << "1. Number is at: " << &number << ", Value = " << number;

    passVal(number);

    bool ok = true;
    if(ok) {qInfo() << "3. Number is at: " << &number << ", Value = " << number;}

    passRef(number);


    return QCoreApplication::exec();
}
