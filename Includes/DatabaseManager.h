#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "common.h"
#include <map>
#include <string>
#include <vector>
#include <QFile>
#include <QWidget>

using namespace std;

class DatabaseManager {
public:
    static DatabaseManager& get();
    DATABASE_ERRORS updateDatabase(QString, QWidget*, bool cleanBuild = false);
    map<QString,vector<QColor>>& getDatabase() { return m_datebaseMap; }
    void readDatabaseFromFile(QFile& file, QWidget* widget, bool cleanBuild = false);
private:
    DatabaseManager() { }
    void checkForFilesInDatabase();
    QStringList m_filesInDirectory;
    map<QString,vector<QColor>> m_datebaseMap;
};

#endif // DATABASEMANAGER_H