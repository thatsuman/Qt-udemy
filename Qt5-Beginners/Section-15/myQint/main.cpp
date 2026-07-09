/* typedef keyword is used to create an alias or alternative name for an existing data type
 *
 *  Type	Size(bytes)	Bits
    qint8	1	           8
    qint16	2	          16
    qint32	4	          32
    qint64	8	          64
    qintptr	4	          32 (on your system)
 *
 *
 *
 */

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qint8 value8 = 0;
    qint16 value16 = 0;
    qint32 value32 = 0;
    qint64 value64 = 0;
    qintptr valueptr = 0;

    qInfo() << "value8: " << sizeof(value8) << "bytes";
    qInfo() << "value16: " << sizeof(value16) << "bytes";
    qInfo() << "value32: " << sizeof(value32) << "bytes";
    qInfo() << "value64: " << sizeof(value64) << "bytes";
    qInfo() << "valueptr: " << sizeof(valueptr) << "bytes";

    return QCoreApplication::exec();
}
