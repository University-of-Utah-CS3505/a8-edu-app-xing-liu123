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
#include <QCloseEvent>
#include <QPropertyAnimation>


// Uncomment this when working on audios
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

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    // Uncomment this when working on audios
    void updateMainMenuMusicButton(QString str);

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
    void playBGM(QMediaPlayer::MediaStatus status);
    void pressMusicButton();

    void displayFish1(int x1, int y1, int x2, int y2);
    void displayFish2(int x1, int y1, int x2, int y2);
    void displayFish3(int x1, int y1, int x2, int y2);
    void displaySpear(int x1, int y1, int x2, int y2);
    void updateSpearLabel(QPixmap map);
    void resetSpearLabel(QPixmap map);
    void playHitSoundEffect();
    void playShootSoundEffect();

    void setUpQuiz(QString question, QString answer, QString randAnswer1,
                   QString randAnswer2, QString randAnswer3,
                   QString fishPic, QString fishName);
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
    void showResult(bool result, QString Answer);

    //display on Journal
    void setUpJournal(QVector<QString> info, QVector<QString> questions);
    void updateNextLevelProgress(int progess, QChar waterType);

    //updates next spear progress bar
    void updateNextSpearProgress(int currentProgress);

    void on_journalButton_clicked();

    void on_journalNextButton_clicked();

    void on_journalPrevButton_clicked();

    void on_return2FishButton_clicked();

    void on_return2MenuButton_clicked();
    void on_journalKeepFishingButton_clicked();

    void on_quizBackFishButton_clicked();

    void on_infoBackButton_clicked();

    void on_closeCongratsButton_clicked();

    void on_answ1Button_4_clicked();

    //Set up count down
    void displayCountDown(QString time);

    //Check before closing
    void closeEvent(QCloseEvent *event);

    //start game button
    void on_startGameButton_clicked();

private:
    Ui::View *ui;
    QTimer * time;
    QImage spearImage;
    int const startPage = 0;
    int const fishingPage = 1;
    int const infoPage = 2;
    int const quizPage = 3;
    int const journalPage = 4;
    int const startMenuPage = 5;
    void setUpAnswers(QString answer, QString randAnswer1, QString randAnswer2);
    void displayJournalLabels(QString info, QString fishPic, int fishNum);
    int journalPageNum = 0;
    void setButtonQuizVisibility(QString answ);
    void disableQuizButtons();

    // Uncomment this when working on audios

    // Audio parameters
    const float32 audioVolumn = 0.2f;

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

    //progress for levels
    int pondProgess = 0;
    int riverProgess = 0;
    int seaProgess = 0;

};
#endif // VIEW_H


