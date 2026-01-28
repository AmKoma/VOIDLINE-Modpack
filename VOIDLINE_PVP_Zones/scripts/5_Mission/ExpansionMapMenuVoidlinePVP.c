#ifdef EXPANSIONMODNAVIGATION
modded class ExpansionMapMenu
{
    override Widget Init()
    {
        Widget result = super.Init();

        Print("[VoidlinePVP] ExpansionMapMenu Init() called");
        
        // Try to load markers initially
        if (m_MapWidget)
        {
            Print("[VoidlinePVP] MapWidget available, loading PVP markers...");
            VoidlinePVPMapMarkerDrawer.LoadVoidlinePVPMarkers(m_MapWidget);
        }
        else
        {
            Print("[VoidlinePVP] WARNING: MapWidget not available yet!");
        }
        
        return result;
    }

    override void UpdateMarkers()
    {
        super.UpdateMarkers();

        Print("[VoidlinePVP] UpdateMarkers() called");
        
        // Refresh PVP zone markers when map is updated
        if (m_MapWidget)
        {
            VoidlinePVPMapMarkerDrawer.LoadVoidlinePVPMarkers(m_MapWidget, true);
            Print("[VoidlinePVP] Updated PVP zone markers on Expansion map");
        }
        else
        {
            Print("[VoidlinePVP] WARNING: MapWidget not available in UpdateMarkers!");
        }
    }

    override void OnShow()
    {
        super.OnShow();
        
        Print("[VoidlinePVP] Map OnShow() called - refreshing markers");
        
        // Try to refresh markers when map is shown
        if (m_MapWidget)
        {
            VoidlinePVPMapMarkerDrawer.LoadVoidlinePVPMarkers(m_MapWidget, true); // Set to true to clear old markers
            Print("[VoidlinePVP] Refreshed markers on map show");
        }
        else
        {
            Print("[VoidlinePVP] WARNING: MapWidget not available in OnShow!");
        }
    }
}
#endif
