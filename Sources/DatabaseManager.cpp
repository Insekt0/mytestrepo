#include "../Includes/DatabaseManager.h"

// static
DatabaseManager& DatabaseManager::get()
{
    static DatabaseManager instance;
    return instance;
}