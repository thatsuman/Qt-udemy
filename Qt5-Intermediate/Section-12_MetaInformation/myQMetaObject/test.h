#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void doStuff();
    void doStuff(QString param);

signals:
    void mySignal();

public slots:
    void mySlot();
};

#endif // TEST_H
