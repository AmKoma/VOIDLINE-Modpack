class CfgPatches
{
	class VOIDLINE_Zombies
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters"
		};
	};
};

class CfgMods
{
    class VOIDLINE_Zombies
    {
        dir = "VOIDLINE_Zombies";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "VOIDLINE Zombies";
        author = "KOMA";
        credits = "";
        version = "1.0";
        extra = 0;
        type = "mod";
    };
};

class CfgVehicles
{
	#include "Zombies\DayZInfected.hpp"
};