#include "aim.h"
#include "../../../Includes/DominantColor.h"
#include <QFileDialog>

AIM::AIM(QWidget *parent)
    : QMainWindow(parent)
    , m_mainPictureScene(0)
    , m_mainImage(0)
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
    QObject::connect(m_ui.baseDirField, SIGNAL(textChanged(const QString &)),this, SLOT(pathToDatabaseChanged(const QString &)));
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

    for (int i = 0; i < 8; ++i)
        m_picturesScene[i] = new QGraphicsScene(m_pictures[i]);
    
}

void AIM::startButtonClicked()
{

    if(!m_mainImage)
    {
        // FIXME: popup with error
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        if (m_dominantColorsScene[i])
            delete m_dominantColorsScene[i];
        m_dominantColorsScene[i] = new QGraphicsScene(m_dominantColors[i]);
    }

    vector<QColor> colors = DominantColors::get().countDominantColors(*m_mainImage);

    int dominantWindowWidth = m_dominantColors[0]->width();
    int dominantWindowHeight = m_dominantColors[0]->height();

    for (int i = 0; i < 8; ++i)
    {
        QPixmap pixmap(dominantWindowWidth, dominantWindowHeight);
        pixmap.fill(colors[i]);
        m_dominantColorsScene[i]->addPixmap(pixmap);
        m_dominantColors[i]->setScene(m_dominantColorsScene[i]);
    }

     
}

void AIM::loadImageButtonClicked()
{
    string filename = QFileDialog::getOpenFileName(this,tr("Otw\303\263rz plik z Sudoku"), ".", tr("JPEG (*.jpg;*.jpeg); PNG (*.png); BMP (*.bmp)")).toStdString();
    if(!filename.empty()){
        if (m_mainPictureScene)
            delete m_mainPictureScene;
        if (!m_mainImage)
            m_mainImage = new QImage();
        m_mainPictureScene = new QGraphicsScene(m_ui.mainPicture);
        m_mainImage->load(QString::fromStdString(filename));
        int width = m_ui.mainPicture->width();
        int height = m_ui.mainPicture->height();
        QPixmap pixmap = m_mainImage->width() > m_mainImage->height() ? QPixmap::fromImage(*m_mainImage).scaledToWidth(width-2) : QPixmap::fromImage(*m_mainImage).scaledToHeight(height-2);
        QFileInfo fileInfo(QString::fromStdString(filename));
        m_ui.mainText->setText(fileInfo.fileName());
        m_mainPictureScene->addPixmap(pixmap);
        m_ui.mainPicture->setScene(m_mainPictureScene);
    }
}