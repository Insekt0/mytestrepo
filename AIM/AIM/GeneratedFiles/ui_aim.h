/********************************************************************************
** Form generated from reading UI file 'aim.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIM_H
#define UI_AIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIMClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *mainPicture;
    QGraphicsView *picture1;
    QGraphicsView *picture2;
    QGraphicsView *picture3;
    QGraphicsView *picture4;
    QGraphicsView *picture5;
    QGraphicsView *picture6;
    QGraphicsView *picture7;
    QGraphicsView *picture8;
    QLineEdit *text1;
    QLineEdit *mainText;
    QLineEdit *text2;
    QLineEdit *text3;
    QLineEdit *text4;
    QLineEdit *text5;
    QLineEdit *text6;
    QLineEdit *text7;
    QLineEdit *text8;
    QLabel *baseDirLabel;
    QLineEdit *baseDirField;
    QPushButton *loadButton;
    QPushButton *startButton;
    QLabel *dominantColorLabel;
    QGraphicsView *dominant1;
    QGraphicsView *dominant2;
    QGraphicsView *dominant3;
    QGraphicsView *dominant5;
    QGraphicsView *dominant6;
    QGraphicsView *dominant4;
    QGraphicsView *dominant7;
    QGraphicsView *dominant8;
    QLabel *basePathLabel;
    QLabel *mainPictureLabel;
    QPushButton *refreshDatabase;
    QCheckBox *cleanAndRebuildDatabase;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AIMClass)
    {
        if (AIMClass->objectName().isEmpty())
            AIMClass->setObjectName(QStringLiteral("AIMClass"));
        AIMClass->resize(1000, 860);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AIMClass->sizePolicy().hasHeightForWidth());
        AIMClass->setSizePolicy(sizePolicy);
        AIMClass->setMinimumSize(QSize(1000, 860));
        AIMClass->setMaximumSize(QSize(1000, 860));
        AIMClass->setMouseTracking(false);
        AIMClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(AIMClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainPicture = new QGraphicsView(centralWidget);
        mainPicture->setObjectName(QStringLiteral("mainPicture"));
        mainPicture->setGeometry(QRect(200, 30, 200, 200));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainPicture->sizePolicy().hasHeightForWidth());
        mainPicture->setSizePolicy(sizePolicy1);
        mainPicture->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mainPicture->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture1 = new QGraphicsView(centralWidget);
        picture1->setObjectName(QStringLiteral("picture1"));
        picture1->setGeometry(QRect(100, 330, 150, 150));
        sizePolicy.setHeightForWidth(picture1->sizePolicy().hasHeightForWidth());
        picture1->setSizePolicy(sizePolicy);
        picture1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture2 = new QGraphicsView(centralWidget);
        picture2->setObjectName(QStringLiteral("picture2"));
        picture2->setGeometry(QRect(310, 330, 150, 150));
        sizePolicy.setHeightForWidth(picture2->sizePolicy().hasHeightForWidth());
        picture2->setSizePolicy(sizePolicy);
        picture2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture3 = new QGraphicsView(centralWidget);
        picture3->setObjectName(QStringLiteral("picture3"));
        picture3->setGeometry(QRect(520, 330, 150, 150));
        sizePolicy.setHeightForWidth(picture3->sizePolicy().hasHeightForWidth());
        picture3->setSizePolicy(sizePolicy);
        picture3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture4 = new QGraphicsView(centralWidget);
        picture4->setObjectName(QStringLiteral("picture4"));
        picture4->setGeometry(QRect(730, 330, 150, 150));
        sizePolicy.setHeightForWidth(picture4->sizePolicy().hasHeightForWidth());
        picture4->setSizePolicy(sizePolicy);
        picture4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture5 = new QGraphicsView(centralWidget);
        picture5->setObjectName(QStringLiteral("picture5"));
        picture5->setGeometry(QRect(100, 540, 150, 150));
        sizePolicy.setHeightForWidth(picture5->sizePolicy().hasHeightForWidth());
        picture5->setSizePolicy(sizePolicy);
        picture5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture6 = new QGraphicsView(centralWidget);
        picture6->setObjectName(QStringLiteral("picture6"));
        picture6->setGeometry(QRect(310, 540, 150, 150));
        sizePolicy.setHeightForWidth(picture6->sizePolicy().hasHeightForWidth());
        picture6->setSizePolicy(sizePolicy);
        picture6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture7 = new QGraphicsView(centralWidget);
        picture7->setObjectName(QStringLiteral("picture7"));
        picture7->setGeometry(QRect(520, 540, 150, 150));
        sizePolicy.setHeightForWidth(picture7->sizePolicy().hasHeightForWidth());
        picture7->setSizePolicy(sizePolicy);
        picture7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture8 = new QGraphicsView(centralWidget);
        picture8->setObjectName(QStringLiteral("picture8"));
        picture8->setGeometry(QRect(730, 540, 150, 150));
        sizePolicy.setHeightForWidth(picture8->sizePolicy().hasHeightForWidth());
        picture8->setSizePolicy(sizePolicy);
        picture8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        picture8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text1 = new QLineEdit(centralWidget);
        text1->setObjectName(QStringLiteral("text1"));
        text1->setGeometry(QRect(100, 490, 150, 20));
        text1->setReadOnly(true);
        mainText = new QLineEdit(centralWidget);
        mainText->setObjectName(QStringLiteral("mainText"));
        mainText->setGeometry(QRect(210, 240, 181, 20));
        mainText->setReadOnly(true);
        mainText->setClearButtonEnabled(true);
        text2 = new QLineEdit(centralWidget);
        text2->setObjectName(QStringLiteral("text2"));
        text2->setGeometry(QRect(310, 490, 150, 20));
        text2->setReadOnly(true);
        text3 = new QLineEdit(centralWidget);
        text3->setObjectName(QStringLiteral("text3"));
        text3->setGeometry(QRect(520, 490, 150, 20));
        text3->setReadOnly(true);
        text4 = new QLineEdit(centralWidget);
        text4->setObjectName(QStringLiteral("text4"));
        text4->setGeometry(QRect(730, 490, 150, 20));
        text4->setReadOnly(true);
        text5 = new QLineEdit(centralWidget);
        text5->setObjectName(QStringLiteral("text5"));
        text5->setGeometry(QRect(100, 700, 150, 20));
        text5->setReadOnly(true);
        text6 = new QLineEdit(centralWidget);
        text6->setObjectName(QStringLiteral("text6"));
        text6->setGeometry(QRect(310, 700, 150, 20));
        text6->setReadOnly(true);
        text7 = new QLineEdit(centralWidget);
        text7->setObjectName(QStringLiteral("text7"));
        text7->setGeometry(QRect(520, 700, 150, 20));
        text7->setReadOnly(true);
        text8 = new QLineEdit(centralWidget);
        text8->setObjectName(QStringLiteral("text8"));
        text8->setGeometry(QRect(730, 700, 150, 20));
        text8->setReadOnly(true);
        baseDirLabel = new QLabel(centralWidget);
        baseDirLabel->setObjectName(QStringLiteral("baseDirLabel"));
        baseDirLabel->setGeometry(QRect(140, 740, 111, 16));
        baseDirField = new QLineEdit(centralWidget);
        baseDirField->setObjectName(QStringLiteral("baseDirField"));
        baseDirField->setGeometry(QRect(60, 760, 231, 22));
        baseDirField->setInputMethodHints(Qt::ImhDigitsOnly);
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(330, 760, 111, 25));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(730, 760, 151, 25));
        dominantColorLabel = new QLabel(centralWidget);
        dominantColorLabel->setObjectName(QStringLiteral("dominantColorLabel"));
        dominantColorLabel->setGeometry(QRect(620, 40, 111, 16));
        dominant1 = new QGraphicsView(centralWidget);
        dominant1->setObjectName(QStringLiteral("dominant1"));
        dominant1->setGeometry(QRect(520, 80, 50, 50));
        sizePolicy.setHeightForWidth(dominant1->sizePolicy().hasHeightForWidth());
        dominant1->setSizePolicy(sizePolicy);
        dominant1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant2 = new QGraphicsView(centralWidget);
        dominant2->setObjectName(QStringLiteral("dominant2"));
        dominant2->setGeometry(QRect(600, 80, 50, 50));
        sizePolicy.setHeightForWidth(dominant2->sizePolicy().hasHeightForWidth());
        dominant2->setSizePolicy(sizePolicy);
        dominant2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant3 = new QGraphicsView(centralWidget);
        dominant3->setObjectName(QStringLiteral("dominant3"));
        dominant3->setGeometry(QRect(680, 80, 50, 50));
        sizePolicy.setHeightForWidth(dominant3->sizePolicy().hasHeightForWidth());
        dominant3->setSizePolicy(sizePolicy);
        dominant3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant5 = new QGraphicsView(centralWidget);
        dominant5->setObjectName(QStringLiteral("dominant5"));
        dominant5->setGeometry(QRect(520, 160, 50, 50));
        sizePolicy.setHeightForWidth(dominant5->sizePolicy().hasHeightForWidth());
        dominant5->setSizePolicy(sizePolicy);
        dominant5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant6 = new QGraphicsView(centralWidget);
        dominant6->setObjectName(QStringLiteral("dominant6"));
        dominant6->setGeometry(QRect(600, 160, 50, 50));
        sizePolicy.setHeightForWidth(dominant6->sizePolicy().hasHeightForWidth());
        dominant6->setSizePolicy(sizePolicy);
        dominant6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant4 = new QGraphicsView(centralWidget);
        dominant4->setObjectName(QStringLiteral("dominant4"));
        dominant4->setGeometry(QRect(760, 80, 50, 50));
        sizePolicy.setHeightForWidth(dominant4->sizePolicy().hasHeightForWidth());
        dominant4->setSizePolicy(sizePolicy);
        dominant4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant7 = new QGraphicsView(centralWidget);
        dominant7->setObjectName(QStringLiteral("dominant7"));
        dominant7->setGeometry(QRect(680, 160, 50, 50));
        sizePolicy.setHeightForWidth(dominant7->sizePolicy().hasHeightForWidth());
        dominant7->setSizePolicy(sizePolicy);
        dominant7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant8 = new QGraphicsView(centralWidget);
        dominant8->setObjectName(QStringLiteral("dominant8"));
        dominant8->setGeometry(QRect(760, 160, 50, 50));
        sizePolicy.setHeightForWidth(dominant8->sizePolicy().hasHeightForWidth());
        dominant8->setSizePolicy(sizePolicy);
        dominant8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        dominant8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        basePathLabel = new QLabel(centralWidget);
        basePathLabel->setObjectName(QStringLiteral("basePathLabel"));
        basePathLabel->setGeometry(QRect(400, 290, 221, 20));
        mainPictureLabel = new QLabel(centralWidget);
        mainPictureLabel->setObjectName(QStringLiteral("mainPictureLabel"));
        mainPictureLabel->setGeometry(QRect(270, 10, 111, 16));
        refreshDatabase = new QPushButton(centralWidget);
        refreshDatabase->setObjectName(QStringLiteral("refreshDatabase"));
        refreshDatabase->setGeometry(QRect(520, 760, 151, 25));
        cleanAndRebuildDatabase = new QCheckBox(centralWidget);
        cleanAndRebuildDatabase->setObjectName(QStringLiteral("cleanAndRebuildDatabase"));
        cleanAndRebuildDatabase->setGeometry(QRect(500, 790, 191, 20));
        AIMClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AIMClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        AIMClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AIMClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AIMClass->setStatusBar(statusBar);

        retranslateUi(AIMClass);

        QMetaObject::connectSlotsByName(AIMClass);
    } // setupUi

    void retranslateUi(QMainWindow *AIMClass)
    {
        AIMClass->setWindowTitle(QApplication::translate("AIMClass", "Micha\305\202 Jurkiewicz - Projekt AIM", 0));
        baseDirLabel->setText(QApplication::translate("AIMClass", "\305\232cie\305\274ka do bazy:", 0));
        baseDirField->setText(QApplication::translate("AIMClass", "D:\\studia\\MGR\\AIM\\projekt\\Base\\Short\\", 0));
        loadButton->setText(QApplication::translate("AIMClass", "Wczytaj plik", 0));
        startButton->setText(QApplication::translate("AIMClass", "Rozpocznij przeszukiwanie!", 0));
        dominantColorLabel->setText(QApplication::translate("AIMClass", "Kolory dominuj\304\205ce:", 0));
        basePathLabel->setText(QApplication::translate("AIMClass", "Obrazy o podobnych kolorach dominuj\304\205cych:", 0));
        mainPictureLabel->setText(QApplication::translate("AIMClass", "Badany obrazek:", 0));
        refreshDatabase->setText(QApplication::translate("AIMClass", "Od\305\233wie\305\274 baz\304\231 danych", 0));
        cleanAndRebuildDatabase->setText(QApplication::translate("AIMClass", "Wyczy\305\233\304\207 i przebuduj baz\304\231 danych", 0));
    } // retranslateUi

};

namespace Ui {
    class AIMClass: public Ui_AIMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIM_H
