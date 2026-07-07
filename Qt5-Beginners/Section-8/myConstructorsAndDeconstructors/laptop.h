#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>

class laptop : public QObject
{
    Q_OBJECT
public:
    explicit laptop(QObject *parent = nullptr);

signals:
};

#endif // LAPTOP_H
