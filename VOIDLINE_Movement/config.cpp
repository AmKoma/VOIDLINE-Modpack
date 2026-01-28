class CfgPatches
{
	class VOIDLINE_Movement
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "RevGuns", "TerjeRadiation"};
	};
};

class CfgMods
{
	class VOIDLINE_Movement
	{
		dir = "VOIDLINE_Movement";
		hideName = 1;
		hidePicture = 1;
		name = "VOIDLINE Movement";
		credits = "KOMA";
		author = "KOMA";
		version = "4.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"VOIDLINE_Movement/Scripts/4_World"};
			};
		};
	};
};