#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <Box2D/Box2D.h>
//#include <QAudio>
#include <QTimer>
#include <QMap>
#include "hitlistener.h"
#include <QImage>
#include <QPixmap>

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
    void sendSpearLabel(QPixmap map);
    void sendCollision();



//Discuss with TEAM why private not working
public slots:
    void setUpWorld();
    void updateFish1();
    void updateFish2();
    void updateFish3();
    void updateSpear();
    void startTimer(int x, int y);
    void setSpearLabel(int x, int y);
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
    HitListener *contactListener;
    QImage spearImage;
    bool isShot;


    //testing question info
    QMultiMap<QString, QMap<QString, QString> > fishQA;

    void loadInfoQ();

};

#endif // MODEL_H
