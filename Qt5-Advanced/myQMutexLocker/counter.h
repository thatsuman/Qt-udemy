#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class counter : public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);

    void increment();
    void decrement();
    int counter();

signals:

private:
    int value = 0;
};

#endif // COUNTER_H
