#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QDateTime>

// exploring the main thread - threads control the execution, think of a thread as "time on the CPU"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "App Thread: " << a.thread(); //Which thread owns this object? -> pointer to a QThread
    qInfo() << "Current Thread: " << QThread::currentThread(); // Which thread is currently executing this line of code?

    Q_ASSERT((a.thread()) == QThread::currentThread());

    qInfo() << "Running: " << QThread::currentThread()->isRunning(); // Is this thread active? true means main thread is running
    qInfo() << "LoopLevel: " << QThread::currentThread()->loopLevel(); // Returns how many nested event loops are running.
    qInfo() << "StackSize: " << QThread::currentThread()->stackSize(); // Returns configured stack size
    qInfo() << "Finished: " << QThread::currentThread()->isFinished(); // Current thread finished?
    qInfo() << "Before: " << QDateTime::currentDateTime().toString(); // Prints current date and time
    QThread::sleep(10); // Stops this thread for x secs
    qInfo() << "After: " << QDateTime::currentDateTime().toString(); // Prints current date and time


    return a.exec();
}
