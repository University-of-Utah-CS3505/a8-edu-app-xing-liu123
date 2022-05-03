#ifndef MODEL_H
#define MODEL_H


/**
 * Team: BAGJL
 * Students: Brittney Morales, Adriana Salazar, Xing Liu, Jinwen Lei, Gonzalo Tello
 * Course: CS3505
 * Date: April 26, 2022
 *
 **/

#include <Box2D/Box2D.h>
#include "hitlistener.h"
#include <QObject>
#include <QTimer>
#include <QMap>
#include <QImage>
#include <QPixmap>
#include <QVector>
#include <QFile>
#include <QTextStream>

enum class TypeOfWater{
    TOW_PondWater,
    TOW_SeaWater,
    TOW_RiverWater
};

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    ~Model();



signals:
    //WOrld object set up
    void setUpFish1(int x1, int y1, int x2, int y2);
    void setUpFish2(int x1, int y1, int x2, int y2);
    void setUpFish3(int x1, int y1, int x2, int y2);
    void setUpSpear(int x1, int y1, int x2, int y2);

    //Updates of pages
    void sendCountDown(QString time);
    void updateQuiz(QString question, QString answer, QString randAnswer1,
                    QString randAnswer2, QString randAnswer3,
                    QString fishPic, QString fishName );
    void updateInformation(QString q1,QString a1, QString q2, QString a2,
                           QString q3, QString a3, QString q4, QString a4,
                           QString fishName, QString fishPic);
    void updateJournal(QVector<QString> info);

    //Spear
    void sendSpearLabel(QPixmap map);
    void resetSpear(QPixmap map);

    //Sound effect
    void sendSoundEffect();
    void sendShootEffect();

    //check answer
    void answerResult(bool result, QString answer); //result is true if answer is correct

    //Progress bar
    void updateNextLevelProgress(int currentProgress, QChar waterType);
    void updateNextSpearProgress(int currentProgress);

    //update Spear labe
    void updateSpearLabel(int spearNumber);


public slots:
    //World
    void setUpWorld(QString water);
    void updateWorld();
    void resetWorld();
    //spear
    void setSpearLabel(int x, int y);
    void shotSpear(int x, int y);
    // Catch fish
    void getFish();
    //Timer for quiz
    void quizCountDown();
    void updateQuizTime();
    //Check answer from user
    void checkAnswer(QString question, QString answer);
    //Journal set up
    void getJouralInfo(int page);

    //TESTING slots for Info and quiz
    void getTestInfoFish();
    void getTestQuizInfo();


private:
    b2World *world;

    //objects in the physical world
    b2Body* fish1;
    b2Body* fish2;
    b2Body* fish3;
    b2Body* spear;

    // information of objects
    int currentSpear;
    int spearX;
    int spearY;
    int fish1X;
    int fish1Y;
    int fish2X;
    int fish2Y;
    int fish3X;
    int fish3Y;
    QImage spearImage;
    bool isShot;    
    HitListener *contactListener;

    // timers
    int quizTimeCounter;
    QTimer *timer;
    QTimer *quizTimer;

    //Answer and progress info
    int correctAnsw;
    int correctAnswForProgBar;
    int pondProgess = 0;
    int riverProgess = 0;
    int seaProgess = 0; //we don't need this, but if we decided to expand our game it a placeholder for the future.

    //Fish information
    QVector<QString> pondFish;
    QVector<QString> riverFish;
    QVector<QString> seaFish;
    QVector<QString> questions;
    QString currFish;
    TypeOfWater waterType;
    QVector<QString> catchedFish;

    //Helper method
    void initFish1();
    void initFish2();
    void initFish3();
    void initSpear();
    void updateSpear();
    void setJournalVector(QVector<QString> fish, QVector<QString> &info, int page);
    QString getRandAnswer(int questionNum, QString question, QString answer,
                          QString randAns1, QString randAns2);


    //testing question info
    QMultiMap<QString, QMap<QString, QString> > fishQA;
    QString getRandFish(int randNum);
    void loadInfoQ();

    //TESTING Variable: slots for Info and quiz
    int currInfo = 0;
    int currQuiz = 0;
    int qNum = 0;
};

#endif // MODEL_H
