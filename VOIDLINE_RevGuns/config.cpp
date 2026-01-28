class CfgPatches
{
	class VOIDLINE_RevGuns
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "RevGuns", "TerjeRadiation"};
	};
};

class CfgMods
{
	class VOIDLINE_RevGuns
	{
		dir = "VOIDLINE_RevGuns";
		hideName = 1;
		hidePicture = 1;
		name = "VOIDLINE RevGuns";
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
				files[] = {"VOIDLINE_RevGuns/Scripts/4_World"};
			};
		};
	};
};

/*class CfgMagazines
{
	class Magazine_Base;
	class Ammunition_Base: Magazine_Base{};
	class Ammo_45ACP: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_308Win: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_308WinTracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_9x19: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_380: Ammunition_Base
	{
		count = 140;
	};
	class Ammo_556x45: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_556x45Tracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_762x54: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_762x54Tracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_762x39: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_762x39Tracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_9x39: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_9x39AP: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_22: Ammunition_Base
	{
		count = 200;
	};
	class Ammo_12gaPellets: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_12gaSlug: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_12gaRubberSlug: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_357: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_545x39: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_545x39Tracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_ArrowComposite: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_SharpStick: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_ArrowPrimitive: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_ArrowBoned: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_ArrowBolt: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_DartSyringe: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_Flare: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_FlareBlue: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_FlareRed: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_FlareGreen: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_RPG7_HE: Ammunition_Base
	{
		count = 4;
	};
	class Ammo_RPG7_AP: Ammunition_Base
	{
		count = 4;
	};
	class Ammo_LAW_HE: Ammunition_Base
	{
		count = 4;
	};
	class Ammo_GrenadeM4: Ammunition_Base
	{
		count = 4;
	};
	class Ammo_46x30: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_8mm: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_338: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_408Chey: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_12GaBB: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_303: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_12gaNeedles: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_FUGAS: Ammunition_Base
	{
		count = 4;
	};
	class Ammo_12gaPellets_tracer: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_4x30: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_338Tracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_408: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_408Tracer: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_792x33: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_12_7x55: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_12x99: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_12x99Tracer_Green: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_12x99Tracer_Yell: Ammunition_Base
	{
		count = 40;
	};
	class Ammo_nails: Ammunition_Base
	{
		count = 200;
	};
	class Ammo_762x25: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_5_7x28: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_5_7x28Tracer: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_762x33: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_792x57: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_9x18: Ammunition_Base
	{
		count = 100;
	};
	class Ammo_shock: Ammunition_Base
	{
		count = 4;
	};
	class Expansion_Ammo_8mm: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_Expansion_338: Ammunition_Base
	{
		count = 60;
	};
	class Ammo_Expansion_46x30: Ammunition_Base
	{
		count = 100;
	};
	class Expansion_Ammo_ArrowBolt: Ammunition_Base
	{
		count = 20;
	};
	class Rev_Ammo_ImprovisedArrow: Ammunition_Base
	{
		count = 20;
	};
	class Rev_Ammo_Arrow: Ammunition_Base
	{
		count = 20;
	};
	class Rev_Ammo_Bolt: Ammunition_Base
	{
		count = 20;
	};
	class Ammo_300WinMagnum: Ammunition_Base
	{
		count = 80;
	};
	class Rev_Ammo_408: Ammunition_Base
	{
		count = 60;
	};
	class Rev_Ammo_68SPC: Ammunition_Base
	{
		count = 120;
	};
	class Rev_Ammo_338: Ammunition_Base
	{
		count = 80;
	};
	class Rev_Ammo_300BO: Ammunition_Base
	{
		count = 80;
	};
	class Ammo_12x7mm: Ammunition_Base
	{
		count = 20;
	};
	class Rev_Ammo_50BMG: Ammunition_Base
	{
		count = 25;
	}
};
*/