#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>
#include "model.h"
#include <QMouseEvent>
#include <QHoverEvent>
#include <QPixmap>
#include <iostream>

// Uncomment this when working on audios
//#include <QMediaPlayer>
//#include <QAudioOutput>
//#include <QAudioDevice>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model &model, QWidget *parent = nullptr);
    ~View();

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    // Uncomment this when working on audios
//    void updateMainMenuMusicButton(QString str);

    void newPositiontValue(int height, int width);
    void updateWorld(QString water);
    void shootSpear(int x, int y);
    void sendPosition(int x, int y);
    void resetWorld();

    //answer
    void checkUserAnswer(QString question, QString answer);
    void getJournal(int pageNum);

private slots:
    // Uncomment this when working on audios
//    void playBGM(QMediaPlayer::MediaStatus status);
//    void pressMusicButton();

    void displayFish1(int x1, int y1, int x2, int y2);
    void displayFish2(int x1, int y1, int x2, int y2);
    void displayFish3(int x1, int y1, int x2, int y2);
    void displaySpear(int x1, int y1, int x2, int y2);
    void updateSpearLabel(QPixmap map);
    void resetSpearLabel(QPixmap map);

    void setUpQuiz(QString question, QString answer, QString randAnswer1,
                   QString randAnswer2, QString fishPic, QString fishName);
    void setUpInfo(QString q1,QString a1, QString q2, QString a2,
                   QString q3, QString a3, QString q4, QString a4,
                   QString fishName, QString fishPic);

    void on_startButton_clicked();
    void on_freshWaterButton_clicked();
    void on_smoothWaterButton_clicked();
    void on_saltWaterButton_clicked();

    //correct answer
    void on_answerButton1_clicked();
    void on_answerButton2_clicked();
    void on_answerButton3_clicked();
    void showResult(bool result);

    // goback to fishing screen
    void on_nextButton_clicked();
    void on_nextButtonFI_clicked();

    //display on Journal
    void setUpJournal(int fishNum, QChar waterLetter,
                       QString a1, QString a2,
                       QString a3, QString a4,
                       QString fishName, QString fishPic);


    void on_journalButton_clicked();

    void on_journalNextButton_clicked();

    void on_journalPrevButton_clicked();

    void on_return2FishButton_clicked();

    void on_return2MenuButton_clicked();

private:
    Ui::View *ui;
    QTimer * time;
    QImage spearImage;
    int const startPage = 0;
    int const fishingPage = 1;
    int const InfoPage = 3;
    int const quizPage = 4;
    int const journalPage = 5;
    void setUpAnswers(QString answer, QString randAnswer1, QString randAnswer2);
    void displayTittlePage(QChar waterLetter, int fishNum);
    void displayJournalLabels(QString info, QString fishPic, int fishNum);
    int journalPageNum = 0;



    // Uncomment this when working on audios
//    QMediaPlayer* bgmPlayer = new QMediaPlayer;
//    QAudioOutput* bgmOutput = new QAudioOutput;
//    QAudioOutput* soundEffectOutput = new QAudioOutput;
//    QAudioDevice* audioDevice = new QAudioDevice;
};
#endif // VIEW_H


