#ifndef LION_H
#define LION_H

#include "animal.h"
#include <QObject>

class lion : public animal
{
    Q_OBJECT
public:
    explicit lion(QObject *parent = nullptr);

    void sound();

signals:
};

#endif // LION_H
