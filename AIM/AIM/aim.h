#ifndef AIM_H
#define AIM_H

#include "../../../Includes/common.h"

#include <QtWidgets/QMainWindow>
#include <string>
#include "ui_aim.h"

using namespace std;

class AIM : public QMainWindow
{
    Q_OBJECT

public slots:
    void startButtonClicked();
    void loadImageButtonClicked();
    void refreshDatabaseButtonClicked();
    void pathToDatabaseChanged(const QString& newPath) { m_pathToDatabase = newPath; }
    void setCleanAndRebuildFlag(bool flag) { m_cleanAndRebuildFlag = flag; }

public:
    AIM(QWidget *parent = 0);
    ~AIM();

private:
    Ui::AIMClass m_ui;
    void moveCellsIntoTables();
    QGraphicsView* m_pictures[8];
    QGraphicsScene* m_picturesScene[8];
    QLineEdit* m_labels[8];
    QGraphicsView* m_dominantColors[DOMINANTCOLORS_NUMBER];
    QGraphicsScene* m_dominantColorsScene[DOMINANTCOLORS_NUMBER];
    QGraphicsScene* m_mainPictureScene;
    QString m_pathToDatabase;
    QImage* m_mainImage;
    bool m_cleanAndRebuildFlag;
    bool m_hasChangedMainImage;
    vector<QColor> m_mainImageDominantColors;
};

#endif // AIM_H
