class CfgPatches
{
    class VOIDLINE_PVP_Zones
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DayZExpansion_AI_Scripts", "DayZExpansion_Hardline_Scripts"};
    };
};

class CfgMods
{
    class VOIDLINE_PVP_Zones
    {
        dir = "VOIDLINE_PVP_Zones";
        picture = "";
        action = "";
        hideName = 0;
        hidePicture = 0;
        name = "VOIDLINE PVP Zones";
        credits = "KOMA";
        author = "KOMA";
        authorID = "0";
        version = "1.0";
        extra = 0;
        type = "mod";

        dependencies[] = {"Game", "World", "Mission"};

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"VOIDLINE_PVP_Zones/scripts/3_Game"};
            };

            class worldScriptModule
            {
                value = "";
                files[] = {"VOIDLINE_PVP_Zones/scripts/4_World"};
            };

            class missionScriptModule
            {
                value = "";
                files[] = {"VOIDLINE_PVP_Zones/scripts/5_Mission"};
            };
        };
    };
};
