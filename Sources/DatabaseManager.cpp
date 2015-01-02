#include "../Includes/DatabaseManager.h"
#include "../Includes/DominantColor.h"
#include <QProgressDialog>
#include <QDir>
#include <QTextStream>

// remove me
#include <QMessageBox>

// static
DatabaseManager& DatabaseManager::get()
{
    static DatabaseManager instance;
    return instance;
}

DATABASE_ERRORS DatabaseManager::updateDatabase(QString path, QWidget* widget)
{
    QStringList nameFilter;
    nameFilter << "*.png" << "*.jpeg" << "*.jpg" << "*.bmp";
    QDir directory(path);
    m_filesInDirectory = directory.entryList(nameFilter);

    int numFiles = m_filesInDirectory.size();

    QString filename="database.txt";
    QFile file(filename);
    if (file.exists() && file.open(QIODevice::ReadOnly))
    {
        m_datebaseMap.clear();
        QTextStream stream(&file);
        QString line;
        QStringList lineInList;
        while (!stream.atEnd())
        {
            line = stream.readLine();
            //if (line.isEmpty())
                //break;
            lineInList = line.split('*');
            vector<QColor> dominantColors;
            dominantColors.reserve(8);
            if (lineInList.size() != 25)
            {
                QMessageBox::warning(widget, widget->tr(""), widget->tr("Baza niepoprawna! Zostanie stworzona od nowa!") );
                m_datebaseMap.clear();
                break;
            }
            for (int i = 0; i < 8; ++i)
            {
                int R = lineInList[1+3*i].toInt();
                int G = lineInList[1+3*i+1].toInt();
                int B = lineInList[1+3*i+2].toInt();
                // QString text = QString("R = %1, G = %2, B = %3").arg(QString::number(R),QString::number(G),QString::number(B));
                // QMessageBox::information(widget, widget->tr(""), text );
                dominantColors.push_back(QColor(R,G,B));
            }
            m_datebaseMap.insert(std::make_pair(lineInList[0], dominantColors));
        }
        file.close();
    }

    
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

        map<QString,vector<QColor>>::const_iterator it = m_datebaseMap.find(m_filesInDirectory[i]);
        if (it != m_datebaseMap.end())
            continue; // FIXME moze sprawdz czy sie zgadzaja kolory dominujace dla plikow

        QImage tempImage;
        QString fullFilename = path + m_filesInDirectory[i];
        tempImage.load(fullFilename);

        // QString text = QString("tempImage. name = %3, width() = %1, height() = %2").arg(QString::number(tempImage.width()),QString::number(tempImage.height()),fullFilename);
        // QMessageBox::information(widget, widget->tr(""), text );

        vector<QColor> dominantColors = DominantColors::get().countDominantColors(tempImage);
        m_datebaseMap.insert(std::make_pair(m_filesInDirectory[i], dominantColors));
    }
    progress.setValue(numFiles);

    if (!hasRefreshed)
    {
        m_datebaseMap.clear();
        return RefreshAborted;
    }

    file.remove();

    if (file.open(QIODevice::WriteOnly))
    {
        
        QTextStream stream(&file);
        for (map<QString,vector<QColor>>::iterator it = m_datebaseMap.begin(); it != m_datebaseMap.end(); ++it)
        {
            stream << it->first;
            vector<QColor> dominantColors = it->second;
            int R = 0;
            int G = 0;
            int B = 0;
            for (int i = 0; i < dominantColors.size(); ++i)
            {
                dominantColors[i].getRgb(&R, &G, &B);
                stream << "*" << R << "*" << G << "*" << B;
            }
            stream << endl;
        }
    }


    return Ok;
}