class DZ_LightAI;
class DayZInfected;
class ZombieBase: DayZInfected
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=150;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=30;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=150;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=100;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=100;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=100;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=100;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=100;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=100;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZombieFemaleBase;
class ZombieMaleBase;
class ZmbM_HermitSkinny_Base;
class ZmbM_HermitSkinny_Beige;
class ZmbM_HermitSkinny_Black;
class ZmbM_HermitSkinny_Green;
class ZmbM_HermitSkinny_Red;
class ZmbM_FarmerFat_Base;
class ZmbM_FarmerFat_Beige;
class ZmbM_FarmerFat_Blue;
class ZmbM_FarmerFat_Brown;
class ZmbM_FarmerFat_Green;
class ZmbF_CitizenANormal_Base;
class ZmbF_CitizenANormal_Beige;
class ZmbF_CitizenANormal_Brown;
class ZmbF_CitizenANormal_Blue;
class ZmbM_CitizenASkinny_Base;
class ZmbM_CitizenASkinny_Blue;
class ZmbM_CitizenASkinny_Brown;
class ZmbM_CitizenASkinny_Grey;
class ZmbM_CitizenASkinny_Red;
class ZmbM_CitizenBFat_Base;
class ZmbM_CitizenBFat_Blue;
class ZmbM_CitizenBFat_Red;
class ZmbM_CitizenBFat_Green;
class ZmbF_CitizenBSkinny_Base;
class ZmbF_CitizenBSkinny;
class ZmbM_PrisonerSkinny_Base;
class ZmbM_PrisonerSkinny;
class ZmbM_FirefighterNormal_Base;
class ZmbM_FirefighterNormal;
class ZmbM_FishermanOld_Base;
class ZmbM_FishermanOld_Blue;
class ZmbM_FishermanOld_Green;
class ZmbM_FishermanOld_Grey;
class ZmbM_FishermanOld_Red;
class ZmbM_JournalistSkinny_Base;
class ZmbM_JournalistSkinny;
class ZmbF_JournalistNormal_Base;
class ZmbF_JournalistNormal_Blue;
class ZmbF_JournalistNormal_Green;
class ZmbF_JournalistNormal_Red;
class ZmbF_JournalistNormal_White;
class ZmbM_ParamedicNormal_Base;
class ZmbM_ParamedicNormal_Blue;
class ZmbM_ParamedicNormal_Green;
class ZmbM_ParamedicNormal_Red;
class ZmbM_ParamedicNormal_Black;
class ZmbF_ParamedicNormal_Base;
class ZmbF_ParamedicNormal_Blue;
class ZmbF_ParamedicNormal_Green;
class ZmbF_ParamedicNormal_Red;
class ZmbM_HikerSkinny_Base;
class ZmbM_HikerSkinny_Blue;
class ZmbM_HikerSkinny_Green;
class ZmbM_HikerSkinny_Yellow;
class ZmbF_HikerSkinny_Base;
class ZmbF_HikerSkinny_Blue;
class ZmbF_HikerSkinny_Grey;
class ZmbF_HikerSkinny_Green;
class ZmbF_HikerSkinny_Red;
class ZmbM_JoggerSkinny_Base;
class ZmbM_JoggerSkinny_Blue;
class ZmbM_JoggerSkinny_Green;
class ZmbM_JoggerSkinny_Red;
class ZmbF_JoggerSkinny_Base;
class ZmbF_JoggerSkinny_Blue;
class ZmbF_JoggerSkinny_Brown;
class ZmbF_JoggerSkinny_Green;
class ZmbF_JoggerSkinny_Red;
class ZmbM_MotobikerFat_Base;
class ZmbM_MotobikerFat_Beige;
class ZmbM_MotobikerFat_Black;
class ZmbM_MotobikerFat_Blue;
class ZmbM_VillagerOld_Base;
class ZmbM_VillagerOld_Blue;
class ZmbM_VillagerOld_Green;
class ZmbM_VillagerOld_White;
class ZmbM_SkaterYoung_Base;
class ZmbM_SkaterYoung_Blue;
class ZmbM_SkaterYoung_Brown;
class ZmbM_SkaterYoung_Green;
class ZmbM_SkaterYoung_Grey;
class ZmbF_SkaterYoung_Base;
class ZmbF_SkaterYoung_Brown;
class ZmbF_SkaterYoung_Striped;
class ZmbF_SkaterYoung_Violet;
class ZmbM_HunterOld_Base;
class ZmbM_HunterOld_Autumn;
class ZmbM_HunterOld_Spring;
class ZmbM_HunterOld_Summer;
class ZmbM_HunterOld_Winter;
class ZmbF_SurvivorNormal_Base;
class ZmbF_SurvivorNormal_Blue;
class ZmbF_SurvivorNormal_Orange;
class ZmbF_SurvivorNormal_Red;
class ZmbF_SurvivorNormal_White;
class ZmbM_CommercialPilotOld_Base;
class ZmbM_CommercialPilotOld_Blue;
class ZmbM_CommercialPilotOld_Olive;
class ZmbM_CommercialPilotOld_Brown;
class ZmbM_CommercialPilotOld_Grey;
class ZmbM_PolicemanFat_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=250;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=50;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=400;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_PolicemanFat;
class ZmbF_PoliceWomanNormal_Base: ZombieFemaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=250;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=50;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=400;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbF_PoliceWomanNormal;
class ZmbM_PolicemanSpecForce_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=450;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=80;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_PolicemanSpecForce;
class ZmbM_SoldierNormal_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=550;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=150;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_SoldierNormal;
class ZmbM_usSoldier_normal_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=550;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=150;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_usSoldier_normal_Woodland;
class ZmbM_usSoldier_normal_Desert;
class ZmbM_PatrolNormal_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=550;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=150;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=600;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=700;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_PatrolNormal_PautRev;
class ZmbM_PatrolNormal_Autumn;
class ZmbM_PatrolNormal_Flat;
class ZmbM_PatrolNormal_Summer;
class ZmbF_DoctorSkinny_Base;
class ZmbF_DoctorSkinny;
class ZmbF_BlueCollarFat_Base;
class ZmbF_BlueCollarFat_Blue;
class ZmbF_BlueCollarFat_Green;
class ZmbF_BlueCollarFat_Red;
class ZmbF_BlueCollarFat_White;
class ZmbF_MechanicNormal_Base;
class ZmbF_MechanicNormal_Beige;
class ZmbF_MechanicNormal_Green;
class ZmbF_MechanicNormal_Grey;
class ZmbF_MechanicNormal_Orange;
class ZmbM_MechanicSkinny_Base;
class ZmbM_MechanicSkinny_Blue;
class ZmbM_MechanicSkinny_Grey;
class ZmbM_MechanicSkinny_Green;
class ZmbM_MechanicSkinny_Red;
class ZmbM_ConstrWorkerNormal_Base;
class ZmbM_ConstrWorkerNormal_Beige;
class ZmbM_ConstrWorkerNormal_Black;
class ZmbM_ConstrWorkerNormal_Green;
class ZmbM_ConstrWorkerNormal_Grey;
class ZmbM_HeavyIndustryWorker_Base;
class ZmbM_HeavyIndustryWorker;
class ZmbM_OffshoreWorker_Base;
class ZmbM_OffshoreWorker_Green;
class ZmbM_OffshoreWorker_Orange;
class ZmbM_OffshoreWorker_Red;
class ZmbM_OffshoreWorker_Yellow;
class ZmbF_NurseFat_Base;
class ZmbF_NurseFat;
class ZmbM_HandymanNormal_Base;
class ZmbM_HandymanNormal_Beige;
class ZmbM_HandymanNormal_Blue;
class ZmbM_HandymanNormal_Green;
class ZmbM_HandymanNormal_Grey;
class ZmbM_HandymanNormal_White;
class ZmbM_DoctorFat_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=250;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=50;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=400;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_DoctorFat;
class ZmbM_Jacket_Base;
class ZmbM_Jacket_beige;
class ZmbM_Jacket_black;
class ZmbM_Jacket_blue;
class ZmbM_Jacket_bluechecks;
class ZmbM_Jacket_brown;
class ZmbM_Jacket_greenchecks;
class ZmbM_Jacket_grey;
class ZmbM_Jacket_khaki;
class ZmbM_Jacket_magenta;
class ZmbM_Jacket_stripes;
class ZmbF_PatientOld_Base;
class ZmbF_PatientOld;
class ZmbM_PatientSkinny_Base;
class ZmbM_PatientSkinny;
class ZmbF_ShortSkirt_Base;
class ZmbF_ShortSkirt_beige;
class ZmbF_ShortSkirt_black;
class ZmbF_ShortSkirt_brown;
class ZmbF_ShortSkirt_green;
class ZmbF_ShortSkirt_grey;
class ZmbF_ShortSkirt_checks;
class ZmbF_ShortSkirt_red;
class ZmbF_ShortSkirt_stripes;
class ZmbF_ShortSkirt_white;
class ZmbF_ShortSkirt_yellow;
class ZmbF_VillagerOld_Base;
class ZmbF_VillagerOld_Blue;
class ZmbF_VillagerOld_Green;
class ZmbF_VillagerOld_Red;
class ZmbF_VillagerOld_White;
class ZmbM_Soldier;
class ZmbM_SoldierAlice;
class ZmbM_SoldierHelmet: ZmbM_SoldierNormal_Base
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=1500;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.7;
                        };
                        class Shock
                        {
                            damage=0.7;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_SoldierVest: ZmbM_SoldierNormal_Base
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=1500;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=200;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=1500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_SoldierAliceHelmet: ZmbM_SoldierNormal_Base
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=1500;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.7;
                        };
                        class Shock
                        {
                            damage=0.7;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_SoldierVestHelmet: ZmbM_SoldierNormal_Base
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=1500;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.7;
                        };
                        class Shock
                        {
                            damage=0.7;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=1000;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbF_MilkMaidOld_Base;
class ZmbF_MilkMaidOld_Beige;
class ZmbF_MilkMaidOld_Black;
class ZmbF_MilkMaidOld_Green;
class ZmbF_MilkMaidOld_Grey;
class ZmbM_priestPopSkinny_Base: ZombieMaleBase
{
    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints=250;
                healthLevels[]=
                {
                    
                    {
                        1,
                        {}
                    },
                    
                    {
                        0.69999999,
                        {}
                    },
                    
                    {
                        0.5,
                        {}
                    },
                    
                    {
                        0.30000001,
                        {}
                    },
                    
                    {
                        0,
                        {}
                    }
                };
            };
        };
        class DamageZones
        {
            class Head
            {
                class Health
                {
                    hitpoints=50;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Head",
                    "Neck"
                };
                fatalInjuryCoef=0.1;
                inventorySlots[]=
                {
                    "Headgear",
                    "Mask"
                };
            };
            class Torso
            {
                class Health
                {
                    hitpoints=400;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=1;
                        };
                        class Shock
                        {
                            damage=1;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "Spine1",
                    "Spine3"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Vest",
                    "Body",
                    "Back"
                };
                inventorySlotsCoefs[]={1,1,0.5};
            };
            class LeftArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftArm",
                    "LeftForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class RightArm
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightArm",
                    "RightForeArm"
                };
                fatalInjuryCoef=-1;
            };
            class LeftLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "LeftLeg",
                    "LeftUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class RightLeg
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.33000001;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Shock
                        {
                            damage=0.5;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                componentNames[]=
                {
                    "RightLeg",
                    "RightUpLeg"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Legs"
                };
            };
            class LeftFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "LeftLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "LeftFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
            class RightFoot
            {
                class Health
                {
                    hitpoints=500;
                    transferToGlobalCoef=0.1;
                };
                class ArmorType
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.25;
                        };
                        class Shock
                        {
                            damage=0.25;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=10;
                        };
                    };
                };
                transferToZonesNames[]=
                {
                    "RightLeg"
                };
                transferToZonesCoefs[]={0.1};
                componentNames[]=
                {
                    "RightFoot"
                };
                fatalInjuryCoef=-1;
                inventorySlots[]=
                {
                    "Feet"
                };
            };
        };
    };
};
class ZmbM_priestPopSkinny;
class ZmbM_ClerkFat_Base;
class ZmbM_ClerkFat_Brown;
class ZmbM_ClerkFat_Grey;
class ZmbM_ClerkFat_Khaki;
class ZmbM_ClerkFat_White;
class ZmbF_Clerk_Normal_Base;
class ZmbF_Clerk_Normal_Blue;
class ZmbF_Clerk_Normal_White;
class ZmbF_Clerk_Normal_Green;
class ZmbF_Clerk_Normal_Red;
class ZmbF_ClerkFat_Base;
class ZmbF_ClerkFat_Black;
class ZmbF_ClerkFat_GreyPattern;
class ZmbF_ClerkFat_BluePattern;
class ZmbF_ClerkFat_White;