class CfgPatches
{
    class VOIDLINE_GearAdjustments
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Characters_Backpacks", "DZ_Scripts", "DZ_Characters", "JPC_Vest"};
    };
};

class CfgMods
{
    class VOIDLINE_GearAdjustments
    {
        dir = "VOIDLINE_GearAdjustments";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "VOIDLINE GearAdjustments";
        author = "KOMA";
        credits = "ReDos";
        version = "1.0";
        extra = 0;
        type = "mod";
    };
};

class CfgVehicles
{
    #include "Gear\Classes.hpp"
	#include "Gear\MMG_Gear.hpp"
    #include "Gear\Windstride_Gear.hpp"
};