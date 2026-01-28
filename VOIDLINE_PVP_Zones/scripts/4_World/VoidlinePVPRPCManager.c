// Enhanced RPC System for VOIDLINE PVP Zones

class VoidlinePVPRPCManager
{
    private static ref VoidlinePVPRPCManager m_Instance;
    
    static VoidlinePVPRPCManager GetInstance()
    {
        if (!m_Instance)
            m_Instance = new VoidlinePVPRPCManager();
        return m_Instance;
    }
    
    void VoidlinePVPRPCManager()
    {
        // Constructor
    }
    
    // Helper function to get PlayerBase from PlayerIdentity
    PlayerBase GetPlayerByIdentity(PlayerIdentity identity)
    {
        if (!identity)
            return null;
            
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        
        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (player && player.GetIdentity() && player.GetIdentity().GetId() == identity.GetId())
            {
                return player;
            }
        }
        
        return null;
    }
    
    // Server -> Client RPCs using direct RPC approach
    void SendZoneData(PlayerIdentity identity, string name, vector position, float radius, string description, int color, bool isActive, bool showNameOnMap = true, bool showMarkersOnMap = true)
    {
        if (!identity || !GetGame().IsServer())
            return;
            
        // Get the player object for this identity
        PlayerBase player = GetPlayerByIdentity(identity);
        if (!player)
        {
            Print("[VoidlinePVP] ERROR: Could not find player for identity: " + identity.GetName());
            return;
        }
            
        auto params = new Param8<string, vector, float, string, int, bool, bool, bool>(name, position, radius, description, color, isActive, showNameOnMap, showMarkersOnMap);
        GetGame().RPCSingleParam(player, VoidlineERPCs.VOIDLINE_RPC_ZONE_DATA, params, true, identity);
        
        Print("[VoidlinePVP] Sent zone data to client: " + name + " (Active: " + isActive + ", ShowName: " + showNameOnMap + ", ShowMarkers: " + showMarkersOnMap + ")");
    }
    
    void NotifyZoneEntry(PlayerIdentity identity, string message)
    {
        if (!identity || !GetGame().IsServer())
            return;
            
        PlayerBase player = GetPlayerByIdentity(identity);
        if (!player)
            return;
            
        auto params = new Param1<string>(message);
        GetGame().RPCSingleParam(player, VoidlineERPCs.VOIDLINE_RPC_ZONE_ENTRY, params, true, identity);
        
        Print("[VoidlinePVP] Sent zone entry notification to: " + identity.GetName());
    }
    
    void NotifyZoneExit(PlayerIdentity identity, string message)
    {
        if (!identity || !GetGame().IsServer())
            return;
            
        PlayerBase player = GetPlayerByIdentity(identity);
        if (!player)
            return;
            
        auto params = new Param1<string>(message);
        GetGame().RPCSingleParam(player, VoidlineERPCs.VOIDLINE_RPC_ZONE_EXIT, params, true, identity);
        
        Print("[VoidlinePVP] Sent zone exit notification to: " + identity.GetName());
    }
    
    void UpdateZoneVisibility(PlayerIdentity identity, string zoneName, bool isVisible)
    {
        if (!identity || !GetGame().IsServer())
            return;
            
        PlayerBase player = GetPlayerByIdentity(identity);
        if (!player)
            return;
            
        auto params = new Param2<string, bool>(zoneName, isVisible);
        GetGame().RPCSingleParam(player, VoidlineERPCs.VOIDLINE_RPC_ZONE_VISIBILITY, params, true, identity);
        
        Print("[VoidlinePVP] Sent zone visibility update to: " + identity.GetName() + " - Zone: " + zoneName + " - Visible: " + isVisible);
    }
    
    // Broadcast to all players
    void BroadcastZoneVisibilityUpdate(string zoneName, bool isVisible)
    {
        if (!GetGame().IsServer())
            return;
            
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        
        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (player && player.GetIdentity())
            {
                UpdateZoneVisibility(player.GetIdentity(), zoneName, isVisible);
            }
        }
    }
    
    void BroadcastZoneEntry(string message)
    {
        if (!GetGame().IsServer())
            return;
            
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        
        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (player && player.GetIdentity())
            {
                NotifyZoneEntry(player.GetIdentity(), message);
            }
        }
    }
    
    void BroadcastZoneExit(string message)
    {
        if (!GetGame().IsServer())
            return;
            
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        
        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (player && player.GetIdentity())
            {
                NotifyZoneExit(player.GetIdentity(), message);
            }
        }
    }
    
    void BroadcastZoneData(string zoneName, vector position, float radius, string description, int color, bool isActive, bool showNameOnMap = true, bool showMarkersOnMap = true)
    {
        if (!GetGame().IsServer())
            return;
            
        Print("[VoidlinePVP] Broadcasting zone data to all clients: " + zoneName + " - Active: " + isActive + " - ShowName: " + showNameOnMap + " - ShowMarkers: " + showMarkersOnMap);
            
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        
        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (player && player.GetIdentity())
            {
                // Send zone data to this player using the new RPC approach
                SendZoneData(player.GetIdentity(), zoneName, position, radius, description, color, isActive, showNameOnMap, showMarkersOnMap);
            }
        }
    }
    
    void SendAllZoneDataToPlayer(PlayerIdentity identity)
    {
        if (!GetGame().IsServer())
            return;
            
        Print("[VoidlinePVP] Sending all zone data to new player: " + identity.GetName());
        
        // Get all zones from zone manager
        VoidlinePVPZoneManager zoneManager = VoidlinePVPZoneManager.GetInstance();
        if (!zoneManager)
        {
            Print("[VoidlinePVP] ERROR: Zone manager not found when sending data to new player");
            return;
        }
        
        // Send standard zones
        map<string, ref VoidlinePVPZone> allZones = zoneManager.GetZonesByName();
        for (int i = 0; i < allZones.Count(); i++)
        {
            string zoneName = allZones.GetKey(i);
            VoidlinePVPZone zone = allZones.GetElement(i);
            if (zone)
            {
                SendZoneData(identity, zone.GetName(), zone.GetPosition(), zone.GetRadius(), zone.GetDescription(), zone.GetColor(), zone.IsCurrentlyActive(), zone.GetShowNameOnMap(), zone.GetShowMarkersOnMap());
            }
        }
        
        // Send territory zones
        array<ref VoidlinePVPZone> territoryZones = zoneManager.GetTerritoryZones();
        for (int j = 0; j < territoryZones.Count(); j++)
        {
            VoidlinePVPZone territoryZone = territoryZones[j];
            if (territoryZone)
            {
                SendZoneData(identity, territoryZone.GetName(), territoryZone.GetPosition(), territoryZone.GetRadius(), territoryZone.GetDescription(), territoryZone.GetColor(), territoryZone.IsCurrentlyActive(), territoryZone.GetShowNameOnMap(), territoryZone.GetShowMarkersOnMap());
            }
        }
        
        Print("[VoidlinePVP] Sent all zone data to player: " + identity.GetName());
    }
}
