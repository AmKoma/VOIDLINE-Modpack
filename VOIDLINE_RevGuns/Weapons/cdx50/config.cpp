class CfgPatches
{
	class RevCDX50
	{
		units[] = {};
		weapons[] = {"Rev_CDX50"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Firearms","DZ_Weapons_Magazines","DZ_Sounds_Effects"};
        attachments[] = {};
	};
};

class cfgWeapons 
{
    class Mode_SemiAuto;
    class BoltActionRifle_ExternalMagazine_Base;
	class Rev_CDX50_Base: BoltActionRifle_ExternalMagazine_Base
	{
        class Single;
		modes[] = {"_Single"};
		class _Single: Single
		{
			soundSetShot[] = {"CDX50_Shot_SoundSet","CDX50_Tail_SoundSet","CDX50_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"cdx50_rp_silenced_Shot_SoundSet","LongHorn_silencerHomeMadeTail_SoundSet","LongHorn_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.5;
			dispersion = 0.0002;
			magazineSlot = "magazine";
			simpleHiddenSelections[] = {"hide_barrel", "hide_muzzle"};
		};
	}
	class eAI_CDX50 : Rev_CDX50_Base
	{
		scope = 2;
		descriptionShort = "This weapon belonged to a bot... To pick it up, you must break the Matrix.";
		hiddenSelectionsTextures[] = {"RevGuns\Weapons\CDX50\data\cdx_co.paa"};
	}
}

class CfgSoundShaders 
{
    class baseCharacter_SoundShader;
    class base_tailTrees_SoundShader;
    class base_tailMeadows_SoundShader;
    class base_tailDistant_SoundShader;
    class base_tailForest_SoundShader;
    class base_tailHouses_SoundShader;
    class base_tailInterior_SoundShader;
    class base_closeShot_SoundShader;
	class base_midShot_SoundShader;
	class base_distShot_SoundShader;

    class CDX50_RP_Closure_SoundShader
	{
		samples[] = {{"DZ\sounds\weapons\firearms\SVD\SVD_closure_01",1},{"DZ\sounds\weapons\firearms\SVD\SVD_closure_02",1}};
		range = 5;
		volume = 0.4466836;
	};
	class CDX50_RP_closeShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Close",1},{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Close",1},{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Close",1}};
		volume = 2;
		range = 100;
		rangeCurve = "closeShotCurve";
	};
	class CDX50_RP_midShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Mid",1},{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Mid",1},{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Mid",1}};
		volume = 0.56234133;
		range = 1500;
		rangeCurve[] = {{0,0.2},{50,1},{300,0},{1500,0}};
	};
	class CDX50_RP_distShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Far",1},{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Far",1},{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Shot1_Far",1}};
		volume = 1;
		range = 3500;
		rangeCurve[] = {{0,0},{50,0},{300,1},{3500,1}};
	};

    class CDX50_tailTrees_SoundShader: base_tailTrees_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Tree1",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Tree2",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Tree3",1}};
	};

    class CDX50_silencerHomeMadeCloseShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Silenced_close",1}};
		volume = 1;
		range = 100;
		rangeCurve = "closeShotCurve";
	};

	class CDX50_silencerHomeMadeMidShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Silenced_mid",1}};
		volume = 0.56234133;
		range = 500;
		rangeCurve[] = {{0,0.2},{50,1},{140,0},{250,0}};
	};

	class CDX50_silencerHomeMadeDistShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Silenced_far",1}};
		volume = 1;
		range = 800;
		rangeCurve[] = {{0,0},{50,0},{140,1},{250,1}};
	};

	class CDX50_tailDistant_SoundShader: base_tailDistant_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Distant1",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Distant2",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Distant3",1}};
		range = 3500;
	};
	
	class CDX50_tailForest_SoundShader: base_tailForest_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Forest1",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Forest2",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Forest3",1}};
		volume = 0.6;
	};
	
	class CDX50_tailHouses_SoundShader: base_tailHouses_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Houses1",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Houses2",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Houses3",1}};
	};
	
	class CDX50_tailInterior_SoundShader: base_tailInterior_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Interior1",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Interior2",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Interior3",1}};
	};
	
	class CDX50_tailMeadows_SoundShader: base_tailMeadows_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Meadows1",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Meadows2",1}, {"VOIDLINE_RevGuns\Weapons\cdx50\sounds\CDX50_Tail_Meadows3",1}};
		range = 3500;
	};

}

class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;
	class Rifle_silencerHomemade_Base_SoundSet;
	class Rifle_Tail_Base_SoundSet;
	class Rifle_InteriorTail_Base_SoundSet;
	class baseCharacter_SoundSet;

	class CDX50_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"CDX50_RP_closeShot_SoundShader","CDX50_RP_midShot_SoundShader","CDX50_RP_distShot_SoundShader"};
	};

	class cdx50_rp_silenced_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"CDX50_silencerHomeMadeCloseShot_SoundShader","CDX50_silencerHomeMadeMidShot_SoundShader","CDX50_silencerHomeMadeDistShot_SoundShader"};
	};

    class CDX50_Tail_SoundSet: Rifle_Tail_Base_SoundSet
	{
		soundShaders[]=
		{
			"CDX50_tailDistant_SoundShader",
			"CDX50_tailTrees_SoundShader",
			"CDX50_tailForest_SoundShader",
			"CDX50_tailMeadows_SoundShader",
			"CDX50_tailHouses_SoundShader"
		};
	};
	class CDX50_InteriorTail_SoundSet: Rifle_InteriorTail_Base_SoundSet
	{
		soundShaders[]=
		{
			"CDX50_tailInterior_SoundShader"
		};
	};
}