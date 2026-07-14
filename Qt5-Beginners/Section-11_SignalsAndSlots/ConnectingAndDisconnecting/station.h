// station is a Qt class inheriting from QObject. It acts as a signal emitter in a broadcast simulation, sending messages to connected receivers like a radio.


#ifndef STATION_H
#define STATION_H

#include <QObject>

class station : public QObject
{
    Q_OBJECT
private:
    int channel;
    QString name;
public:
    explicit station(QObject *parent = nullptr, int channel = 0, QString name = "Unknown");

signals:
    void send(int channel, QString name, QString message);

public slots:
    void broadcast(QString message);
};

#endif // STATION_H
