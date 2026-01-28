class CfgPatches
{
    class VOIDLINE_Clothes
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Characters_Backpacks", "DZ_Scripts", "DZ_Characters"};
    };
};

class CfgMods
{
    class VOIDLINE_Clothes
    {
        dir = "VOIDLINE_Clothes";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "VOIDLINE Clothes";
        author = "KOMA";
        credits = "ReDos";
        version = "1.0";
        extra = 0;
        type = "mod";
        dependencies[] = {"World"};
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"VOIDLINE_Clothes/Scripts/4_World"};
            };
        };
    };
};