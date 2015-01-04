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
    map<int, QStringList>& getDatabase() { return m_datebaseMap; }
    QStringList& getDatabaseFilesList() { return m_databaseMapFilesList; }
    void readDatabaseFromFile(QFile& file, QWidget* widget, bool cleanBuild = false);
    unsigned convertFromRGBToint(int R, int G, int B);

private:
    DatabaseManager() { }
    void checkForFilesInDatabase();
    void insertToDatabase(int value, QString filename);
    QStringList m_filesInDirectory;
    map<int, QStringList> m_datebaseMap;
    QStringList m_databaseMapFilesList;
};

#endif // DATABASEMANAGER_H