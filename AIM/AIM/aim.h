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

public:
    AIM(QWidget *parent = 0);
    ~AIM();

private:
    Ui::AIMClass m_ui;
    void moveCellsIntoTables();
    QGraphicsView* m_pictures[8];
    QGraphicsScene* m_picturesScene[8];
    QLineEdit* m_labels[8];
    QGraphicsView* m_dominantColors[8];
    QGraphicsScene* m_dominantColorsScene[8];
    QGraphicsScene* m_mainPictureScene;
    QString m_pathToDatabase;
    QImage* m_mainImage;

};

#endif // AIM_H
