modded class PlayerBase
{
    private ref array<ref VoidlinePVPZoneClientData> m_ClientZoneData;
    
    void PlayerBase()
    {
        m_ClientZoneData = new array<ref VoidlinePVPZoneClientData>();
    }
    
    // Handle incoming RPC calls from server and clients
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);
        
        // Handle VoidlinePVP RPC calls
        switch (rpc_type)
        {
            case VoidlineERPCs.VOIDLINE_RPC_ZONE_DATA:
                HandleReceiveZoneData(ctx);
                break;
                
            case VoidlineERPCs.VOIDLINE_RPC_ZONE_ENTRY:
                HandleZoneEntry(ctx);
                break;
                
            case VoidlineERPCs.VOIDLINE_RPC_ZONE_EXIT:
                HandleZoneExit(ctx);
                break;
                
            case VoidlineERPCs.VOIDLINE_RPC_ZONE_VISIBILITY:
                HandleZoneVisibility(ctx);
                break;
                
            case VoidlineERPCs.VOIDLINE_RPC_REQUEST_DATA:
                HandleZoneDataRequest(sender, ctx);
                break;
        }
    }
    
    // Client-side: Handle zone data received from server
    void HandleReceiveZoneData(ParamsReadContext ctx)
    {
        if (!GetGame().IsClient())
            return;
            
        Param8<string, vector, float, string, int, bool, bool, bool> data;
        if (!ctx.Read(data))
        {
            Print("[VoidlinePVP] CLIENT: Failed to read zone data");
            return;
        }
        
        Print("[VoidlinePVP] CLIENT: Received zone data: " + data.param1 + " - Active: " + data.param6 + " - ShowName: " + data.param7 + " - ShowMarkers: " + data.param8 + " - Position: " + data.param2);
        
        // Store zone data locally in PlayerBase
        VoidlinePVPZoneClientData clientZone = GetZoneDataByName(data.param1);
        if (!clientZone)
        {
            clientZone = new VoidlinePVPZoneClientData();
            clientZone.name = data.param1;
            m_ClientZoneData.Insert(clientZone);
        }
        
        clientZone.position = data.param2;
        clientZone.radius = data.param3;
        clientZone.description = data.param4;
        clientZone.color = data.param5;
        clientZone.isActive = data.param6;
        clientZone.showNameOnMap = data.param7; // Store showNameOnMap
        clientZone.showMarkersOnMap = data.param8; // Store showMarkersOnMap
    }
    
    // Client-side: Handle zone entry notification
    void HandleZoneEntry(ParamsReadContext ctx)
    {
        if (!GetGame().IsClient())
            return;
            
        Param1<string> data;
        if (!ctx.Read(data))
        {
            Print("[VoidlinePVP] CLIENT: Failed to read zone entry data");
            return;
        }
        
        Print("[VoidlinePVP] CLIENT: Received zone entry notification: " + data.param1);
        
        // Show notification using Expansion system
        if (GetIdentity())
        {
            ExpansionNotification("PVP Zone Entry", data.param1, "set:expansion_notification_iconset image:icon_error", 0xFFFF4444, 8.0).Create(GetIdentity());
        }
    }
    
    // Client-side: Handle zone exit notification
    void HandleZoneExit(ParamsReadContext ctx)
    {
        if (!GetGame().IsClient())
            return;
            
        Param1<string> data;
        if (!ctx.Read(data))
        {
            Print("[VoidlinePVP] CLIENT: Failed to read zone exit data");
            return;
        }
        
        Print("[VoidlinePVP] CLIENT: Received zone exit notification: " + data.param1);
        
        // Show notification using Expansion system
        if (GetIdentity())
        {
            ExpansionNotification("PVP Zone Exit", data.param1, "set:expansion_notification_iconset image:icon_info", 0xFF44FF44, 8.0).Create(GetIdentity());
        }
    }
    
    // Client-side: Handle zone visibility update
    void HandleZoneVisibility(ParamsReadContext ctx)
    {
        if (!GetGame().IsClient())
            return;
            
        Param2<string, bool> data;
        if (!ctx.Read(data))
        {
            Print("[VoidlinePVP] CLIENT: Failed to read zone visibility data");
            return;
        }
        
        Print("[VoidlinePVP] CLIENT: Zone visibility updated: " + data.param1 + " - Visible: " + data.param2);
        
        VoidlinePVPZoneClientData zone = GetZoneDataByName(data.param1);
        if (zone)
        {
            if (data.param2) // Zone is now visible/active
            {
                zone.isActive = true;
            }
            else // Zone is now hidden/removed
            {
                Print("[VoidlinePVP] CLIENT: Removing zone from client data: " + data.param1);
                // Remove the zone completely from client data so it disappears from map
                m_ClientZoneData.RemoveItem(zone);
            }
            
            // Try to refresh map markers if map is currently open
            RefreshMapMarkersIfOpen();
        }
    }
    
    // Server-side: Handle zone data request from client
    void HandleZoneDataRequest(PlayerIdentity sender, ParamsReadContext ctx)
    {
        if (!GetGame().IsServer())
            return;
            
        Param1<string> data;
        if (!ctx.Read(data))
        {
            Print("[VoidlinePVP] SERVER: Failed to read zone data request");
            return;
        }
        
        Print("[VoidlinePVP] SERVER: Received zone data request from: " + sender.GetName());
        
        // Send all zone data to the requesting player
        VoidlinePVPRPCManager rpcManager = VoidlinePVPRPCManager.GetInstance();
        if (rpcManager)
        {
            rpcManager.SendAllZoneDataToPlayer(sender);
        }
    }
    
    // Helper function to get zone data by name
    VoidlinePVPZoneClientData GetZoneDataByName(string name)
    {
        for (int i = 0; i < m_ClientZoneData.Count(); i++)
        {
            if (m_ClientZoneData[i].name == name)
                return m_ClientZoneData[i];
        }
        return null;
    }
    
    // Public function to get all client zones (for map integration)
    array<ref VoidlinePVPZoneClientData> GetClientZoneData()
    {
        return m_ClientZoneData;
    }
    
    // Helper method to refresh map markers if map is currently open
    void RefreshMapMarkersIfOpen()
    {
        // Zone visibility changed - markers will refresh automatically when map is next opened
        // The OnShow() method in ExpansionMapMenuVoidlinePVP.c handles this automatically
        Print("[VoidlinePVP] CLIENT: Zone visibility changed - markers will refresh when map is opened");
    }
}
