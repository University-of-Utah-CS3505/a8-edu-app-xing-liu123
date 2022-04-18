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
    QLabel *smoothPicLabel;
    QLabel *saltPicLabel;
    QLabel *freshPicLabel;
    QPushButton *mainMenuMucisButton;
    QWidget *FishingPage;
    QLabel *fish1Label;
    QLabel *fish2Label;
    QLabel *fish3Label;
    QLabel *spearLabel;
    QLabel *locationLabel;
    QPushButton *catchButton;
    QPushButton *goToQuizButton;
    QPushButton *journalButton;
    QWidget *JournalPage;
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
    QPushButton *nextButtonFI;
    QPushButton *nextFishTestButton;
    QWidget *QuizInfoPage;
    QLabel *QuizTitleLabel;
    QLabel *quizQ1Label;
    QPushButton *answ1Button;
    QPushButton *answ1Button_2;
    QPushButton *answ1Button_3;
    QLabel *fishPicLabel;
    QLabel *quizFishName;
    QLabel *resultLabel;
    QPushButton *nextButton;
    QPushButton *nextQuestionButton;
    QWidget *JournalPage_1;
    QLabel *journalTittleLabel;
    QLabel *journalPageLabel;
    QLabel *journalPicLabel_1;
    QLabel *journalPicLabel_2;
    QLabel *journalPicLabel_3;
    QLabel *journalPicLabel_4;
    QLabel *journalPicLabel_5;
    QLabel *journalInfoLabel_1;
    QLabel *journalInfoLabel_2;
    QLabel *journalInfoLabel_3;
    QLabel *journalInfoLabel_4;
    QLabel *journalInfoLabel_5;
    QPushButton *journalNextButton;
    QPushButton *journalPrevButton;
    QPushButton *journalKeepFishingButton;
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
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        stackedWidget->setMouseTracking(true);
        MainMenuPage = new QWidget();
        MainMenuPage->setObjectName(QString::fromUtf8("MainMenuPage"));
        MainMenuPage->setMouseTracking(false);
        label = new QLabel(MainMenuPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 411, 261));
        freshWaterButton = new QPushButton(MainMenuPage);
        freshWaterButton->setObjectName(QString::fromUtf8("freshWaterButton"));
        freshWaterButton->setGeometry(QRect(60, 290, 161, 81));
        smoothWaterButton = new QPushButton(MainMenuPage);
        smoothWaterButton->setObjectName(QString::fromUtf8("smoothWaterButton"));
        smoothWaterButton->setGeometry(QRect(310, 440, 161, 71));
        saltWaterButton = new QPushButton(MainMenuPage);
        saltWaterButton->setObjectName(QString::fromUtf8("saltWaterButton"));
        saltWaterButton->setGeometry(QRect(560, 290, 161, 81));
        label_3 = new QLabel(MainMenuPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 60, 611, 31));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        smoothPicLabel = new QLabel(MainMenuPage);
        smoothPicLabel->setObjectName(QString::fromUtf8("smoothPicLabel"));
        smoothPicLabel->setGeometry(QRect(290, 290, 201, 141));
        saltPicLabel = new QLabel(MainMenuPage);
        saltPicLabel->setObjectName(QString::fromUtf8("saltPicLabel"));
        saltPicLabel->setGeometry(QRect(540, 140, 201, 141));
        freshPicLabel = new QLabel(MainMenuPage);
        freshPicLabel->setObjectName(QString::fromUtf8("freshPicLabel"));
        freshPicLabel->setGeometry(QRect(40, 140, 201, 141));
        mainMenuMucisButton = new QPushButton(MainMenuPage);
        mainMenuMucisButton->setObjectName(QString::fromUtf8("mainMenuMucisButton"));
        mainMenuMucisButton->setGeometry(QRect(670, 490, 100, 32));
        stackedWidget->addWidget(MainMenuPage);
        FishingPage = new QWidget();
        FishingPage->setObjectName(QString::fromUtf8("FishingPage"));
        FishingPage->setMouseTracking(true);
        fish1Label = new QLabel(FishingPage);
        fish1Label->setObjectName(QString::fromUtf8("fish1Label"));
        fish1Label->setGeometry(QRect(0, 260, 110, 80));
        fish1Label->setMouseTracking(true);
        fish2Label = new QLabel(FishingPage);
        fish2Label->setObjectName(QString::fromUtf8("fish2Label"));
        fish2Label->setGeometry(QRect(0, 360, 110, 80));
        fish2Label->setMouseTracking(true);
        fish3Label = new QLabel(FishingPage);
        fish3Label->setObjectName(QString::fromUtf8("fish3Label"));
        fish3Label->setGeometry(QRect(0, 460, 110, 80));
        fish3Label->setMouseTracking(true);
        spearLabel = new QLabel(FishingPage);
        spearLabel->setObjectName(QString::fromUtf8("spearLabel"));
        spearLabel->setGeometry(QRect(325, 0, 150, 150));
        spearLabel->setMouseTracking(true);
        locationLabel = new QLabel(FishingPage);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(580, 10, 131, 16));
        locationLabel->setMouseTracking(true);
        catchButton = new QPushButton(FishingPage);
        catchButton->setObjectName(QString::fromUtf8("catchButton"));
        catchButton->setGeometry(QRect(590, 70, 80, 18));
        goToQuizButton = new QPushButton(FishingPage);
        goToQuizButton->setObjectName(QString::fromUtf8("goToQuizButton"));
        goToQuizButton->setGeometry(QRect(630, 110, 131, 31));
        journalButton = new QPushButton(FishingPage);
        journalButton->setObjectName(QString::fromUtf8("journalButton"));
        journalButton->setGeometry(QRect(30, 30, 99, 33));
        stackedWidget->addWidget(FishingPage);
        JournalPage = new QWidget();
        JournalPage->setObjectName(QString::fromUtf8("JournalPage"));
        JournalPage->setMouseTracking(false);
        stackedWidget->addWidget(JournalPage);
        FishInfoPage = new QWidget();
        FishInfoPage->setObjectName(QString::fromUtf8("FishInfoPage"));
        CongratsLabel = new QLabel(FishInfoPage);
        CongratsLabel->setObjectName(QString::fromUtf8("CongratsLabel"));
        CongratsLabel->setGeometry(QRect(170, 19, 451, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(true);
        CongratsLabel->setFont(font1);
        CongratsLabel->setAlignment(Qt::AlignCenter);
        fishNameLabel = new QLabel(FishInfoPage);
        fishNameLabel->setObjectName(QString::fromUtf8("fishNameLabel"));
        fishNameLabel->setGeometry(QRect(300, 80, 181, 20));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        fishNameLabel->setFont(font2);
        fishNameLabel->setAlignment(Qt::AlignCenter);
        inforFishPicLabel = new QLabel(FishInfoPage);
        inforFishPicLabel->setObjectName(QString::fromUtf8("inforFishPicLabel"));
        inforFishPicLabel->setGeometry(QRect(460, 180, 260, 250));
        infoQ1Label = new QLabel(FishInfoPage);
        infoQ1Label->setObjectName(QString::fromUtf8("infoQ1Label"));
        infoQ1Label->setGeometry(QRect(50, 140, 171, 16));
        QFont font3;
        font3.setBold(true);
        infoQ1Label->setFont(font3);
        infoQ2Label = new QLabel(FishInfoPage);
        infoQ2Label->setObjectName(QString::fromUtf8("infoQ2Label"));
        infoQ2Label->setGeometry(QRect(50, 220, 171, 16));
        infoQ2Label->setFont(font3);
        infoQ3Label = new QLabel(FishInfoPage);
        infoQ3Label->setObjectName(QString::fromUtf8("infoQ3Label"));
        infoQ3Label->setGeometry(QRect(50, 310, 171, 16));
        infoQ3Label->setFont(font3);
        infoQ4Label = new QLabel(FishInfoPage);
        infoQ4Label->setObjectName(QString::fromUtf8("infoQ4Label"));
        infoQ4Label->setGeometry(QRect(50, 420, 171, 16));
        infoQ4Label->setFont(font3);
        infoA1Label = new QLabel(FishInfoPage);
        infoA1Label->setObjectName(QString::fromUtf8("infoA1Label"));
        infoA1Label->setGeometry(QRect(50, 180, 131, 16));
        QFont font4;
        font4.setItalic(true);
        infoA1Label->setFont(font4);
        infoA2Label = new QLabel(FishInfoPage);
        infoA2Label->setObjectName(QString::fromUtf8("infoA2Label"));
        infoA2Label->setGeometry(QRect(50, 270, 131, 16));
        infoA2Label->setFont(font4);
        infoA3Label = new QLabel(FishInfoPage);
        infoA3Label->setObjectName(QString::fromUtf8("infoA3Label"));
        infoA3Label->setGeometry(QRect(50, 340, 371, 61));
        infoA3Label->setFont(font4);
        infoA4Label = new QLabel(FishInfoPage);
        infoA4Label->setObjectName(QString::fromUtf8("infoA4Label"));
        infoA4Label->setGeometry(QRect(50, 470, 131, 16));
        infoA4Label->setFont(font4);
        nextButtonFI = new QPushButton(FishInfoPage);
        nextButtonFI->setObjectName(QString::fromUtf8("nextButtonFI"));
        nextButtonFI->setGeometry(QRect(670, 480, 91, 61));
        nextFishTestButton = new QPushButton(FishInfoPage);
        nextFishTestButton->setObjectName(QString::fromUtf8("nextFishTestButton"));
        nextFishTestButton->setGeometry(QRect(618, 410, 121, 33));
        stackedWidget->addWidget(FishInfoPage);
        QuizInfoPage = new QWidget();
        QuizInfoPage->setObjectName(QString::fromUtf8("QuizInfoPage"));
        QuizTitleLabel = new QLabel(QuizInfoPage);
        QuizTitleLabel->setObjectName(QString::fromUtf8("QuizTitleLabel"));
        QuizTitleLabel->setGeometry(QRect(336, 30, 101, 41));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(true);
        QuizTitleLabel->setFont(font5);
        QuizTitleLabel->setAlignment(Qt::AlignCenter);
        quizQ1Label = new QLabel(QuizInfoPage);
        quizQ1Label->setObjectName(QString::fromUtf8("quizQ1Label"));
        quizQ1Label->setGeometry(QRect(160, 160, 191, 31));
        quizQ1Label->setFont(font3);
        answ1Button = new QPushButton(QuizInfoPage);
        answ1Button->setObjectName(QString::fromUtf8("answ1Button"));
        answ1Button->setGeometry(QRect(50, 220, 381, 20));
        answ1Button_2 = new QPushButton(QuizInfoPage);
        answ1Button_2->setObjectName(QString::fromUtf8("answ1Button_2"));
        answ1Button_2->setGeometry(QRect(50, 290, 381, 20));
        answ1Button_3 = new QPushButton(QuizInfoPage);
        answ1Button_3->setObjectName(QString::fromUtf8("answ1Button_3"));
        answ1Button_3->setGeometry(QRect(50, 370, 371, 20));
        fishPicLabel = new QLabel(QuizInfoPage);
        fishPicLabel->setObjectName(QString::fromUtf8("fishPicLabel"));
        fishPicLabel->setGeometry(QRect(460, 180, 260, 250));
        quizFishName = new QLabel(QuizInfoPage);
        quizFishName->setObjectName(QString::fromUtf8("quizFishName"));
        quizFishName->setGeometry(QRect(280, 80, 211, 31));
        quizFishName->setFont(font2);
        quizFishName->setAlignment(Qt::AlignCenter);
        resultLabel = new QLabel(QuizInfoPage);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(160, 160, 441, 331));
        QFont font6;
        font6.setPointSize(26);
        font6.setKerning(true);
        resultLabel->setFont(font6);
        resultLabel->setFrameShape(QFrame::StyledPanel);
        resultLabel->setFrameShadow(QFrame::Sunken);
        resultLabel->setTextFormat(Qt::PlainText);
        nextButton = new QPushButton(QuizInfoPage);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(650, 480, 91, 61));
        nextQuestionButton = new QPushButton(QuizInfoPage);
        nextQuestionButton->setObjectName(QString::fromUtf8("nextQuestionButton"));
        nextQuestionButton->setGeometry(QRect(388, 490, 201, 33));
        stackedWidget->addWidget(QuizInfoPage);
        JournalPage_1 = new QWidget();
        JournalPage_1->setObjectName(QString::fromUtf8("JournalPage_1"));
        journalTittleLabel = new QLabel(JournalPage_1);
        journalTittleLabel->setObjectName(QString::fromUtf8("journalTittleLabel"));
        journalTittleLabel->setGeometry(QRect(360, 10, 70, 23));
        journalPageLabel = new QLabel(JournalPage_1);
        journalPageLabel->setObjectName(QString::fromUtf8("journalPageLabel"));
        journalPageLabel->setGeometry(QRect(670, 20, 70, 23));
        journalPicLabel_1 = new QLabel(JournalPage_1);
        journalPicLabel_1->setObjectName(QString::fromUtf8("journalPicLabel_1"));
        journalPicLabel_1->setGeometry(QRect(20, 60, 120, 90));
        journalPicLabel_2 = new QLabel(JournalPage_1);
        journalPicLabel_2->setObjectName(QString::fromUtf8("journalPicLabel_2"));
        journalPicLabel_2->setGeometry(QRect(20, 240, 120, 90));
        journalPicLabel_3 = new QLabel(JournalPage_1);
        journalPicLabel_3->setObjectName(QString::fromUtf8("journalPicLabel_3"));
        journalPicLabel_3->setGeometry(QRect(20, 430, 120, 90));
        journalPicLabel_4 = new QLabel(JournalPage_1);
        journalPicLabel_4->setObjectName(QString::fromUtf8("journalPicLabel_4"));
        journalPicLabel_4->setGeometry(QRect(410, 150, 120, 90));
        journalPicLabel_5 = new QLabel(JournalPage_1);
        journalPicLabel_5->setObjectName(QString::fromUtf8("journalPicLabel_5"));
        journalPicLabel_5->setGeometry(QRect(410, 350, 120, 90));
        journalInfoLabel_1 = new QLabel(JournalPage_1);
        journalInfoLabel_1->setObjectName(QString::fromUtf8("journalInfoLabel_1"));
        journalInfoLabel_1->setGeometry(QRect(150, 60, 230, 90));
        journalInfoLabel_2 = new QLabel(JournalPage_1);
        journalInfoLabel_2->setObjectName(QString::fromUtf8("journalInfoLabel_2"));
        journalInfoLabel_2->setGeometry(QRect(150, 240, 230, 90));
        journalInfoLabel_3 = new QLabel(JournalPage_1);
        journalInfoLabel_3->setObjectName(QString::fromUtf8("journalInfoLabel_3"));
        journalInfoLabel_3->setGeometry(QRect(150, 430, 230, 90));
        journalInfoLabel_4 = new QLabel(JournalPage_1);
        journalInfoLabel_4->setObjectName(QString::fromUtf8("journalInfoLabel_4"));
        journalInfoLabel_4->setGeometry(QRect(540, 150, 230, 90));
        journalInfoLabel_5 = new QLabel(JournalPage_1);
        journalInfoLabel_5->setObjectName(QString::fromUtf8("journalInfoLabel_5"));
        journalInfoLabel_5->setGeometry(QRect(540, 350, 230, 90));
        journalNextButton = new QPushButton(JournalPage_1);
        journalNextButton->setObjectName(QString::fromUtf8("journalNextButton"));
        journalNextButton->setGeometry(QRect(678, 490, 71, 33));
        journalPrevButton = new QPushButton(JournalPage_1);
        journalPrevButton->setObjectName(QString::fromUtf8("journalPrevButton"));
        journalPrevButton->setGeometry(QRect(598, 490, 71, 33));
        journalKeepFishingButton = new QPushButton(JournalPage_1);
        journalKeepFishingButton->setObjectName(QString::fromUtf8("journalKeepFishingButton"));
        journalKeepFishingButton->setGeometry(QRect(30, 30, 131, 33));
        stackedWidget->addWidget(JournalPage_1);
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
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
        smoothPicLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        saltPicLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        freshPicLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        mainMenuMucisButton->setText(QCoreApplication::translate("View", "Music: On", nullptr));
        fish1Label->setText(QCoreApplication::translate("View", "Fish 1", nullptr));
        fish2Label->setText(QCoreApplication::translate("View", "Fish 2", nullptr));
        fish3Label->setText(QCoreApplication::translate("View", "Fish 3", nullptr));
        spearLabel->setText(QCoreApplication::translate("View", "Spear", nullptr));
        locationLabel->setText(QCoreApplication::translate("View", "X: Y:", nullptr));
        catchButton->setText(QCoreApplication::translate("View", "Catch", nullptr));
        goToQuizButton->setText(QCoreApplication::translate("View", "quiz (testing)", nullptr));
        journalButton->setText(QCoreApplication::translate("View", "Journal", nullptr));
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
        nextButtonFI->setText(QCoreApplication::translate("View", "Next", nullptr));
        nextFishTestButton->setText(QCoreApplication::translate("View", "Next Fish Test", nullptr));
        QuizTitleLabel->setText(QCoreApplication::translate("View", "Quiz", nullptr));
        quizQ1Label->setText(QCoreApplication::translate("View", "What is my name? ", nullptr));
        answ1Button->setText(QCoreApplication::translate("View", "PushButton", nullptr));
        answ1Button_2->setText(QCoreApplication::translate("View", "PushButton", nullptr));
        answ1Button_3->setText(QCoreApplication::translate("View", "PushButton", nullptr));
        fishPicLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        quizFishName->setText(QCoreApplication::translate("View", "fish Name", nullptr));
        resultLabel->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        nextButton->setText(QCoreApplication::translate("View", "Next", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("View", "Next Quiz (Test)", nullptr));
        journalTittleLabel->setText(QCoreApplication::translate("View", "Fish", nullptr));
        journalPageLabel->setText(QCoreApplication::translate("View", "Page 1", nullptr));
        journalPicLabel_1->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalPicLabel_2->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalPicLabel_3->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalPicLabel_4->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalPicLabel_5->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalInfoLabel_1->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalInfoLabel_2->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalInfoLabel_3->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalInfoLabel_4->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalInfoLabel_5->setText(QCoreApplication::translate("View", "TextLabel", nullptr));
        journalNextButton->setText(QCoreApplication::translate("View", "Next", nullptr));
        journalPrevButton->setText(QCoreApplication::translate("View", "Prev", nullptr));
        journalKeepFishingButton->setText(QCoreApplication::translate("View", "Keep Fishing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
