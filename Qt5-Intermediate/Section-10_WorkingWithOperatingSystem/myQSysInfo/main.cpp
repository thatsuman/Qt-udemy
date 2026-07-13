#include <QCoreApplication>
#include <QSysInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System Information: ";
    qInfo() << "Machine Host Name: " << sys.machineHostName();
    qInfo() << "Product Name: " << sys.prettyProductName();
    qInfo() << "CPU Architecture: " << sys.buildCpuArchitecture();
    qInfo() << "Current CPU Architecture: " << sys.currentCpuArchitecture();
    qInfo() << "Boot Id: " << sys.bootUniqueId();
    qInfo() << "Kernel Type: " << sys.kernelType();
    qInfo() << "Kernel Version: " << sys.kernelVersion();

    return QCoreApplication::exec();
}
