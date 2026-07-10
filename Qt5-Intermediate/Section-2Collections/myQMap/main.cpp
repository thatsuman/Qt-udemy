#include <QCoreApplication>
#include <QMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> map;

    // one way to insert the the key and values
    map["one"] = 1;
    map["three"] = 3;
    map["seven"] = 7;

    // another way to insert items
    map.insert("twelve", 12);
    map.insert("thirteen", 13);

    qInfo() << "Keys: " << map.keys();

    // looping through map
    for (QString key : map.keys()) {
        qInfo() << key << ":" << map[key];
    }



    return QCoreApplication::exec();
}
