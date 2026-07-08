#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QDebug>

class animal : public QObject
{
    Q_OBJECT
public:
    explicit animal(QString name, QObject *parent = nullptr); // No need to give default param if it stays at first

    QString name;

signals:
};

#endif // ANIMAL_H
