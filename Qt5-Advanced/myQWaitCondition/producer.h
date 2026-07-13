#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QRandomGenerator>
#include <QDebug>

class producer : public QObject
{
    Q_OBJECT
public:
    explicit producer(QObject *parent = nullptr);

    void setData(QList<int> data);
    void setMutex(QMutex* mutex);
signals:
    void ready();

public slots:
    void start();

private:
    QList<int> data;
    QMutex* mutex;
};

#endif // PRODUCER_H
