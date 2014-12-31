#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "common.h"
#include <string>
#include <vector>
#include <QWidget>

using namespace std;

class DatabaseManager {
public:
    static DatabaseManager& get();
    DATABASE_ERRORS updateDatabase(string, QWidget*);
private:
    DatabaseManager() { }
    void checkForFilesInDatabase();
    vector<string> filesInDirectory;
};

#endif // DATABASEMANAGER_H