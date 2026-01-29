class Gunsmith: SkillsBase
{
	id="gnsmth";
	enabled=1;
	displayName="#STR_TERJESKILL_GUNSMITH_NAME";
	description="#STR_TERJESKILL_GUNSMITH_DESC";
	icon="set:TerjeSkills_icon image:ts_gunsmith";
	class Modifiers
	{
		class WeaponDegradationModifier
		{
			id="wpndegmod";
			enabled=1;
			text="#STR_TERJESKILL_GUNSMITH_MOD0";
			value=-0.01;
		};
	};
	class Perks
	{
		class RecoilControl
		{
			id="rclctrl";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_RECOILCONTROL";
			description="#STR_TERJEPERK_GNSM_RECOILCONTROL_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_rclctrl";
			enabledIcon="set:TerjePerk_icon image:tp_rclctrl";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,2,3};
			values[]={-0.05,-0.1,-0.15,-0.25,-0.35,-0.5};
		};
		class SteadyAim
		{
			id="steadyaim";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_STEADYAIM";
			description="#STR_TERJEPERK_GNSM_STEADYAIM_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_steadyaim";
			enabledIcon="set:TerjePerk_icon image:tp_steadyaim";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,2,3};
			values[]={-0.05,-0.1,-0.2,-0.3,-0.4,-0.6};
		};
		class WeaponMaintenance
		{
			id="wpnmaint";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_WEAPONMAINT";
			description="#STR_TERJEPERK_GNSM_WEAPONMAINT_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_wpnmaint";
			enabledIcon="set:TerjePerk_icon image:tp_wpnmaint";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.35,-0.5,-0.7,-0.85};
		};
		class JamResistance
		{
			id="jamres";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_JAMRESIST";
			description="#STR_TERJEPERK_GNSM_JAMRESIST_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_jamres";
			enabledIcon="set:TerjePerk_icon image:tp_jamres";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.35,-0.5,-0.7,-0.9};
		};
		class ImprovedRepair
		{
			id="imprep";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_IMPROVEDREPAIR";
			description="#STR_TERJEPERK_GNSM_IMPROVEDREPAIR_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_imprep";
			enabledIcon="set:TerjePerk_icon image:tp_imprep";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={0.1,0.2,0.35,0.5,0.75,1.0};
		};
		class ReliableWeapons
		{
			id="relwpn";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_RELIABLEWEAPONS";
			description="#STR_TERJEPERK_GNSM_RELIABLEWEAPONS_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_relwpn";
			enabledIcon="set:TerjePerk_icon image:tp_relwpn";
			requiredSkillLevels[]={1,5,10,15,20,25};
			requiredPerkPoints[]={1,1,1,1,1,2};
			values[]={-0.1,-0.2,-0.3,-0.5,-0.65,-0.85};
		};
		class SuppressorCare
		{
			id="supcare";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_SUPPRESSORCARE";
			description="#STR_TERJEPERK_GNSM_SUPPRESSORCARE_DES";
			stagesCount=6;
			disabledIcon="set:TerjePerkBlack_icon image:tp_supcare";
			enabledIcon="set:TerjePerk_icon image:tp_supcare";
			requiredSkillLevels[]={3,8,13,18,23,30};
			requiredPerkPoints[]={1,1,1,1,2,2};
			values[]={-0.1,-0.2,-0.35,-0.5,-0.7,-0.85};
		};
		class PristineRepair
		{
			id="prstrep";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_PRISTINEREPAIR";
			description="#STR_TERJEPERK_GNSM_PRISTINEREPAIR_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_prstrep";
			enabledIcon="set:TerjePerk_icon image:tp_prstrep";
			requiredSkillLevels[]={35};
			requiredPerkPoints[]={4};
			values[]={0.0};
		};
		class WeaponMastery
		{
			id="wpnmstr";
			enabled=1;
			displayName="#STR_TERJEPERK_GNSM_WEAPONMASTERY";
			description="#STR_TERJEPERK_GNSM_WEAPONMASTERY_DES";
			stagesCount=1;
			disabledIcon="set:TerjePerkBlack_icon image:tp_wpnmstr";
			enabledIcon="set:TerjePerk_icon image:tp_wpnmstr";
			requiredSkillLevels[]={45};
			requiredPerkPoints[]={5};
			values[]={0.0};
		};
	};
};
