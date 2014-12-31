#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "common.h"
#include <string>
#include <vector>

using namespace std;

const string defaultPath = "D://studia//MGR//AIM//projekt//Base//Examples//";

class DatabaseManager {
public:
    static DatabaseManager& get();
    void updateDatabase(string path = defaultPath);
private:
    DatabaseManager() { }
    void checkForFilesInDatabase();
    vector<string> filesInDirectory;
};

#endif // DATABASEMANAGER_H