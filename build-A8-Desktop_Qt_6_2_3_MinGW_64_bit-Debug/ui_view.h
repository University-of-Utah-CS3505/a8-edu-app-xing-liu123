/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *MainMenuPage;
    QLabel *label;
    QPushButton *freshWaterButton;
    QPushButton *smoothWaterButton;
    QPushButton *saltWaterButton;
    QLabel *label_3;
    QWidget *FishingPage;
    QLabel *fish1Label;
    QLabel *fish2Label;
    QLabel *fish3Label;
    QLabel *spearLabel;
    QLabel *locationLabel;
    QPushButton *catchButton;
    QWidget *JournalPage;
    QLabel *label_2;
    QWidget *FishInfoPage;
    QLabel *CongratsLabel;
    QLabel *fishNameLabel;
    QLabel *inforFishPicLabel;
    QLabel *infoQ1Label;
    QLabel *infoQ2Label;
    QLabel *infoQ3Label;
    QLabel *infoQ4Label;
    QLabel *infoA1Label;
    QLabel *infoA2Label;
    QLabel *infoA3Label;
    QLabel *infoA4Label;
    QWidget *QuizInfoPage;
    QLabel *QuizTitleLabel;
    QLabel *quizQ1Label;
    QPushButton *answ1Button;
    QPushButton *answ1Button_2;
    QPushButton *answ1Button_3;
    QLabel *fishPicLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(800, 600);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 771, 551));
        stackedWidget->setMouseTracking(true);
        MainMenuPage = new QWidget();
        MainMenuPage->setObjectName(QString::fromUtf8("MainMenuPage"));
        MainMenuPage->setMouseTracking(false);
        label = new QLabel(MainMenuPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 411, 261));
        freshWaterButton = new QPushButton(MainMenuPage);
        freshWaterButton->setObjectName(QString::fromUtf8("freshWaterButton"));
        freshWaterButton->setGeometry(QRect(20, 150, 161, 81));
        smoothWaterButton = new QPushButton(MainMenuPage);
        smoothWaterButton->setObjectName(QString::fromUtf8("smoothWaterButton"));
        smoothWaterButton->setGeometry(QRect(160, 270, 161, 71));
        saltWaterButton = new QPushButton(MainMenuPage);
        saltWaterButton->setObjectName(QString::fromUtf8("saltWaterButton"));
        saltWaterButton->setGeometry(QRect(250, 150, 161, 81));
        label_3 = new QLabel(MainMenuPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 80, 271, 31));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(MainMenuPage);
        FishingPage = new QWidget();
        FishingPage->setObjectName(QString::fromUtf8("FishingPage"));
        FishingPage->setMouseTracking(true);
        fish1Label = new QLabel(FishingPage);
        fish1Label->setObjectName(QString::fromUtf8("fish1Label"));
        fish1Label->setGeometry(QRect(40, 300, 111, 81));
        fish2Label = new QLabel(FishingPage);
        fish2Label->setObjectName(QString::fromUtf8("fish2Label"));
        fish2Label->setGeometry(QRect(30, 390, 111, 71));
        fish3Label = new QLabel(FishingPage);
        fish3Label->setObjectName(QString::fromUtf8("fish3Label"));
        fish3Label->setGeometry(QRect(30, 480, 111, 61));
        spearLabel = new QLabel(FishingPage);
        spearLabel->setObjectName(QString::fromUtf8("spearLabel"));
        spearLabel->setGeometry(QRect(400, 0, 61, 101));
        locationLabel = new QLabel(FishingPage);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(580, 10, 131, 16));
        catchButton = new QPushButton(FishingPage);
        catchButton->setObjectName(QString::fromUtf8("catchButton"));
        catchButton->setGeometry(QRect(590, 70, 80, 18));
        stackedWidget->addWidget(FishingPage);
        JournalPage = new QWidget();
        JournalPage->setObjectName(QString::fromUtf8("JournalPage"));
        JournalPage->setMouseTracking(false);
        label_2 = new QLabel(JournalPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, 10, 451, 301));
        stackedWidget->addWidget(JournalPage);
        FishInfoPage = new QWidget();
        FishInfoPage->setObjectName(QString::fromUtf8("FishInfoPage"));
        CongratsLabel = new QLabel(FishInfoPage);
        CongratsLabel->setObjectName(QString::fromUtf8("CongratsLabel"));
        CongratsLabel->setGeometry(QRect(256, 40, 271, 20));
        fishNameLabel = new QLabel(FishInfoPage);
        fishNameLabel->setObjectName(QString::fromUtf8("fishNameLabel"));
        fishNameLabel->setGeometry(QRect(286, 70, 181, 20));
        inforFishPicLabel = new QLabel(FishInfoPage);
        inforFishPicLabel->setObjectName(QString::fromUtf8("inforFishPicLabel"));
        inforFishPicLabel->setGeometry(QRect(470, 30, 261, 251));
        infoQ1Label = new QLabel(FishInfoPage);
        infoQ1Label->setObjectName(QString::fromUtf8("infoQ1Label"));
        infoQ1Label->setGeometry(QRect(50, 140, 171, 16));
        infoQ2Label = new QLabel(FishInfoPage);
        infoQ2Label->setObjectName(QString::fromUtf8("infoQ2Label"));
        infoQ2Label->setGeometry(QRect(40, 220, 171, 16));
        infoQ3Label = new QLabel(FishInfoPage);
        infoQ3Label->setObjectName(QString::fromUtf8("infoQ3Label"));
        infoQ3Label->setGeometry(QRect(40, 310, 171, 16));
        infoQ4Label = new QLabel(FishInfoPage);
        infoQ4Label->setObjectName(QString::fromUtf8("infoQ4Label"));
        infoQ4Label->setGeometry(QRect(30, 400, 171, 16));
        infoA1Label = new QLabel(FishInfoPage);
        infoA1Label->setObjectName(QString::fromUtf8("infoA1Label"));
        infoA1Label->setGeometry(QRect(50, 180, 131, 16));
        infoA2Label = new QLabel(FishInfoPage);
        infoA2Label->setObjectName(QString::fromUtf8("infoA2Label"));
        infoA2Label->setGeometry(QRect(40, 270, 131, 16));
        infoA3Label = new QLabel(FishInfoPage);
        infoA3Label->setObjectName(QString::fromUtf8("infoA3Label"));
        infoA3Label->setGeometry(QRect(40, 360, 721, 16));
        infoA4Label = new QLabel(FishInfoPage);
        infoA4Label->setObjectName(QString::fromUtf8("infoA4Label"));
        infoA4Label->setGeometry(QRect(40, 450, 131, 16));
        stackedWidget->addWidget(FishInfoPage);
        QuizInfoPage = new QWidget();
        QuizInfoPage->setObjectName(QString::fromUtf8("QuizInfoPage"));
        QuizTitleLabel = new QLabel(QuizInfoPage);
        QuizTitleLabel->setObjectName(QString::fromUtf8("QuizTitleLabel"));
        QuizTitleLabel->setGeometry(QRect(336, 30, 101, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        QuizTitleLabel->setFont(font1);
        QuizTitleLabel->setAlignment(Qt::AlignCenter);
        quizQ1Label = new QLabel(QuizInfoPage);
        quizQ1Label->setObjectName(QString::fromUtf8("quizQ1Label"));
        quizQ1Label->setGeometry(QRect(50, 120, 191, 31));
        QFont font2;
        font2.setBold(true);
        quizQ1Label->setFont(font2);
        answ1Button = new QPushButton(QuizInfoPage);
        answ1Button->setObjectName(QString::fromUtf8("answ1Button"));
        answ1Button->setGeometry(QRect(50, 180, 80, 18));
        answ1Button_2 = new QPushButton(QuizInfoPage);
        answ1Button_2->setObjectName(QString::fromUtf8("answ1Button_2"));
        answ1Button_2->setGeometry(QRect(50, 220, 80, 18));
        answ1Button_3 = new QPushButton(QuizInfoPage);
        answ1Button_3->setObjectName(QString::fromUtf8("answ1Button_3"));
        answ1Button_3->setGeometry(QRect(50, 260, 80, 18));
        fishPicLabel = new QLabel(QuizInfoPage);
        fishPicLabel->setObjectName(QString::fromUtf8("fishPicLabel"));
        fishPicLabel->setGeometry(QRect(520, 20, 211, 241));
        stackedWidget->addWidget(QuizInfoPage);
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        View->setStatusBar(statusbar);

        retranslateUi(View);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        label->setText(QString());
        freshWaterButton->setText(QCoreApplication::translate("View", "Fresh Water", nullptr));
        smoothWaterButton->setText(QCoreApplication::translate("View", "Smooth Water", nullptr));
        saltWaterButton->setText(QCoreApplication::translate("View", "Salt Water", nullptr));
        label_3->setText(QCoreApplication::translate("View", "Select were would you like to navegate!", nullptr));
        fish1Label->setText(QCoreApplication::translate("View", "Fish 1", nullptr));
        fish2Label->setText(QCoreApplication::translate("View", "Fish 2", nullptr));
        fish3Label->setText(QCoreApplication::translate("View", "Fish 3", nullptr));
        spearLabel->setText(QCoreApplication::translate("View", "Spear", nullptr));
        locationLabel->setText(QCoreApplication::translate("View", "X: Y:", nullptr));
        catchButton->setText(QCoreApplication::translate("View", "Catch", nullptr));
        label_2->setText(QString());
        CongratsLabel->setText(QCoreApplication::translate("View", "Congratulations! You have catch", nullptr));
        fishNameLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        inforFishPicLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        infoQ1Label->setText(QCoreApplication::translate("View", "q1", nullptr));
        infoQ2Label->setText(QCoreApplication::translate("View", "q2", nullptr));
        infoQ3Label->setText(QCoreApplication::translate("View", "q3", nullptr));
        infoQ4Label->setText(QCoreApplication::translate("View", "q4", nullptr));
        infoA1Label->setText(QCoreApplication::translate("View", "a1", nullptr));
        infoA2Label->setText(QCoreApplication::translate("View", "a2", nullptr));
        infoA3Label->setText(QCoreApplication::translate("View", "a3", nullptr));
        infoA4Label->setText(QCoreApplication::translate("View", "a4", nullptr));
        QuizTitleLabel->setText(QCoreApplication::translate("View", "Quiz", nullptr));
        quizQ1Label->setText(QCoreApplication::translate("View", "What is my name? ", nullptr));
        answ1Button->setText(QCoreApplication::translate("View", "PushButton", nullptr));
        answ1Button_2->setText(QCoreApplication::translate("View", "PushButton", nullptr));
        answ1Button_3->setText(QCoreApplication::translate("View", "PushButton", nullptr));
        fishPicLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
