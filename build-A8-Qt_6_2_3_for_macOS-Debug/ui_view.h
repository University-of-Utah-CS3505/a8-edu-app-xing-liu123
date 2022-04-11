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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(800, 600);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 771, 551));
        MainMenuPage = new QWidget();
        MainMenuPage->setObjectName(QString::fromUtf8("MainMenuPage"));
        label = new QLabel(MainMenuPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 411, 261));
        startButton = new QPushButton(MainMenuPage);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(130, 190, 80, 18));
        stackedWidget->addWidget(MainMenuPage);
        FishingPage = new QWidget();
        FishingPage->setObjectName(QString::fromUtf8("FishingPage"));
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
        spearLabel->setGeometry(QRect(300, 0, 61, 101));
        locationLabel = new QLabel(FishingPage);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(580, 10, 131, 16));
        stackedWidget->addWidget(FishingPage);
        JournalPage = new QWidget();
        JournalPage->setObjectName(QString::fromUtf8("JournalPage"));
        label_2 = new QLabel(JournalPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, 10, 451, 301));
        stackedWidget->addWidget(JournalPage);
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        View->setStatusBar(statusbar);

        retranslateUi(View);

        stackedWidget->setCurrentIndex(1);


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
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
