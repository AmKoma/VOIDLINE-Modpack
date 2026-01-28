modded class ModItemRegisterCallbacks
{
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);

        pType.AddItemInHandsProfileIK("Voidline_RifleBag_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior,"dz/anims/anm/player/ik/two_handed/assault_g.anm");
		pType.AddItemInHandsProfileIK("Voidline_RifleBag1_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior,"dz/anims/anm/player/ik/two_handed/assault_g.anm");
     	pType.AddItemInHandsProfileIK("Voidline_CamoNetPoncho_Base", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/camo_net.anm");
    }
};