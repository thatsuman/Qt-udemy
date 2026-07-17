#ifndef EXPORTERINTERFACE_H
#define EXPORTERINTERFACE_H

#include <QString>
#include <QList>
#include <QtPlugin>
#include "contact.h"

class ExporterInterface {
    public:
        virtual ~ExporterInterface() {}
        virtual bool exportContacts(const QList<Contact> &contacts, const QString &filePath) = 0;    
};

#define ExporterInterface_iid "com.example.ExporterInterface"
Q_DECLARE_INTERFACE(ExporterInterface, ExporterInterface_iid)


#endif // EXPORTERINTERFACE_H
