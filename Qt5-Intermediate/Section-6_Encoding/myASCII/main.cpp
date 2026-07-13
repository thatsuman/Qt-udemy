#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

QByteArray makeData(){
    QByteArray data;

    for(int i = 0; i < 10; i++){
        data.append(72); // H
        data.append(101); // e
        data.append(108); // l
        data.append(108); // l
        data.append(111); // o
        data.append(33); // !
        data.append(13); // \r
        data.append(10); // \n
    }

    return data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makeData();
    QString path = QDir::currentPath() + QDir::separator() + "data.txt";
    QFile file(path);

    if(file.open(QIODevice::WriteOnly)){
        file.write(data);
        file.close();
    }

    qInfo() << "File Created!";

    return QCoreApplication::exec();
}
