class CfgPatches
{
	class RevM110
	{
		units[] = {};
		weapons[] = {"Rev_M110_Tan","Rev_M110_Black","Rev_SR25_Tan","Rev_SR25_Black"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Firearms","DZ_Sounds_Effects","DZ_Weapons_Magazines"};
		magazines[] = {"Rev_Mag_M110_10rnd","Rev_Mag_M110_20rnd","Rev_Mag_SR25_10rnd","Rev_Mag_SR25_20rnd"};
	};
};

class cfgWeapons
{
    class BoltActionRifle_Base;
    class Rev_M110_Base: BoltActionRifle_Base {
		displayName = "M110";
		descriptionShort = "Die M110 ist ein halbautomatisches Scharfschützengewehr im Kaliber .308 Winchester. Sie bietet hohe Präzision auf mittlere bis große Distanz und kombiniert Feuerkraft mit schneller Schussfolge. Ausgestattet mit Montageschienen ist sie kompatibel mit verschiedenen Optiken, Schalldämpfern und Anbauteilen. Die Waffe zeichnet sich durch ihre Zuverlässigkeit und Effektivität in taktischen Einsätzen aus.";
		WeaponLength = 1.0;
		class SemiAuto
		{
			soundSetShot[] = {"New_M110_Shot_SoundSet","Winchester70_Shot_iterior_SoundSet","Winchester70_Tail_SoundSet","Winchester70_InteriorTail_SoundSet","Winchester70_Tail_2D_SoundSet"};
			soundSetShotExt[] = {{"New_M110_Supressed_Shot_SoundSet","Winchester70_silencerHomeMadeTail_SoundSet","Winchester70_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.15;
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
	}
	class eAI_M110 : Rev_M110_Base
	{
		scope = 2;
		descriptionShort = "This weapon belonged to a bot... To pick it up, you must break the Matrix.";
		hiddenSelectionsTextures[] = {"RevGuns\Weapons\M110\data\m110_co.paa"};
	}
}

class CfgSoundShaders
{
	class base_closeShot_SoundShader;
	class base_midShot_SoundShader;
	class base_distShot_SoundShader;
	class New_M110_closeShot_SoundShader: base_closeShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m110\sounds\m110_close",1}};
		volume = 0.8;
	};
	class New_M110_midShot_SoundShader: base_midShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m110\sounds\m110_mid",1}};
		volume = 0.5;
	};
	class New_M110_distShot_SoundShader: base_distShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m110\sounds\m110_far",1}};
		volume = 0.35;
	};

	class New_M110_SupressedcloseShot_SoundShader: base_closeShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m110\sounds\m110_suppressed_close",1}};
		volume = 0.8;
	};
	class New_M110_SupressedmidShot_SoundShader: base_midShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m110\sounds\m110_suppressed_mid",1}};
		volume = 0.5;
	};
	class New_M110_SupresseddistShot_SoundShader: base_distShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m110\sounds\m110_suppressed_far",1}};
		volume = 0.35;
	};

};
class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;
	class New_M110_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"New_M110_closeShot_SoundShader","New_M110_midShot_SoundShader","New_M110_distShot_SoundShader"};
	};
	class New_M110_Supressed_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"New_M110_SupressedcloseShot_SoundShader","New_M110_SupressedmidShot_SoundShader","New_M110_SupresseddistShot_SoundShader"};
	};
};
