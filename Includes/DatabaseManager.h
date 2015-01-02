#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "common.h"
#include <map>
#include <string>
#include <vector>
#include <QWidget>

using namespace std;

class DatabaseManager {
public:
    static DatabaseManager& get();
    DATABASE_ERRORS updateDatabase(QString, QWidget*);
    map<QString,vector<QColor>> getDatabase() const { return m_datebaseMap; }
private:
    DatabaseManager() { }
    void checkForFilesInDatabase();
    QStringList m_filesInDirectory;
    map<QString,vector<QColor>> m_datebaseMap;
};

#endif // DATABASEMANAGER_H