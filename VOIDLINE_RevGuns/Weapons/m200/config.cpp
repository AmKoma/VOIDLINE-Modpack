class CfgPatches
{
	class RevM200
	{
		units[] = {};
		weapons[] = {"Rev_M200"};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Firearms","DZ_Weapons_Magazines","DZ_Sounds_Effects"};
	};
};

class cfgWeapons
{
    class Mode_SemiAuto;
    class BoltActionRifle_Base;
    class Rev_M200_Base: BoltActionRifle_Base {
        class Single;
		modes[] = {"_Single"};
		class _Single: Single
		{
			soundSetShot[] = {"m200rev_Shot_SoundSet","LongHorn_Tail_SoundSet","LongHorn_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"m200rev_silencerHomeMade_SoundSet","LongHorn_silencerHomeMadeTail_SoundSet","LongHorn_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 1;
			dispersion = 0.0001;
			magazineSlot = "magazine";
		};
	}
	class Rev_M200_Black: Rev_M200_Base
	{
		scope = 2;
		displayName = "M200 - NEYTE"
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\m200_newblack.paa"};
	};
	class Rev_M200_NEYTE: Rev_M200_Base
	{
		scope = 2;
		displayName = "M200 - NEYTE"
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\m200_neyte.paa"};
	};
	class Rev_M200_CRY: Rev_M200_Base
	{
		scope = 2;
		displayName = "M200 - CRY"
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\m200_cry.paa"};
	};
	class Rev_M200_VOID: Rev_M200_Base
	{
		scope = 2;
		displayName = "M200 - VOID"
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\m200_VOID.paa"};
	};
	class Rev_M200_SKRULK: Rev_M200_Base
	{
		scope = 2;
		displayName = "M200 - SKRULK"
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\M200_SKRULK_CO.paa"};
	};
	class Rev_M200_Gold: Rev_M200_Base
	{
		scope = 2;
		displayName = "M200 - Gold"
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\m200_newblack.paa"};
		hiddenSelectionsMaterials[] = {"\VOIDLINE_RevGuns\Weapons\m200\gold.rvmat", "\VOIDLINE_RevGuns\Weapons\m200\gold.rvmat"};
	};

	class eAI_M200 : Rev_M200_Base
	{
		scope = 2;
		descriptionShort = "This weapon belonged to a bot... To pick it up, you must break the Matrix.";
		hiddenSelectionsTextures[] = {"\VOIDLINE_RevGuns\Weapons\m200\m200_newblack.paa"};
	}


}

class CfgSoundShaders
{
	class m200rev_Closure_SoundShader
	{
		samples[] = {{"DZ\sounds\weapons\firearms\SVD\SVD_closure_01",1},{"DZ\sounds\weapons\firearms\SVD\SVD_closure_02",1}};
		range = 5;
		volume = 0.4466836;
	};

	class m200rev_silencerHomeMadeCloseShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m200\M200close_silence",1}};
		volume = 1;
		range = 100;
		rangeCurve = "closeShotCurve";
	};

	class m200rev_silencerHomeMadeMidShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m200\M200mid_silence",1}};
		volume = 0.56234133;
		range = 500;
		rangeCurve[] = {{0,0.2},{50,1},{140,0},{250,0}};
	};

	class m200rev_silencerHomeMadeDistShot_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m200\M200long_silence",1}};
		volume = 1;
		range = 800;
		rangeCurve[] = {{0,0},{50,0},{140,1},{250,1}};
	};

	class m200rev_m200rev_NewShotsClose_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m200\sounds\M200_Close",1}};
		volume = 2;
		range = 100;
		rangeCurve = "closeShotCurve";
	};
	class m200rev_m200rev_NewShotsMid_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m200\sounds\M200_Mid",1}};
		volume = 0.56234133;
		range = 1500;
		rangeCurve[] = {{0,0.2},{50,1},{300,0},{1500,0}};
	};
	class m200rev_m200rev_NewShotsDist_SoundShader
	{
		samples[] = {{"VOIDLINE_RevGuns\Weapons\m200\sounds\M200_Dist",1}};
		volume = 1;
		range = 3500;
		rangeCurve[] = {{0,0},{50,0},{300,1},{3500,1}};
	};
}

class CfgSoundSets
{
    class Rifle_silencerHomemade_Base_SoundSet;
    class Rifle_Shot_Base_SoundSet;

    class m200rev_NewShots_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"m200rev_m200rev_NewShotsClose_SoundShader","m200rev_m200rev_NewShotsMid_SoundShader","m200rev_m200rev_NewShotsDist_SoundShader","m200rev_Closure_SoundShader"};
	};

	class m200rev_silencerHomeMade_SoundSet: Rifle_silencerHomemade_Base_SoundSet
	{
		soundShaders[] = {"m200rev_silencerHomeMadeCloseShot_SoundShader","m200rev_silencerHomeMadeMidShot_SoundShader","m200rev_silencerHomeMadeDistShot_SoundShader","m200rev_Closure_SoundShader"};
	};
}