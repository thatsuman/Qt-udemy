#include <QCoreApplication>
#include <QDebug>

void display(QString* variable) {
    qInfo() << "The value of pointer: " << variable; // address stored at value
    qInfo() << "The address of pointer: " << &variable << " A copy of the pointer"; // address of the pointer variable
    qInfo() << "The actual value: " << *variable; // actual value at that address
}

/*
void getLength(QString* myStr) {
    qInfo() << "Length: " << myStr->length();
}
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // firstName is a QString stored in STACK
    QString firstName = "Suman";

    // fullName is a pointer object to QString stored in HEAP
    QString* fullName = new QString("SumanMondal");

    // As display() requires address of a QString variable so passing address of firstName
    display(&firstName);

    // fullName itself holds address of a QString variable
    display(fullName);

    //getLength(&firstName);
    //getLength(fullName);

    qInfo() << "Length of First Name: " << firstName.length(); // accessing (.) method using variable
    qInfo() << "Length of Full Name: " << fullName->length(); // accessing (->) method using pointer variable

    // Always delete object created in HEAP
    //When you create something with 'new', it stays in the heap forever until you say otherwise. If you overwrite or lose the pointer, you lose your only map to that memory.
    delete fullName; // Correctly frees the memory
    fullName = nullptr; // // Good practice: stops the pointer from pointing to dead memory

    return QCoreApplication::exec();
}
