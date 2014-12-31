#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "common.h"
#include "CImg.h"
#include <string>

using namespace std;

class FileManager {
public:
    static FileManager& get();
    CImage loadImageFromFile(string& path);
private:
    FileManager() {}
};


#endif // FILEMANAGER_H