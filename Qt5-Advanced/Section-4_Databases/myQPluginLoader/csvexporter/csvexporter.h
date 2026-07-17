#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <QObject>
#include "../exporterinterface.h"

class CsvExporter : public QObject, public ExporterInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID ExporterInterface_iid)
    Q_INTERFACES(ExporterInterface)

public:
    bool exportContacts(const QList<Contact> &contacts, const QString &filePath) override;
};

#endif