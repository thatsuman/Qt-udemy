#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include <QSharedDataPointer>
#include "test.h"

class consumer : public QObject
{
    Q_OBJECT
public:
    explicit consumer(QObject *parent = nullptr);

    ~consumer();

    QSharedPointer<test> tester;

signals:
};

#endif // CONSUMER_H
