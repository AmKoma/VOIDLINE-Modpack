class CfgPatches
{
	class VOIDLINE_Storage
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "RevGuns", "TerjeRadiation"};
	};
};

class CfgMods
{
	class VOIDLINE_Storage
	{
		dir = "VOIDLINE_Storage";
		hideName = 1;
		hidePicture = 1;
		name = "VOIDLINE Storage";
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
				files[] = {"VOIDLINE_Storage/Scripts/4_World"};
			};
		};
	};
};