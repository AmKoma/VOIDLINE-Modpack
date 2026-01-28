modded class MissionGameplay
{
    override void OnInit()
    {
        super.OnInit();
        
        Print("[VoidlinePVP] Client-side PVP Zone system initialized");
    }
    
    override void OnMissionStart()
    {
        super.OnMissionStart();
            
        // Request zone data from server after mission starts
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RequestZoneDataFromServer, 5000, false);
    }
    
    void RequestZoneDataFromServer()
    {
        if (!GetGame().IsClient() || GetGame().IsServer())
            return;
            
        Print("[VoidlinePVP] Client requesting zone data from server...");
        
        // Send RPC to server to request all zone data using direct RPC approach
        auto params = new Param1<string>("RequestZoneData");
        GetGame().RPCSingleParam(GetGame().GetPlayer(), VoidlineERPCs.VOIDLINE_RPC_REQUEST_DATA, params, true, null);
    }
}
