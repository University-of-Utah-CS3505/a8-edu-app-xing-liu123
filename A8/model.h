#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <Box2D/Box2D.h>
//#include <QAudio>
#include <QTimer>
#include <QMap>
#include "hitlistener.h"

enum class TypeOfWater{
    TOW_FreshWater,
    TOW_SaltWater,
    TOW_SmoothWater
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

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    ~Model();

signals:
    void setUpFish1(int x, int y);
    void setUpFish2(int x, int y);
    void setUpFish3(int x, int y);
    void setUpSpear(int x1, int y1, int x2, int y2);
    void startTime();

    void updateQuiz(QString question, QString answer, QString randAnswer1,
                   QString randAnswer2, QString fishPic );
    void updateInformation(QString q1,QString a1, QString q2, QString a2,
                           QString q3, QString a3, QString q4, QString a4,
                           QString fish);

    void sendCollision();




//Discuss with TEAM why private not working
public slots:
    void setUpWorld(QString water);
    void updateFish1();
    void updateFish2();
    void updateFish3();
    void updateSpear();
    void getFish();

    void startTimer(float x, float y);
    void notifyCollision();



private:
    b2World *world;
    b2Body* fish1;
    b2Body* fish2;
    b2Body* fish3;
    b2Body* spear;
    int spearX;
    int spearY;
    QTimer timer;
    void initFish1();
    void initFish2();
    void initFish3();
    void initSpear();
    QString getRandAnswers(int questionNum, QString question, QString answer);

    HitListener *contactListener;
    QString currFish;
    SmoothWaterFish smoothCurrFish; //default 0
    SaltWaterFish saltCurrFish; //default 0
    FreshWaterFish freshCurrFish; //default 0
    TypeOfWater waterType;
    QMap<QString, int> catchedFish;
    QString smoothFish[10] = {"Ocean Sunfish",
                              "Giant Freshwater Stingray",
                              "Bull Shark",
                              "Nile Perch",
                              "Taimen",
                             "Arapaima",
                              "Mekong Giant Catfish",
                              "Beluga Sturgeon",
                             "Alligator Gar",
                              "American Paddlefish"};

    QString saltFish[10] = {"Designer Clownfish",
                            "Red Sea Purple Tang",
                            "Sargassum Triggerfish",
                            "Lineatus Fairy Wrasse",
                            "Lyretail Anthias",
                            "Flame Angelfish",
                            "Emperor Angelfish",
                            "Harlequin Tusk",
                             "Marine Betta",
                            "Volitan Lionfish"};

    QString freshFish[10] = {"Neon Tetra",
                             "Guppies",
                             "Mollies",
                             "Betta Fish",
                             "Goldfish",
                             "Angelfish",
                             "Golden Dwarf Barbs",
                             "Rainbowfish",
                             "Zebra Danios",
                             "Platies"};



    //testing question info
    QMultiMap<QString, QMap<QString, QString> > fishQA;

    void loadInfoQ();

};

#endif // MODEL_H
