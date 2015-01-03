#ifndef COMMON_H
#define COMMON_H

enum DATABASE_ERRORS
{
    Ok = 0,
    DirectoryEmpty = 1,
    RefreshAborted = 2
};

#include <QString>
const QString defaultPath = "D:\\studia\\MGR\\AIM\\projekt\\Base\\Examples\\";
const QString databaseFilename="database.txt";
const int DOMINANTCOLORS_NUMBER = 8;
const int SHIFT_STEP = 5;

#endif // COMMON_H