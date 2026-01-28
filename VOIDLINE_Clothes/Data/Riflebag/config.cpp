class CfgPatches
{
    class Voidline_RifleBags
    {
        units[] = {"Voidline_RifleBags_Black", "Voidline_RifleBags_Green", "Voidline_RifleBags_Tan", "Voidline_RifleBags_D_Black", "Voidline_RifleBags_D_Green", "Voidline_RifleBags_D_Tan"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Characters_Backpacks", "DZ_Scripts", "DZ_Characters"};
    };
};

class cfgWeapons
{
    class RifleCore;
    class Rifle_Base : RifleCore
    {
        inventorySlot[] = {"Shoulder", "Melee", "Shoulder1", "Shoulder2", "Shoulder3", "Shoulder4", "Shoulder5", "Shoulder6", "Shoulder7", "Shoulder8"};
    };
};

class cfgVehicles
{
    class Clothing_Base;
    class Clothing: Clothing_Base{};
    class Voidline_RifleBag_Base : Clothing_Base
    {
        scope = 0;
        displayName = "RifleBag";
        descriptionShort = "This is a Riflebag That is capable of carrying 8 weapons. Thank's to ReDos for this mod.";
        model = "\Voidline_Clothes\Data\Riflebag\Voidline_RifleBags_g.p3d";
        inventorySlot[] = {"Back"};
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        attachments[] = {"Shoulder1", "Shoulder2", "Shoulder3", "Shoulder4", "Shoulder5", "Shoulder6", "Shoulder7", "Shoulder8", "VestHolster", "VestPouch", "Chemlight", "WalkieTalkie", "Belt_Back"};
        itemInfo[] = {"Clothing", "Back"};
        rotationFlags = 16;
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa"};
        itemSize[] = {8, 8};
        itemsCargoSize[] = {10, 10};
        weight = 2300;
        varWetMax = 0.79;
        heatIsolation = 0.7;
        repairableWithKits[] = {5, 2};
        repairCosts[] = {30, 25};
        soundAttType = "Outdoor";
        randomQuantity = 4;
        class ClothingTypes
        {
            male = "\Voidline_Clothes\Data\Riflebag\Voidline_RifleBags_m.p3d";
            female = "\Voidline_Clothes\Data\Riflebag\Voidline_RifleBags_f.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 190;
                    healthLevels[] = {{1, {"Voidline_Clothes\Data\Riflebag\RifleBag.rvmat"}}, {0.7, {"Voidline_Clothes\Data\Riflebag\RifleBag.rvmat"}}, {0.5, {"Voidline_Clothes\Data\Riflebag\RifleBag_damage.rvmat"}}, {0.3, {"Voidline_Clothes\Data\Riflebag\RifleBag_damage.rvmat"}}, {0, {"Voidline_Clothes\Data\Riflebag\RifleBag_destruct.rvmat"}}};
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem_Light
                {
                    soundSet = "pickUpBackPack_Plastic_Light_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpBackPack_Plastic_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "taloonbag_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class Voidline_RifleBags_Black : Voidline_RifleBag_Base
    {
        scope = 2;
        displayName = "RifleBag (Black)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa"};
    };
    class Voidline_RifleBags_Green : Voidline_RifleBag_Base
    {
        scope = 2;
        displayName = "RifleBag (Green)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Green_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Green_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Green_co.paa"};
    };
    class Voidline_RifleBags_Tan : Voidline_RifleBag_Base
    {
        scope = 2;
        displayName = "RifleBag (Tan)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Tan_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Tan_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Tan_co.paa"};
    };
    class Voidline_RifleBags_Desert_Camo : Voidline_RifleBag_Base
    {
        scope = 2;
        displayName = "RifleBag (Desert Camo)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Desert_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Desert_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Desert_Camo_co.paa"};
    };
    class Voidline_RifleBags_Winter : Voidline_RifleBag_Base
    {
        scope = 2;
        displayName = "RifleBag (Winter)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Winter_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_co.paa"};
    };
    class Voidline_RifleBags_Winter_Camo : Voidline_RifleBag_Base
    {
        scope = 2;
        displayName = "RifleBag (Winter Camo)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Winter_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_Camo_co.paa"};
    };
    class Voidline_RifleBag1_Base : Clothing_Base
    {
        scope = 0;
        displayName = "RifleBag (Diagonal)";
        descriptionShort = "This is a Diagonal Riflebag That is capable of carrying 8 weapons. Thank's to ReDos for this mod.";
        model = "\Voidline_Clothes\Data\Riflebag\Voidline_RifleBags_D_g.p3d";
        inventorySlot[] = {"Back"};
        hiddenSelections[] = {"camoGround", "camoMale", "camoFemale"};
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa"};
        attachments[] = {"Shoulder1", "Shoulder2", "Shoulder3", "Shoulder4", "Shoulder5", "Shoulder6", "Shoulder7", "Shoulder8", "VestHolster", "VestPouch", "Chemlight", "WalkieTalkie", "Belt_Back"};
        itemInfo[] = {"Clothing", "Back"};
        rotationFlags = 16;
        itemSize[] = {8, 8};
        itemsCargoSize[] = {10, 10};
        weight = 2300;
        varWetMax = 0.79;
        heatIsolation = 0.7;
        repairableWithKits[] = {5, 2};
        repairCosts[] = {30, 25};
        soundAttType = "Outdoor";
        randomQuantity = 4;
        class ClothingTypes
        {
            male = "\Voidline_Clothes\Data\Riflebag\Voidline_RifleBags_D_m.p3d";
            female = "\Voidline_Clothes\Data\Riflebag\Voidline_RifleBags_D_f.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 190;
                    healthLevels[] = {{1, {"Voidline_Clothes\Data\Riflebag\RifleBag.rvmat"}}, {0.7, {"Voidline_Clothes\Data\Riflebag\RifleBag.rvmat"}}, {0.5, {"Voidline_Clothes\Data\Riflebag\RifleBag_damage.rvmat"}}, {0.3, {"Voidline_Clothes\Data\Riflebag\RifleBag_damage.rvmat"}}, {0, {"Voidline_Clothes\Data\Riflebag\RifleBag_destruct.rvmat"}}};
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem_Light
                {
                    soundSet = "pickUpBackPack_Plastic_Light_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpBackPack_Plastic_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "taloonbag_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class Voidline_RifleBags_V_Black : Voidline_RifleBag1_Base
    {
        scope = 2;
        displayName = "RifleBag (Diagonal Black)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Black_co.paa"};
    };
    class Voidline_RifleBags_V_Green : Voidline_RifleBag1_Base
    {
        scope = 2;
        displayName = "RifleBag (Diagonal Green)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Green_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Green_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Green_co.paa"};
    };
    class Voidline_RifleBags_V_Tan : Voidline_RifleBag1_Base
    {
        scope = 2;
        displayName = "RifleBag (Diagonal Tan)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Tan_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Tan_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Tan_co.paa"};
    };
    class Voidline_RifleBags_V_Desert_Camo : Voidline_RifleBag1_Base
    {
        scope = 2;
        displayName = "RifleBag (Diagonal Desert Camo)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Desert_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Desert_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Desert_Camo_co.paa"};
    };
    class Voidline_RifleBags_V_Winter : Voidline_RifleBag1_Base
    {
        scope = 2;
        displayName = "RifleBag (Diagonal Winter)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Winter_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_co.paa"};
    };
    class Voidline_RifleBags_V_Winter_Camo : Voidline_RifleBag1_Base
    {
        scope = 2;
        displayName = "RifleBag (Diagonal Winter Camo)";
        hiddenSelectionsTextures[] = {"Voidline_Clothes\Data\Riflebag\RifleBag_Winter_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_Camo_co.paa", "Voidline_Clothes\Data\Riflebag\RifleBag_Winter_Camo_co.paa"};
    };
};
class CfgSlots
{
    class Slot_Gun1
    {
        name = "Shoulder1";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder1";
    };
    class Slot_Gun2
    {
        name = "Shoulder2";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder2";
    };
    class Slot_Gun3
    {
        name = "Shoulder3";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder3";
    };
    class Slot_Gun4
    {
        name = "Shoulder4";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder4";
    };
    class Slot_Gun5
    {
        name = "Shoulder5";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder5";
    };
    class Slot_Gun6
    {
        name = "Shoulder6";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder6";
    };
    class Slot_Gun7
    {
        name = "Shoulder7";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder7";
    };
    class Slot_Gun8
    {
        name = "Shoulder8";
        displayName = "Weapon";
        ghostIcon = "shoulderleft";
        selection = "Shoulder8";
    };
};
class CfgNonAIVehicles
{
    class ProxyAttachment;
    class ProxyShoulder1 : ProxyAttachment
    {
        scope = 2;
        inventorySlot = "Shoulder1";
        model = "\Voidline_Clothes\Data\Riflebag\Proxies\Shoulder.p3d";
    };
    class ProxyShoulder2 : ProxyAttachment
    {
        scope = 2;
        inventorySlot = "Shoulder2";
        model = "\Voidline_Clothes\Data\Riflebag\Proxies\Shoulder2.p3d";
    };
    class Proxyplate_carrier_pouches_g : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = {"VestPouch"};
        model = "DZ\characters\vests\plate_carrier_pouches_g.p3d";
    };
    class Proxyplate_carrier_holster_g : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = {"VestHolster"};
        model = "DZ\characters\vests\plate_carrier_holster_g.p3d";
    };
    class ProxyWalkieTalkie : ProxyAttachment
    {
        scope = 2;
        inventorySlot = "WalkieTalkie";
        model = "\DZ\gear\radio\WalkieTalkie.p3d";
    };
    class ProxyChemlight : ProxyAttachment
    {
        scope = 2;
        inventorySlot = "Chemlight";
        model = "\DZ\gear\consumables\Chemlight.p3d";
    };
    class Proxybelt_back_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = {"Belt_Back"};
        model = "\DZ\characters\belts\proxies\belt_back_proxy.p3d";
    };
};
