#include <QCoreApplication>
#include <QDebug>

// Pass by Value - Passing the copy of the object
void fooPassByValue(int val) {
    qInfo() << "Inside Function: ";
    val += 10;
    qInfo() << "Val: " << val;
}

// Pass by Reference - Passing the actual object
void fooPassByRef(int &val) {
    qInfo() << "Inside Function: ";
    val *= 10;
    qInfo() << "Val: " << val;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int val = 5;

    // Testing pass by value
    qInfo() << "------Testing Pass by Value------";
    qInfo() << "Before Function call: " << val;
    fooPassByValue(val);
    qInfo() << "After Function call: " << val;

    // Testing pass by reference
    qInfo() << "------Testing Pass by Reference------";
    qInfo() << "Before Function call: " << val;
    fooPassByRef(val);
    qInfo() << "After Function call: " << val;

    return QCoreApplication::exec();
}
