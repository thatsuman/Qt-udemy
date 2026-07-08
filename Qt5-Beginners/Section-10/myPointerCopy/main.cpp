#include <QCoreApplication>
#include <QDebug>

void printData(QString* val) {
    qInfo() << *val;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString* data = new QString("sdfjsdfsjdfjlsdjfksdfheijsdfjoisehfjkgiuwejiorsojvhsdsdfjkdsfjwieihvjksjlfkwpejirwejfshdfhsldfsdfjsdfhsudgfksdf");

    qInfo() << "Data Length: " << data->length();
    qInfo() << "Pointer Size: " << sizeof(data);
    qInfo() << "Actual Data: " << *data;
    qInfo() << "Actual Data Size: " << sizeof(*data);

    // passing through pointer rather than copying
    printData(data);

    // delete object in HEAP
    delete data;
    data = nullptr;

    return QCoreApplication::exec();
}
