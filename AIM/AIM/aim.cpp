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
    for (int i = 0; i < 8; ++i)
    {
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
    for (int i = 0; i < 8; ++i)
    {
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
    switch (DatabaseManager::get().updateDatabase(m_pathToDatabase, this, m_cleanAndRebuildFlag))
    {
    case Ok:    
        QMessageBox::information(this, tr(""), tr("Baza zostala zaktualizowana") );
        break;
    case DirectoryEmpty:
        QMessageBox::warning(this, tr(""), tr("Katalog z baza danych nie zawiera obrazkow!") );
        break;
    case RefreshAborted:
        QMessageBox::warning(this, tr(""), tr("Odswiezanie zostalo przerwane!") );
        break;
    default:
        QMessageBox::critical(this, tr(""), tr("Niezidentyfikowany blad!") );
    }
}

bool sortFunction (pair<QString,double> first_pair, pair<QString,double> second_pair) {
    return first_pair.second < second_pair.second; 
}

void AIM::startButtonClicked()
{

    if (!m_mainImage)
    {
        QString text = QString("Nie wybrano obrazka!");
        QMessageBox::warning(this, tr(""), text);
        return;
    }

    if(m_hasChangedMainImage)
    {
        for (int i = 0; i < DOMINANTCOLORS_NUMBER; ++i)
        {
            if (m_dominantColorsScene[i])
                delete m_dominantColorsScene[i];
            m_dominantColorsScene[i] = new QGraphicsScene(m_dominantColors[i]);
        }
        m_mainImageDominantColors = DominantColors::get().countDominantColors(*m_mainImage);

        int dominantWindowWidth = m_dominantColors[0]->width();
        int dominantWindowHeight = m_dominantColors[0]->height();

        for (int i = 0; i < DOMINANTCOLORS_NUMBER; ++i)
        {
            QPixmap pixmap(dominantWindowWidth, dominantWindowHeight);
            pixmap.fill(m_mainImageDominantColors[i]);
            m_dominantColorsScene[i]->addPixmap(pixmap);
            m_dominantColors[i]->setScene(m_dominantColorsScene[i]);
        }
        m_hasChangedMainImage = false;
    }

    QFile file(databaseFilename);
    DatabaseManager::get().readDatabaseFromFile(file, this);

    if (DatabaseManager::get().getDatabase().empty())
    {
        QString text = QString("Baza danych pusta! Odœwie¿ bazê danych!");
        QMessageBox::warning(this, tr(""), text);
        return;
    }

    vector<pair<QString,double>> distanceVector;

    double distance = 0;

    std::map<QString,vector<QColor>> databaseMap = DatabaseManager::get().getDatabase();
    
    for (std::map<QString,vector<QColor>>::iterator it = databaseMap.begin(); it != databaseMap.end(); ++it)
    {
        vector<QColor> secondImageDominantColors = it->second;
        distance = DominantColors::get().calculateDistance(m_mainImageDominantColors, secondImageDominantColors);
        distanceVector.push_back(make_pair(it->first,distance));
    }
    sort(distanceVector.begin(), distanceVector.end(), sortFunction);
    
    int numberOfImages = 0;

    for (int i = 0; i < distanceVector.size(); ++i)
    {
        if(numberOfImages == 8)
            break;
        QString filename = defaultPath + distanceVector[i].first;
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

        m_labels[numberOfImages]->setText(distanceVector[i].first);
        m_picturesScene[numberOfImages]->addPixmap(pixmap);
        m_pictures[i]->setScene(m_picturesScene[numberOfImages]);
        ++numberOfImages;
    }




    // FIXME: Narysuj 8 najbardziej podobnych na ekranie

}

void AIM::loadImageButtonClicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Otw\303\263rz plik z obrazem"), ".", tr("JPEG (*.jpg;*.jpeg);; PNG (*.png);; BMP (*.bmp)"));
    if(!filename.isEmpty()){
        if (m_mainPictureScene)
            delete m_mainPictureScene;
        if (!m_mainImage)
            m_mainImage = new QImage();
        m_hasChangedMainImage = true;
        // QString text = QString("filename = %1").arg(filename);
        // QMessageBox::information(this, tr(""), text );
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