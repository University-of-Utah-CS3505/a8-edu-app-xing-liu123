#ifndef MODEL_H
#define MODEL_H

#include <QObject>

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

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

signals:


};

#endif // MODEL_H
