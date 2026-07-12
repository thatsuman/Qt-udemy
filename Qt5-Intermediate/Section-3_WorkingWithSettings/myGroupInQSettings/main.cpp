#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void saveAge(QSettings* setting, QString group, QString name, int age) {
    setting->beginGroup(group);
    setting->setValue(name, age);
    setting->endGroup();

}

int getAge(QSettings* setting, QString group, QString name) {
    setting->beginGroup(group);

    if(!setting->contains(name)) {
        qWarning() << "Does not contain" << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok) {
        qWarning() << "Failed to convert at int!!";
        return 0;
    }
    return value;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Google");
    QCoreApplication::setOrganizationDomain("google.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    // Changing the Org's Name/Domain/AppName will not restore the saved settings
    // Save the setting
    // settings.setValue("test", 123);

    // Read/Load the setting back
    // qInfo() << settings.value("test").toString();
    // qInfo() << settings.value("test").toInt();

    saveAge(&settings,"people","Zeus",44);
    saveAge(&settings,"family","Poseidon",40);
    saveAge(&settings,"family","Zeus",22);

    qInfo() << "Details Poseidon: " << getAge(&settings,"family","Poseidon");
    qInfo() << "Zeus(people): " << getAge(&settings,"people","Zeus");
    qInfo() << "Zeus(family): " << getAge(&settings,"family","Zeus");

    return QCoreApplication::exec();
}
