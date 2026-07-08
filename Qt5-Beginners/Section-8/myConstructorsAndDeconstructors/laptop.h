#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>
#include <QDebug>

class laptop : public QObject
{
    Q_OBJECT
public:
    QString name;
    int weight;
    double asKilograms();
    void test();

    // ------------------------Constructor-------------------------
    // passing default argument null pointer in parameter parent
    // passing default argument "" in parameter name
    explicit laptop(QObject *parent = nullptr, QString name = "");

    // ------------------------Destructor------------------------
    ~laptop();

signals:
};

#endif // LAPTOP_H
