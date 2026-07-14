#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>

class radio : public QObject
{
    Q_OBJECT
public:
    explicit radio(QObject *parent = nullptr);

signals:
    void quit();

public slots:
    // Slot to handle incoming messages from stations
    
    // void send(int channel, QString name, QString message); 
    // This is the signal that will be emitted by the station and number of arguments will be same as the arguments of the slot
    void listen(int channel, QString name, QString message);

};

#endif // RADIO_H
