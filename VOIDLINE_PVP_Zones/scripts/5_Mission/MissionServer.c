modded class MissionServer
{
    private ref VoidlinePVPZoneManager m_PVPZoneManager;

    override void OnInit()
    {
        super.OnInit();

        // Initialize PVP Zone Manager
        m_PVPZoneManager = VoidlinePVPZoneManager.GetInstance();

        Print("[VoidlinePVP] Server-side PVP Zone system initialized");
    }

    override void OnMissionStart()
    {
        super.OnMissionStart();

        // Ensure zone manager is running
        if (!m_PVPZoneManager)
            m_PVPZoneManager = VoidlinePVPZoneManager.GetInstance();
    }

    override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
    {
        super.OnClientRespawnEvent(identity, player);

        // Send all zone data to newly spawned player
        VoidlinePVPRPCManager rpcManager = VoidlinePVPRPCManager.GetInstance();
        if (rpcManager)
        {
            rpcManager.SendAllZoneDataToPlayer(identity);
            Print("[VoidlinePVP] Sent all zone data to respawned player: " + identity.GetName());
        }
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);

        Print("[VoidlinePVP] Player connected: " + identity.GetName());

        // Send all zone data to connected player after a delay
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendZoneDataDelayed, 3000, false, identity);
    }

    void SendZoneDataDelayed(PlayerIdentity identity)
    {
        VoidlinePVPRPCManager rpcManager = VoidlinePVPRPCManager.GetInstance();
        if (rpcManager && identity)
        {
            rpcManager.SendAllZoneDataToPlayer(identity);
            Print("[VoidlinePVP] Sent delayed zone data to connected player: " + identity.GetName());
        }
    }

    void SendZoneInfoToPlayer(PlayerIdentity identity)
    {
        if (!identity || !m_PVPZoneManager)
            return;

        array<ref VoidlinePVPZone> zones = m_PVPZoneManager.GetActiveZones();

        for (int i = 0; i < zones.Count(); i++)
        {
            VoidlinePVPZone zone = zones[i];
            if (zone && zone.IsCurrentlyActive())
            {
                // Send zone data via RPC manager
                VoidlinePVPRPCManager rpcManager = VoidlinePVPRPCManager.GetInstance();
                rpcManager.SendZoneData(identity, zone.GetName(), zone.GetPosition(), zone.GetRadius(), zone.GetDescription(), zone.GetColor(), zone.IsCurrentlyActive());
            }
        }
    }
}
