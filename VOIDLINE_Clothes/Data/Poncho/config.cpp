class CfgPatches
{
	class Voidline_CamoNetPoncho
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters"};
		units[] = {"Voidline_CamoNetPoncho","Black_CamoNetPoncho","White_CamoNetPoncho","Brown_CamoNetPoncho", "KOMA_CamoNetPoncho"};
	};
};

class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class Voidline_CamoNetPoncho_Base: Clothing
	{
		scope = 0;
		displayName = "Move along";
		descriptionShort = "Nothing to see here";
		model = "VOIDLINE_Clothes\Data\Poncho\CamoNetPoncho_g.p3d";
		inventorySlot[] = {"Armband"};
		weight = 150;
		itemSize[] = {3,2};
		absorbency = 0.3;
		heatIsolation = 0.5;
		varWetMax = 0.79;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,50.0};
		hiddenSelections[] = {"color"};
		class ClothingTypes
		{
			male = "VOIDLINE_Clothes\Data\Poncho\CamoNetPoncho.p3d";
			female = "VOIDLINE_Clothes\Data\Poncho\CamoNetPoncho.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\camonet_east_nowind.rvmat"}},{0.7,{"DZ\gear\camping\data\camonet_east_nowind.rvmat"}},{0.5,{"DZ\gear\camping\data\camonet_east_nowind.rvmat"}},{0.3,{"DZ\gear\camping\data\camonet_east_nowind.rvmat"}},{0.0,{"DZ\gear\camping\data\camonet_east_nowind.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Voidline_CamoNetPoncho: Voidline_CamoNetPoncho_Base
	{
		scope = 2;
		displayName = "Improvised Camo Net Poncho";
		descriptionShort = "Very simple-made and effective thing.";
		hiddenSelectionsTextures[] = {"dz\structures\military\improvised\data\camonet_east_co.paa"};
	};
	class Black_CamoNetPoncho: Voidline_CamoNetPoncho_Base
	{
		scope = 2;
		displayName = "Black Improvised Camo Net Poncho";
		descriptionShort = "Very simple-made and effective thing.";
		hiddenSelectionsTextures[] = {"VOIDLINE_Clothes\Data\Poncho\camonet_black_co.paa"};
	};
	class White_CamoNetPoncho: Voidline_CamoNetPoncho_Base
	{
		scope = 2;
		displayName = "White Improvised Camo Net Poncho";
		descriptionShort = "Very simple-made and effective thing.";
		hiddenSelectionsTextures[] = {"VOIDLINE_Clothes\Data\Poncho\camonet_white_co.paa"};
	};
	class Brown_CamoNetPoncho: Voidline_CamoNetPoncho_Base
	{
		scope = 2;
		displayName = "Brown Improvised Camo Net Poncho";
		descriptionShort = "Very simple-made and effective thing.";
		hiddenSelectionsTextures[] = {"VOIDLINE_Clothes\Data\Poncho\camonet_brown_co.paa"};
	};
	class KOMA_CamoNetPoncho: Voidline_CamoNetPoncho_Base
	{
		scope = 2;
		displayName = "KOMA Camo Net Poncho";
		descriptionShort = "Exclusive for KOMA Clan";
		hiddenSelectionsTextures[] = {"VOIDLINE_Clothes\Data\Poncho\camonet_koma_co.paa"};
	};
};
