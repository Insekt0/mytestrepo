#include "aim.h"
#include "../../../Includes/DominantColor.h"
#include "../../../Includes/DatabaseManager.h"
#include <algorithm>
#include <QFileDialog>
#include <QMessageBox>

AIM::AIM(QWidget *parent)
    : QMainWindow(parent)
    , m_mainPictureScene(0)
    , m_mainImage(0)
    , m_pathToDatabase(defaultPath)
    , m_cleanAndRebuildFlag(false)
    , m_hasChangedMainImage(false)
{
    for (int i = 0; i < 8; ++i) {
        m_dominantColorsScene[i] = 0;
        m_picturesScene[i] = 0;
    }
    m_ui.setupUi(this);
    moveCellsIntoTables();
    QObject::connect(m_ui.startButton, SIGNAL(clicked()),this, SLOT(startButtonClicked()));
    QObject::connect(m_ui.loadButton, SIGNAL(clicked()), this, SLOT(loadImageButtonClicked()));
    QObject::connect(m_ui.refreshDatabase,  SIGNAL(clicked()), this, SLOT(refreshDatabaseButtonClicked()));
    QObject::connect(m_ui.baseDirField, SIGNAL(textChanged(const QString &)),this, SLOT(pathToDatabaseChanged(const QString &)));
    QObject::connect(m_ui.cleanAndRebuildDatabase, SIGNAL(toggled(bool)),this, SLOT(setCleanAndRebuildFlag(bool)));

    m_ui.baseDirField->setText(QApplication::translate("AIMClass", defaultPath.toUtf8().constData(), 0));
}

AIM::~AIM()
{
    for (int i = 0; i < 8; ++i) {
        if (m_dominantColorsScene[i])
            delete m_dominantColorsScene[i];
        if (m_picturesScene[i])
            delete m_picturesScene[i];
    }
    if (m_mainPictureScene)
        delete m_mainPictureScene;
    if (m_mainImage)
        delete m_mainImage;
}

void AIM::moveCellsIntoTables()
{
    m_pictures[0] = m_ui.picture1;
    m_pictures[1] = m_ui.picture2;
    m_pictures[2] = m_ui.picture3;
    m_pictures[3] = m_ui.picture4;
    m_pictures[4] = m_ui.picture5;
    m_pictures[5] = m_ui.picture6;
    m_pictures[6] = m_ui.picture7;
    m_pictures[7] = m_ui.picture8;

    m_labels[0] = m_ui.text1;
    m_labels[1] = m_ui.text2;
    m_labels[2] = m_ui.text3;
    m_labels[3] = m_ui.text4;
    m_labels[4] = m_ui.text5;
    m_labels[5] = m_ui.text6;
    m_labels[6] = m_ui.text7;
    m_labels[7] = m_ui.text8;
    
    m_dominantColors[0] = m_ui.dominant1;
    m_dominantColors[1] = m_ui.dominant2;
    m_dominantColors[2] = m_ui.dominant3;
    m_dominantColors[3] = m_ui.dominant4;
    m_dominantColors[4] = m_ui.dominant5;
    m_dominantColors[5] = m_ui.dominant6;
    m_dominantColors[6] = m_ui.dominant7;
    m_dominantColors[7] = m_ui.dominant8;
}

void AIM::refreshDatabaseButtonClicked()
{
    switch (DatabaseManager::get().updateDatabase(m_pathToDatabase, this, m_cleanAndRebuildFlag)) {
    case Ok:    
        QMessageBox::information(this, tr(""), tr("Baza zostala zaktualizowana") );
        break;
    case DirectoryEmpty:
        QMessageBox::warning(this, tr(""), tr("Katalog z baza danych nie zawiera obrazkow! Wskaz inny katalog!") );
        break;
    case RefreshAborted:
        QMessageBox::warning(this, tr(""), tr("Odswiezanie zostalo przerwane!") );
        break;
    default:
        QMessageBox::critical(this, tr(""), tr("Niezidentyfikowany blad!") );
    }
}

struct sortStruct
{
    bool operator()(int value1, int value2) const { return value1 > value2; }
};

void AIM::startButtonClicked()
{

    if (!m_mainImage) {
        QString text = QString("Nie wybrano obrazka!");
        QMessageBox::warning(this, tr(""), text);
        return;
    }

    QStringList nameFilter;
    nameFilter << "*.png" << "*.jpeg" << "*.jpg" << "*.bmp";
    QDir directory(m_pathToDatabase);
    QStringList filesInDirectory = directory.entryList(nameFilter);
    int numFiles = filesInDirectory.size();

    if(!numFiles) {
        QString text = QString("Katalog z baza danych nie zawiera obrazkow! Wskaz inny katalog!");
        QMessageBox::warning(this, tr(""), text);
        return;
    }

    if(m_hasChangedMainImage) {
        for (int i = 0; i < DOMINANTCOLORS_NUMBER; ++i) {
            if (m_dominantColorsScene[i])
                delete m_dominantColorsScene[i];
            m_dominantColorsScene[i] = new QGraphicsScene(m_dominantColors[i]);
        }
        m_mainImageDominantColors = DominantColors::get().countDominantColors(*m_mainImage);

        int dominantWindowWidth = m_dominantColors[0]->width();
        int dominantWindowHeight = m_dominantColors[0]->height();

        for (int i = 0; i < DOMINANTCOLORS_NUMBER; ++i) {
            QPixmap pixmap(dominantWindowWidth, dominantWindowHeight);
            pixmap.fill(m_mainImageDominantColors[i]);
            m_dominantColorsScene[i]->addPixmap(pixmap);
            m_dominantColors[i]->setScene(m_dominantColorsScene[i]);
        }
        m_hasChangedMainImage = false;
    }

    QFile file(databaseFilename);
    DatabaseManager::get().readDatabaseFromFile(file, this);

    if (DatabaseManager::get().getDatabase().empty()) {
        QString text = QString("Baza danych pusta! Odœwie¿ bazê danych!");
        QMessageBox::warning(this, tr(""), text);
        return;
    }

    map<QString, int> matchMapTemp;
    map<QString, int>::iterator matchMapTempIterator;
    multimap<int, QString, sortStruct> matchMap;
    multimap<int, QString>::iterator matchMapIterator;


    int matches = 0;
    int value, R, G, B;
    map<int, QStringList> databaseMap = DatabaseManager::get().getDatabase();
    map<int, QStringList>::iterator it;
    for (int i = 0; i < m_mainImageDominantColors.size(); ++i) {
        m_mainImageDominantColors[i].getRgb(&R, &G, &B);
        value = DatabaseManager::get().convertFromRGBToint(R, G, B);
        it = databaseMap.find(value);
        
        if (it == databaseMap.end())
            continue;

        QStringList filesWithMatchingDominantColor = it->second;
        for (int k = 0; k < filesWithMatchingDominantColor.size(); ++k)
            matchMapTemp[filesWithMatchingDominantColor[k]] += 1;
    }

    for (matchMapTempIterator = matchMapTemp.begin(); matchMapTempIterator != matchMapTemp.end(); ++matchMapTempIterator)
        matchMap.insert(make_pair(matchMapTempIterator->second, matchMapTempIterator->first));

    int numberOfImages = 0;

    for (matchMapIterator = matchMap.begin(); matchMapIterator != matchMap.end(); ++matchMapIterator) {
        if(numberOfImages == 8)
            break;
        QString filename = m_pathToDatabase + "\\" + matchMapIterator->second;
        QFile file(filename);
        if (!file.exists())
            continue;
        
        QImage image;
        image.load(filename);
        int width = m_pictures[numberOfImages]->width();
        int height = m_pictures[numberOfImages]->height();
        QPixmap pixmap = image.width() > image.height() ? QPixmap::fromImage(image).scaledToWidth(width-2) : QPixmap::fromImage(image).scaledToHeight(height-2);

        if (m_picturesScene[numberOfImages])
           delete m_picturesScene[numberOfImages];
        m_picturesScene[numberOfImages] = new QGraphicsScene(m_pictures[numberOfImages]);
        QString text = matchMapIterator->second + " [" + QString::number(matchMapIterator->first) + "]";
        m_labels[numberOfImages]->setText(text);
        m_picturesScene[numberOfImages]->addPixmap(pixmap);
        m_pictures[numberOfImages]->setScene(m_picturesScene[numberOfImages]);
        ++numberOfImages;
    }
}

void AIM::loadImageButtonClicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Otw\303\263rz plik z obrazem"), ".", tr("JPEG (*.jpg;*.jpeg);; PNG (*.png);; BMP (*.bmp)"));
    if (!filename.isEmpty()) {
        if (m_mainPictureScene)
            delete m_mainPictureScene;
        if (!m_mainImage)
            m_mainImage = new QImage();
        m_hasChangedMainImage = true;

        for (int i = 0; i < 8; ++i) {
            if (m_picturesScene[i])
                m_picturesScene[i]->clear();
            if (m_labels[i])
                m_labels[i]->clear();
            if (m_dominantColorsScene[i])
                m_dominantColorsScene[i]->clear();
        }
            
        m_mainPictureScene = new QGraphicsScene(m_ui.mainPicture);
        m_mainImage->load(filename);
        int width = m_ui.mainPicture->width();
        int height = m_ui.mainPicture->height();
        QPixmap pixmap = m_mainImage->width() > m_mainImage->height() ? QPixmap::fromImage(*m_mainImage).scaledToWidth(width-2) : QPixmap::fromImage(*m_mainImage).scaledToHeight(height-2);
        QFileInfo fileInfo(filename);
        m_ui.mainText->setText(fileInfo.fileName());
        m_mainPictureScene->addPixmap(pixmap);
        m_ui.mainPicture->setScene(m_mainPictureScene);
    }
}