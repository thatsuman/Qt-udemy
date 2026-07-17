#include "csvexporter.h"
#include <QFile>
#include <QTextStream>

bool CsvExporter::exportContacts(const QList<Contact> &contacts, const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "id,name,phone\n";
    for (const Contact &c : contacts)
        out << c.id << "," << c.name << "," << c.phone << "\n";

    file.close();
    return true;
}