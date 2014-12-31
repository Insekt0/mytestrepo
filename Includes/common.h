#ifndef COMMON_H
#define COMMON_H

enum DATABASE_ERRORS
{
    Ok = 0,
    DirectoryEmpty = 1,
    RefreshAborted = 2
};

#include <string>
const std::string defaultPath = "D://studia//MGR//AIM//projekt//Base//Examples//";

#endif // COMMON_H