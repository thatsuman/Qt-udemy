#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Google");
    QCoreApplication::setOrganizationDomain("google.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    // save the setting
    // settings.setValue("test", 123);

    // Read the setting back
    qInfo() << settings.value("test").toString();
    qInfo() << settings.value("test").toInt();

    return QCoreApplication::exec();
}
