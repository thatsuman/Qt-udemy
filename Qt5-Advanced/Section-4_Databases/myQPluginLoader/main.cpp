#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPluginLoader>
#include <QDir>
#include "contact.h"
#include "exporterinterface.h"

bool setupDatabase(QSqlDatabase &db)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contacts.db");

    if (!db.open()) {
        qWarning() << "Failed to open DB:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "name TEXT NOT NULL, "
                "phone TEXT)");
    return true;
}

void insertContact(const QString &name, const QString &phone)
{
    QSqlQuery query;
    query.prepare("INSERT INTO contacts (name, phone) VALUES (:name, :phone)");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    if (!query.exec())
        qWarning() << "Insert failed:" << query.lastError().text();
}

Contact contactFromQuery(const QSqlQuery &q) {
    Contact c;
    c.id = q.value("id").toInt();
    c.name = q.value("name").toString();
    c.phone = q.value("phone").toString();
    return c;
}

QList<Contact> readContacts()
{
    QList<Contact> contacts;
    QSqlQuery query("SELECT id, name, phone FROM contacts");
    while (query.next())
        contacts.append(contactFromQuery(query));
    return contacts;
}

ExporterInterface* loadExporterPlugin()
{
    QStringList searchPaths = {
        QCoreApplication::applicationDirPath(),
        QCoreApplication::applicationDirPath() + "/plugins",
        QCoreApplication::applicationDirPath() + "/../plugins",
        QCoreApplication::applicationDirPath() + "/../../plugins",
        QCoreApplication::applicationDirPath() + "/../../../plugins",
        QCoreApplication::applicationDirPath() + "/../../../../plugins",
        QDir::currentPath(),
        QDir::currentPath() + "/plugins"
    };

    for (const QString &path : searchPaths) {
        QDir pluginsDir(path);
        if (!pluginsDir.exists())
            continue;

        QStringList filters;
#if defined(Q_OS_WIN)
        filters << "*.dll";
#elif defined(Q_OS_OSX)
        filters << "*.dylib";
#else
        filters << "*.so";
#endif

        for (const QString &fileName : pluginsDir.entryList(filters, QDir::Files)) {
            QString absolutePath = pluginsDir.absoluteFilePath(fileName);
            QPluginLoader loader(absolutePath);
            QObject *plugin = loader.instance();
            if (plugin) {
                ExporterInterface *exporter = qobject_cast<ExporterInterface*>(plugin);
                if (exporter) {
                    qDebug() << "Loaded plugin:" << absolutePath;
                    return exporter;
                }
            } else {
                qDebug() << "Failed to load" << absolutePath << ":" << loader.errorString();
            }
        }
    }
    return nullptr;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db;
    if (!setupDatabase(db))
        return 1;

    insertContact("Alice", "111-222-3333");
    insertContact("Bob", "444-555-6666");

    QList<Contact> contacts = readContacts();
    qDebug() << "---- Contacts in DB ----";
    for (const Contact &c : contacts)
        qDebug() << c.id << c.name << c.phone;

    ExporterInterface *exporter = loadExporterPlugin();
    if (exporter) {
        exporter->exportContacts(contacts, "contacts_export.csv");
        qDebug() << "Exported via plugin.";
    } else {
        qDebug() << "No exporter plugin found (this is fine, DB part still works).";
    }

    return 0;
}