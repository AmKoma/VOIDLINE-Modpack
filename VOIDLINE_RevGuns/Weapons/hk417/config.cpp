class CfgPatches
{
    class RevCDX50
    {
        units[] = {};
        weapons[] = {"Rev_HK417"};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Weapons_Firearms", "DZ_Weapons_Magazines", "DZ_Sounds_Effects"};
        attachments[] = {};
    };
};

class cfgWeapons
{
    class Rev_HK417_Base;
    class eAI_HK417 : Rev_HK417_Base
    {
        scope = 2;
        descriptionShort = "This weapon belonged to a bot... To pick it up, you must break the Matrix.";
        hiddenSelectionsTextures[] = {"RevGuns\Weapons\HK417\data\front_co.paa", "RevGuns\Weapons\HK417\data\rear_co.paa", "RevGuns\Weapons\HK417\data\stock_co.paa"};
    }
}