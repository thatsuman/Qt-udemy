#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
#include "station.h"
#include "radio.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    radio boombox;
    // an array of pointers to station objects is declared to manage multiple channels.
    station* channel[3];

    // create some stations
    channel[0] = new station(&boombox, 34, "Rock and Roll");
    channel[1] = new station(&boombox, 45, "Jazz");
    channel[2] = new station(&boombox, 56, "Classical");

    QObject::connect(&boombox, &radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    QTextStream qtin(stdin);

    while(true){
        qInfo("Enter on, off, test or quit: ");

        QString line = qtin.readLine().trimmed().toUpper();

        // Break if stream fails or reaches End-of-File (EOF)
        if (line.isNull()) {
            qInfo() << "Input stream closed. Exiting loop.";
            break;
        }

        line = line.trimmed().toUpper();


        if(line == "ON"){
            qInfo() << "Radio is on";
            for(int i = 0; i < 3; i++){
                station* st = channel[i];
                boombox.connect(st,&station::send,&boombox,&radio::listen);
            }
        }

        else if(line=="OFF"){
            qInfo() << "Radion is Off";
            for(int i = 0; i < 3; i++){
                station* st = channel[i];
                boombox.disconnect(st,&station::send,&boombox,&radio::listen);
            }
        }
        else if(line == "TEST")
            qInfo() << "Radio is testing";

        else if(line == "QUIT"){
            qInfo() << "Radio is quitting";
            break; // quits the loop
        }
    }


    return QCoreApplication::exec();
}
