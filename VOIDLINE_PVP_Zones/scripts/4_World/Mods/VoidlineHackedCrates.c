modded class BS_Hacked_Crate
{
    override void EEInit()
    {
        super.EEInit();
        
        if (GetGame().IsServer())
        {
            Print("[VoidlineHackedCrates] BS_Hacked_Crate spawned");
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CreateZoneForCrate, 2000, false);
        }
    }

    override void EEDelete(EntityAI parent)
    {
        if (GetGame().IsServer())
        {
            Print("[VoidlineHackedCrates] BS_Hacked_Crate deleted");
            RemoveZoneForCrate();
        }
        
        super.EEDelete(parent);
    }
    
    void CreateZoneForCrate()
    {
        VoidlinePVPZoneManager zoneManager = VoidlinePVPZoneManager.GetInstance();
        if (!zoneManager)
        {
            Print("[VoidlineHackedCrates] ERROR: Zone manager not found!");
            return;
        }
            
        vector pos = GetPosition();
        string crateID = GetID().ToString();
        string zoneName = "HackedCrate_" + crateID;
        
        Print("[VoidlineHackedCrates] Creating PVP zone at: " + pos.ToString());
        
        if (zoneManager.CreateCustomZone("HackedCrates", zoneName, pos, 500.0, "HackedCrate PVP Zone - High Value Loot!", 0xFFFF6600, 0, false) != "")
        {
            Print("[VoidlineHackedCrates] SUCCESS: Created PVP zone");
        }
        else
        {
            Print("[VoidlineHackedCrates] ERROR: Failed to create PVP zone!");
        }
    }
    
    void RemoveZoneForCrate()
    {
        VoidlinePVPZoneManager zoneManager = VoidlinePVPZoneManager.GetInstance();
        if (!zoneManager)
            return;
            
        string crateID = GetID().ToString();
        string zoneName = "HackedCrates: HackedCrate_" + crateID;
        
        Print("[VoidlineHackedCrates] Removing PVP zone: " + zoneName);
        
        if (zoneManager.RemoveCustomZone(zoneName))
        {
            Print("[VoidlineHackedCrates] SUCCESS: Removed PVP zone");
        }
        else
        {
            Print("[VoidlineHackedCrates] WARNING: Could not remove PVP zone (maybe already removed)");
        }
    }
}