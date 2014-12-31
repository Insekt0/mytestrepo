#include "../Includes/DatabaseManager.h"
#include <QProgressDialog>
#include <QDir>



// static
DatabaseManager& DatabaseManager::get()
{
    static DatabaseManager instance;
    return instance;
}

DATABASE_ERRORS DatabaseManager::updateDatabase(string path, QWidget* widget)
{
    QStringList nameFilter;
    nameFilter << "*.png" << "*.jpeg" << "*.jpg" << "*.bmp";
    QDir directory(QString::fromStdString(path));
    QStringList files = directory.entryList(nameFilter);

    int numFiles = files.size();

    QProgressDialog progress("Odswiezanie bazy danych...", "Przerwij", 0, numFiles, widget);
    progress.setWindowModality(Qt::WindowModal);

    bool hasRefreshed = true;

    for (int i = 0; i < numFiles; i++) {
        progress.setValue(i);

        if (progress.wasCanceled())
        {
            hasRefreshed = false;
            break;
        }
         //... copy one file
        // FIXME wpisz pliki, zeby sprawdzic czy dobrze ogarnia sciezke
        // FIXME dodaj wywolanie dominant color dla wszystkich plikow

    }
    progress.setValue(numFiles);


    if (!hasRefreshed)
        return RefreshAborted;

    return Ok;
}