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
    QPushButton *startButton;
    QWidget *FishingPage;
    QLabel *fish1Label;
    QLabel *fish2Label;
    QLabel *fish3Label;
    QLabel *spearLabel;
    QLabel *locationLabel;
    QWidget *JournalPage;
    QLabel *label_2;
    QWidget *FishInfoPage;
    QWidget *QuizInfoPage;
    QLabel *QuizTitleLabel;
    QLabel *question1Label;
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
        stackedWidget->setGeometry(QRect(0, 0, 771, 551));
        stackedWidget->setMouseTracking(true);
        MainMenuPage = new QWidget();
        MainMenuPage->setObjectName(QString::fromUtf8("MainMenuPage"));
        MainMenuPage->setMouseTracking(false);
        label = new QLabel(MainMenuPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 411, 261));
        startButton = new QPushButton(MainMenuPage);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(130, 190, 161, 81));
        stackedWidget->addWidget(MainMenuPage);
        FishingPage = new QWidget();
        FishingPage->setObjectName(QString::fromUtf8("FishingPage"));
        FishingPage->setMouseTracking(true);
        fish1Label = new QLabel(FishingPage);
        fish1Label->setObjectName(QString::fromUtf8("fish1Label"));
        fish1Label->setGeometry(QRect(40, 300, 111, 81));
        fish1Label->setMouseTracking(true);
        fish2Label = new QLabel(FishingPage);
        fish2Label->setObjectName(QString::fromUtf8("fish2Label"));
        fish2Label->setGeometry(QRect(30, 390, 111, 71));
        fish2Label->setMouseTracking(true);
        fish3Label = new QLabel(FishingPage);
        fish3Label->setObjectName(QString::fromUtf8("fish3Label"));
        fish3Label->setGeometry(QRect(30, 480, 111, 61));
        fish3Label->setMouseTracking(true);
        spearLabel = new QLabel(FishingPage);
        spearLabel->setObjectName(QString::fromUtf8("spearLabel"));
        spearLabel->setGeometry(QRect(325, 0, 150, 150));
        spearLabel->setMouseTracking(true);
        locationLabel = new QLabel(FishingPage);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(580, 10, 131, 16));
        locationLabel->setMouseTracking(true);
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
        stackedWidget->addWidget(FishInfoPage);
        QuizInfoPage = new QWidget();
        QuizInfoPage->setObjectName(QString::fromUtf8("QuizInfoPage"));
        QuizTitleLabel = new QLabel(QuizInfoPage);
        QuizTitleLabel->setObjectName(QString::fromUtf8("QuizTitleLabel"));
        QuizTitleLabel->setGeometry(QRect(336, 30, 101, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        QuizTitleLabel->setFont(font);
        QuizTitleLabel->setAlignment(Qt::AlignCenter);
        question1Label = new QLabel(QuizInfoPage);
        question1Label->setObjectName(QString::fromUtf8("question1Label"));
        question1Label->setGeometry(QRect(50, 120, 191, 31));
        QFont font1;
        font1.setBold(true);
        question1Label->setFont(font1);
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
        menubar->setGeometry(QRect(0, 0, 800, 19));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        View->setStatusBar(statusbar);

        retranslateUi(View);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        label->setText(QString());
        startButton->setText(QCoreApplication::translate("View", "Start", nullptr));
        fish1Label->setText(QCoreApplication::translate("View", "Fish 1", nullptr));
        fish2Label->setText(QCoreApplication::translate("View", "Fish 2", nullptr));
        fish3Label->setText(QCoreApplication::translate("View", "Fish 3", nullptr));
        spearLabel->setText(QCoreApplication::translate("View", "Spear", nullptr));
        locationLabel->setText(QCoreApplication::translate("View", "X: Y:", nullptr));
        label_2->setText(QString());
        QuizTitleLabel->setText(QCoreApplication::translate("View", "Quiz", nullptr));
        question1Label->setText(QCoreApplication::translate("View", "What is my name? ", nullptr));
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
