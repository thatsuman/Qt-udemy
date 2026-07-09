#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>
#include <QTime>
#include <QDate>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // We use :: because we are asking the main class, not an object
    QDate today = QDate::currentDate();

    qInfo() << today;

    // We use . because "today" is a real object instance
    qInfo() << today.addDays(7);
    qInfo() << today.addYears(1);
    qInfo() << today.toString(Qt::DateFormat::SystemLocaleLongDate);
    qInfo() << today.toString(Qt::DateFormat::SystemLocaleShortDate);
    qInfo() << today.toString(Qt::DateFormat::TextDate);

    QTime now = QTime::currentTime();
    qInfo() << now;
    qInfo() << now.toString(Qt::DateFormat::DefaultLocaleShortDate);
    qInfo() << now.toString(Qt::DateFormat::DefaultLocaleLongDate);

    QDateTime current = QDateTime::currentDateTime();
    qInfo() << "current: " << current.toString(Qt::DateFormat::TextDate);

    QDateTime expire = current.addDays(30);
    qInfo() << "expire: " << expire.toString(Qt::DateFormat::TextDate);

    if (current > expire)
        qInfo() << "EXPIRED!!";
    else
        qInfo() << "Not Expired";

    return QCoreApplication::exec();
}
