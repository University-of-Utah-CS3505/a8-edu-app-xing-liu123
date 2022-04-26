#ifndef VIEW_H
#define VIEW_H

/**
 * Team: BAGJL
 * Students: Brittney Morales, Adriana Salazar, Xing Liu, Jinwen Lei, Gonzalo Tello
 * Course: CS3505
 * Date: April 26, 2022
 *
 **/

#include <QMainWindow>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>
#include "model.h"
#include <QMouseEvent>
#include <QHoverEvent>
#include <QPixmap>
#include <iostream>
#include <QCloseEvent>
#include <QPropertyAnimation>
#include <QApplication>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(Model &model, QWidget *parent = nullptr);
    ~View();

    //Mouse events
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void updateWorld(QString water);
    void resetWorld();
    void shootSpear(int x, int y);
    void sendPosition(int x, int y);
    void newPositiontValue(int height, int width);
    void getJournal(int pageNum);
    void checkUserAnswer(QString question, QString answer);
    void updateMainMenuMusicButton(QString str);

private slots:
    //Music
    void playBGM(QMediaPlayer::MediaStatus status);
    void pressMusicButton();
    void playHitSoundEffect();
    void playShootSoundEffect();

    //Fish
    void displayFish1(int x1, int y1, int x2, int y2);
    void displayFish2(int x1, int y1, int x2, int y2);
    void displayFish3(int x1, int y1, int x2, int y2);
    void displaySpear(int x1, int y1, int x2, int y2);

    //Spear
    void updateSpearLabel(QPixmap map);
    void resetSpearLabel(QPixmap map);

    //Quuiz and Info windows
    void setUpQuiz(QString question, QString answer, QString randAnswer1,
                   QString randAnswer2, QString randAnswer3,
                   QString fishPic, QString fishName);
    void setUpInfo(QString q1,QString a1, QString q2, QString a2,
                   QString q3, QString a3, QString q4, QString a4,
                   QString fishName, QString fishPic);

    //Choosing water
    void on_startButton_clicked();
    void on_freshWaterButton_clicked();
    void on_smoothWaterButton_clicked();
    void on_saltWaterButton_clicked();

    //Correct answer
    void on_answerButton1_clicked();
    void on_answerButton2_clicked();
    void on_answerButton3_clicked();
    void on_answ1Button_4_clicked();
    void showResult(bool result, QString Answer);

    // Journal
    void on_journalButton_clicked();
    void on_journalNextButton_clicked();
    void on_journalPrevButton_clicked();    
    void on_journalKeepFishingButton_clicked();
    void setUpJournal(QVector<QString> info);
    void updateNextLevelProgress(int progess, QChar waterType);

    //Moving to different windows
    void on_return2FishButton_clicked();
    void on_return2MenuButton_clicked();
    void on_quizBackFishButton_clicked();
    void on_infoBackButton_clicked();  

    //Action Buttons
    void on_startGameButton_clicked();
    void on_howToPlayButton_clicked();
    void on_goToMainMenuPageButton_clicked();
    void on_closeCongratsButton_clicked();

    //Set up count down
    void displayCountDown(QString time);
    //updates next spear progress bar
    void updateNextSpearProgress(int currentProgress);
    //Check before closing
    void closeEvent(QCloseEvent *event);

private:
    Ui::View *ui;
    QTimer * time;
    QImage spearImage;

    // Pages (Widget) Number
    int const startPage = 0;
    int const fishingPage = 1;
    int const infoPage = 2;
    int const quizPage = 3;
    int const journalPage = 4;
    int const startMenuPage = 5;
    int const helpMenuPage = 6;

    // Progress for levels
    int pondProgess = 0;
    int riverProgess = 0;
    int seaProgess = 0;

    // Number of the current page in the journal
    int journalPageNum = 0;

    // Audio parameters
    const float32 audioVolumn = 0.2f;

    //Sound
    bool soundOn = true;
    float const sound = 0.25f;
    int const interval = 25;


    // Background music
    QMediaPlayer *bgmPlayer;
    QAudioOutput *bgmOutput;
    int mapNumber = 1;

    // Sound Effects
    QSoundEffect *shootEffect;
    QSoundEffect *hitEffect;

    // Animation
    QPropertyAnimation *fishAnimation1;
    QPropertyAnimation *fishAnimation2;
    QPropertyAnimation *fishAnimation3;
    QPropertyAnimation *spearAnimation;

    // Helper methods
    void setUpAnswers(QString answer, QString randAnswer1, QString randAnswer2);
    void displayJournalLabels(QString info, QString fishPic, int fishNum);
    void setButtonQuizVisibility(QString answ);
    void disableQuizButtons();




};
#endif // VIEW_H


