#include "../Includes/DatabaseManager.h"
#include "../Includes/DominantColor.h"
#include <QProgressDialog>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>


// static
DatabaseManager& DatabaseManager::get()
{
    static DatabaseManager instance;
    return instance;
}

void DatabaseManager::readDatabaseFromFile(QFile& file, QWidget* widget, bool cleanBuild)
{
    if (!cleanBuild && file.exists() && file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        QString line;
        QStringList lineInList;
        while (!stream.atEnd())
        {
            line = stream.readLine();
            lineInList = line.split('*');
            int value = lineInList[0].toInt();
            for (int i = 1; i < lineInList.size(); ++i)
                insertToDatabase(value, lineInList[i]);
        }
        file.close();
    }
}

void DatabaseManager::insertToDatabase(int value, QString filename)
{
    map<int, QStringList>::iterator it = m_datebaseMap.find(value);
    if (it == m_datebaseMap.end()) {
        QStringList list;
        list << filename;
        m_datebaseMap.insert(make_pair(value, list));
        if (!m_databaseMapFilesList.contains(filename))
            m_databaseMapFilesList << filename;
        return;
    }
    if (!it->second.contains(filename))
        it->second << filename;
    if (!m_databaseMapFilesList.contains(filename))
        m_databaseMapFilesList << filename;
}

unsigned DatabaseManager::convertFromRGBToint(int R, int G, int B)
{
    unsigned result = 0;
    int newR = R >> SHIFT_STEP;
    int newG = G >> SHIFT_STEP;
    int newB = B >> SHIFT_STEP;
    
    result = (newR << ((8-SHIFT_STEP)*2)) + (newG << (8 - SHIFT_STEP)) + newB;
    return result;
}

DATABASE_ERRORS DatabaseManager::updateDatabase(QString path, QWidget* widget, bool cleanBuild)
{
    m_datebaseMap.clear();
    m_databaseMapFilesList.clear();
    QStringList emptyList;

    QStringList nameFilter;
    nameFilter << "*.png" << "*.jpeg" << "*.jpg" << "*.bmp";
    QDir directory(path);
    m_filesInDirectory = directory.entryList(nameFilter);
    int numFiles = m_filesInDirectory.size();

    if(!numFiles)
        return DirectoryEmpty;
    
    QFile file(databaseFilename);
    readDatabaseFromFile(file, widget, cleanBuild);

    QProgressDialog progress("Odswiezanie bazy danych...", "Przerwij", 0, numFiles, widget);
    progress.setWindowModality(Qt::WindowModal);

    bool hasRefreshed = true;

    for (int i = 0; i < numFiles; i++) {
        progress.setValue(i);

        if (progress.wasCanceled()) {
            hasRefreshed = false;
            break;
        }

        if (m_databaseMapFilesList.contains(m_filesInDirectory[i]))
            continue;

        QImage tempImage;
        QString fullFilename = path + "\\" + m_filesInDirectory[i];
        tempImage.load(fullFilename);

        vector<QColor> dominantColors = DominantColors::get().countDominantColors(tempImage);
        int R, G, B, value;

        for (int k = 0; k < dominantColors.size(); ++k) {
            dominantColors[k].getRgb(&R, &G, &B);
            value = convertFromRGBToint(R, G, B);
            insertToDatabase(value, m_filesInDirectory[i]);
        }
    }
    progress.setValue(numFiles);

    file.remove();

    if (file.open(QIODevice::WriteOnly)) {
        
        QTextStream stream(&file);
        for (map<int, QStringList>::iterator it = m_datebaseMap.begin(); it != m_datebaseMap.end(); ++it) {
            stream << it->first;
            QStringList files = it->second;
            for (int i = 0; i < files.size(); ++i)
                stream << "*" << files[i];
            stream << endl;
        }
    }
    
    file.close();

    if (!hasRefreshed)
        return RefreshAborted;

    return Ok;
}