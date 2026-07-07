#include <QCoreApplication>
#include <QDebug>

void myFoo(int age) { // should be function name: printAge()
    qInfo() << "Your age is: " << age;
}

void myFoo(bool isActive) { // should be function name: isActive()
    qInfo() << "Checking is it active: " ;

    if(isActive)
        qInfo() << "Active";
    else
        qInfo() << "Not Active";
}

void printNum(int value) {
    qInfo() << "Do something with integer value";
    qInfo() << "Integer: " << value;
}

void printNum(double value) {
    qInfo() << "Do something with double value";
    qInfo() << "Double: " << value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "----------Entering main func----------";
    qInfo() << "Hello from main function";
    qInfo() << "----------Leaving main func----------";

    // myFoo(29);
    // myFoo(false);

    printNum(63);
    printNum(63.1);


    return QCoreApplication::exec();
}
