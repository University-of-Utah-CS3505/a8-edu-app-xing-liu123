#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <Box2D/Box2D.h>
//#include <QAudio>
#include <QTimer>
#include <QTime>
#include <QMap>
#include "hitlistener.h"
#include <QImage>
#include <QPixmap>
#include <QVector>

enum class TypeOfWater{
    TOW_PondWater,
    TOW_SeaWater,
    TOW_RiverWater
};

enum class SmoothWaterFish{
    SFWF_OceanSunfish,
    SFWF_Stingray,
    SFWF_BullShark,
    SFWF_NilePerch,
    SFWF_Taimen,
    SFWF_AmericanPaddlefish,
    SFWF_AlligatorGar,
    SFWF_BelugaSturgeon,
    SFWF_MekongGiantCatfish,
    SFWF_Arapaima
};

enum class SaltWaterFish{
    SWF_DesignerClownfish,
    SWF_RedSeaPurpleTang,
    SWF_SargassumTriggerfish,
    SWF_LineatusFairyWrasse,
    SWF_LyretailAnthias,
    SWF_FlameAngelfish,
    SWF_EmperorAngelfish,
    SWF_HarlequinTusk,
    SWF_MarineBetta,
    SWF_VolitanLionfish,
};

enum class FreshWaterFish{
    FWF_Platies,
    FWF_ZebraDanios,
    FWF_Rainbowfish,
    FWF_GoldenDwarfBarbs,
    FWF_Angelfish,
    FWF_Goldfish,
    FWF_BettaFish,
    FWF_Mollies,
    FWF_Guppies,
    FWF_NeonTetra
};

// For screen transition
enum class CurrentScreen{
    CS_Start,
    CS_Fishing,
    CS_Journal,
    CS_FishInfo
};

//Different types of spears
enum class TypeOfSpear{
    TOS_Wood,
    TOS_Metal,
    TOS_Beagle
};

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    ~Model();

signals:
    void setUpFish1(int x1, int y1, int x2, int y2);
    void setUpFish2(int x1, int y1, int x2, int y2);
    void setUpFish3(int x1, int y1, int x2, int y2);
    void setUpSpear(int x1, int y1, int x2, int y2);

    void updateQuiz(QString question, QString answer, QString randAnswer1,
                    QString randAnswer2, QString randAnswer3,
                    QString fishPic, QString fishName );
    void updateInformation(QString q1,QString a1, QString q2, QString a2,
                           QString q3, QString a3, QString q4, QString a4,
                           QString fishName, QString fishPic);

   void updateJournal(QVector<QString> info, QVector<QString> questions);


    void sendSpearLabel(QPixmap map);
    void resetSpear(QPixmap map);

    //void sendCollision();

    //check answer
    void answerResult(bool result, QString answer); //result is true if answer is correct


    void sendCountDown(QString time);
    //updates nextlevel progress bar
    void updateNextLevelProgress(int currentProgress, QChar waterType);
    //updates next spear progress bar
    void updateNextSpearProgress(int currentProgress);

    //Discuss with TEAM why private not working
public slots:
    void setUpWorld(QString water);

    void updateWorld();

    void getFish();

    void shotSpear(int x, int y);
    void setSpearLabel(int x, int y);
    //void notifyCollision();

    //Check answer from user
    void checkAnswer(QString question, QString answer);


    //TESTING slots for Info and quiz
    void getTestInfoFish();
    void getTestQuizInfo();

    //Journal set up
    void getJouralInfo(int page);

    void resetWorld();

    //Timer for quiz
    void quizCountDown();
    void updateQuizTime();


private:
    b2World *world;
    b2Body* fish1;
    b2Body* fish2;
    b2Body* fish3;
    b2Body* spear;
    int currentSpear;
    int spearX;
    int spearY;
    int fish1X;
    int fish1Y;
    int fish2X;
    int fish2Y;
    int fish3X;
    int fish3Y;
    int quizTimeCounter;
    QTime *time;
    QTimer *timer;
    QTimer *quizTimer;
    void initFish1();
    void initFish2();
    void initFish3();
    void initSpear();
    QString getRandAnswer(int questionNum, QString question, QString answer);

    HitListener *contactListener;

    QString currFish;
    TypeOfWater waterType;
    TypeOfSpear spearType;
    QMap<QString, int> catchedFish;
    int correctAnsw;
    int correctAnswForProgBar;
//    QString smoothFish[10] = {"Ocean Sunfish",
//                              "Giant Freshwater Stingray",
//                              "Bull Shark",
//                              "Nile Perch",
//                              "Taimen",
//                              "Arapaima",
//                              "Mekong Giant Catfish",
//                              "Beluga Sturgeon",
//                              "Alligator Gar",
//                              "American Paddlefish"};

//    QString saltFish[10] = {"Designer Clownfish",
//                            "Red Sea Purple Tang",
//                            "Sargassum Triggerfish",
//                            "Lineatus Fairy Wrasse",
//                            "Lyretail Anthias",
//                            "Flame Angelfish",
//                            "Emperor Angelfish",
//                            "Harlequin Tusk",
//                            "Marine Betta",
//                            "Volitan Lionfish"};

//    QString freshFish[10] = {"Neon Tetra",
//                             "Guppies",
//                             "Mollies",
//                             "Betta Fish",
//                             "Goldfish",
//                             "Angelfish",
//                             "Golden Dwarf Barbs",
//                             "Rainbowfish",
//                             "Zebra Danios",
//                             "Platies"};

    QVector<QString> pondFish = {"Carp",
                            "Koi",
                            "Goldfish",
                            "Crawfish",
                            "Killifish",
                            "Tadpole",
                            "Catfish",
                            "Giant snakehead",
                            "Alligator Gar",
                            "Frog"};
    QVector<QString> riverFish = {"Bitterling",
                             "Pale chub",
                             "Crucian carp",
                             "Soft-shelled turtle",
                             "Snapping Turtle",
                             "Bluegill",
                             "Yellow perch",
                             "Tilapia",
                             "Pike",
                             "Cherry salmon"};
    QVector<QString> seaFish = {"Sea horse",
                           "Clown fish",
                           "Surgeonfish",
                           "Butterfly fish",
                           "Napoleonfish",
                           "Zebra turkeyfish",
                           "Blowfish",
                           "Puffer fish",
                           "Anchovy",
                           "Saw shark"};

    QVector<QString> questions = {"What is my Name?",
                           "How big can I get?",
                           "Where can you find me?",
                           "Am I an endangered species?"};

    QImage spearImage;
    bool isShot;
    void updateSpear();

    void setJournalVector(QVector<QString> fish, QVector<QString> &info, int page);

    //testing question info
    QMultiMap<QString, QMap<QString, QString> > fishQA;
    QString getRandFish(int randNum);
    void loadInfoQ();


    //TESTING Variable: slots for Info and quiz
    int currInfo = 0;
    int currQuiz = 0;
    int qNum = 0;


    //Holds the value of progess for next level
    int pondProgess = 0;
    int riverProgess = 0;
    int seaProgess = 0; //we don't need this, but if we decided to expand our game it a placeholder for the future.
};

#endif // MODEL_H
