#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double value = 3.999;
    qInfo() << "Double Value: " << value;

    int age = value;
    qInfo() << "Age: " << age; // implicit casting should not be trusted


    age = (int)value; // CASTING OLD STYLE
    qInfo() << "Age: " << age; // explicit casting should be done

    return QCoreApplication::exec();
}
