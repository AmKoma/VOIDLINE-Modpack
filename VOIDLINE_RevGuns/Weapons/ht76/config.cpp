class CfgPatches
{
	class RevHT76
	{
		units[] = {};
		weapons[] = {"Rev_HT76"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Firearms", "DZ_Weapons_Magazines", "DZ_Sounds_Effects"};
		magazines[] = {"Rev_Mag_HT76_30Rnd"};
		attachments[] = {};
	};
};

class OpticsInfoRifle;
class Mode_SemiAuto;
class Mode_FullAuto;
class cfgWeapons
{
	class Rifle_Base;
	class Rev_HT76_Base : Rifle_Base
	{
		class SemiAuto;
		class FullAuto;

		scope = 0;
		displayName = "HT-76/A";
		modes[] = {"_FullAuto", "_SemiAuto"};
		class _SemiAuto : SemiAuto
		{
			soundSetShot[] = {"HT76_Shot_SoundSet", "FNFAL_Tail_SoundSet", "FNFAL_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"HT_76_Shot_Silenced", "FNFAL_silencerHomeMadeTail_SoundSet", "FNFAL_silencerInteriorHomeMadeTail_SoundSet"}};
		};
		class _FullAuto : FullAuto
		{
			soundSetShot[] = {"HT76_Shot_SoundSet", "FNFAL_Tail_SoundSet", "FNFAL_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"HT_76_Shot_Silenced", "FNFAL_silencerHomeMadeTail_SoundSet", "FNFAL_silencerInteriorHomeMadeTail_SoundSet"}};
		};
	};

	class eAI_HT76 : Rev_HT76_Base
	{
		scope = 2;
		descriptionShort = "This weapon belonged to a bot... To pick it up, you must break the Matrix.";
		hiddenSelectionsTextures[] = {"RevGuns\Weapons\HT76\data\rifle_black_co.paa"};
	}
};

class CfgSoundShaders
{
	class base_closeShot_SoundShader;
	class base_midShot_SoundShader;
	class base_distShot_SoundShader;

	class HT76_closeShot_SoundShader : base_closeShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_Single1", 1}, {"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_Single2", 1}, {"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_Single3", 1}};
		volume = 0.8;
	};

	class HT76_midShot_SoundShader : base_midShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_mid", 1}};
		volume = 0.45;
	};

	class HT76_distShot_SoundShader : base_distShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_far", 1}};
		volume = 0.2;
	};

	class HT76_silencerHomeMadeCloseShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_Suppressed", 1}};
		volume = 1;
		range = 100;
		rangeCurve = "closeShotCurve";
	};

	class HT76_silencerHomeMadeMidShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_Suppressed", 1}};
		volume = 0.56234133;
		range = 500;
		rangeCurve[] = {{0, 0.2}, {50, 1}, {140, 0}, {250, 0}};
	};

	class HT76_silencerHomeMadeDistShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\ht76\sounds\MBR_Suppressed", 1}};
		volume = 1;
		range = 800;
		rangeCurve[] = {{0, 0}, {50, 0}, {140, 1}, {250, 1}};
	};
}

class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;

	class HT76_Shot_SoundSet : Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"HT76_closeShot_SoundShader", "HT76_midShot_SoundShader", "HT76_distShot_SoundShader"};
	};

	class HT_76_Shot_Silenced : Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"HT76_silencerHomeMadeCloseShot_SoundShader", "HT76_silencerHomeMadeMidShot_SoundShader", "HT76_silencerHomeMadeDistShot_SoundShader"};
	};
}