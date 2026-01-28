/**
 * VOIDLINE PVP ZONE - HACKED CRATES DEBUGGING
 * 
 * This file helps debug HackedCrates integration issues.
 */

class VoidlineHackedCratesDebug
{
    static void TestHackedCratesIntegration()
    {
        Print("[VoidlineHackedCrates] ===== DEBUGGING HACKED CRATES INTEGRATION =====");
        Print("[VoidlineHackedCrates] Testing if HackedCrates mod classes exist...");
        
        // Test if we can create instances of different possible HackedCrate classes
        
        // Test HackedCrate_Base
        Object testObj1 = GetGame().CreateObject("HackedCrate_Base", Vector(0, 0, 0));
        if (testObj1)
        {
            Print("[VoidlineHackedCrates] SUCCESS: HackedCrate_Base class exists and can be created");
            GetGame().ObjectDelete(testObj1);
        }
        else
        {
            Print("[VoidlineHackedCrates] FAIL: HackedCrate_Base class does not exist or cannot be created");
        }
        
        // Test HackedCrate
        Object testObj2 = GetGame().CreateObject("HackedCrate", Vector(0, 0, 0));
        if (testObj2)
        {
            Print("[VoidlineHackedCrates] SUCCESS: HackedCrate class exists and can be created");
            GetGame().ObjectDelete(testObj2);
        }
        else
        {
            Print("[VoidlineHackedCrates] FAIL: HackedCrate class does not exist or cannot be created");
        }
        
        // Test other possible names
        array<string> possibleNames = {"HackedCrate_BaseKit", "ExpansionAirdropContainer", "AirdropContainer", "BS_HackedCrate"};
        for (int i = 0; i < possibleNames.Count(); i++)
        {
            string className = possibleNames[i];
            Object testObj = GetGame().CreateObject(className, Vector(0, 0, 0));
            if (testObj)
            {
                Print("[VoidlineHackedCrates] SUCCESS: " + className + " class exists and can be created");
                GetGame().ObjectDelete(testObj);
            }
            else
            {
                Print("[VoidlineHackedCrates] FAIL: " + className + " class does not exist or cannot be created");
            }
        }
        
        Print("[VoidlineHackedCrates] ===== END HACKED CRATES DEBUGGING =====");
    }
}

// Mission integration to run debug test
modded class MissionServer
{
    override void OnMissionStart()
    {
        super.OnMissionStart();
        
        // Run debug test after mission starts
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(VoidlineHackedCratesDebug.TestHackedCratesIntegration, 5000, false);
    }
}
