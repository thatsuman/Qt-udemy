/*

#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

void myTimer(){
    qInfo() << "Thank you for waiting!!";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Please wait for some time...";

    QTimer::singleShot(3000,&myTimer);

    return QCoreApplication::exec();
}

*/


#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

// We keep track of how many seconds have passed
int secondsPassed = 0;
QTimer* myTimer = nullptr;

void updateCountdown() {
    secondsPassed++; // Add 1 second

    if (secondsPassed <= 3) {
        // Print the current second
        qInfo() << secondsPassed << "sec...";
    }

    if (secondsPassed == 3) {
        // Stop the timer and print the final message
        myTimer->stop();
        qInfo() << "Thank you for waiting!!";

        // This closes the console application automatically
        QCoreApplication::quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Please wait for some time...";

    // Create a new repeating timer
    myTimer = new QTimer(&a);

    // Connect the timer to our countdown function
    QObject::connect(myTimer, &QTimer::timeout, &updateCountdown);

    // Tell the timer to tick every 1000 milliseconds (1 second)
    myTimer->start(1000);

    return QCoreApplication::exec();
}
