// Map Marker Drawer for VOIDLINE PVP Zones - PlayerBase Integration

class VoidlinePVPMapMarkerDrawer
{
    static void LoadVoidlinePVPMarkers(MapWidget mapWidget, bool isUpdating = false)
    {
        if (!mapWidget)
        {
            Print("[VoidlinePVP] ERROR: MapWidget is null");
            return;
        }
        
        if (isUpdating)
            Print("[VoidlinePVP] LoadVoidlinePVPMarkers called - isUpdating: " + isUpdating);
        else
            Print("[VoidlinePVP] LoadVoidlinePVPMarkers called - isUpdating: " + isUpdating);
        
        Print("[VoidlinePVP] MapWidget is valid");
        
        // Clear all existing user marks when updating to avoid duplicates/ghosts
        if (isUpdating)
        {
            Print("[VoidlinePVP] Clearing existing user marks before redrawing zones");
            mapWidget.ClearUserMarks();
        }
        
        // Get local player to access zone data
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player)
        {
            Print("[VoidlinePVP] No player found");
            return;
        }
        
        Print("[VoidlinePVP] Player found, getting zone data");
        
        // Get client zone data from PlayerBase
        array<ref VoidlinePVPZoneClientData> clientZones = player.GetClientZoneData();
        if (!clientZones)
        {
            Print("[VoidlinePVP] No client zone data available");
            return;
        }
        
        Print("[VoidlinePVP] === CLIENT ZONE DEBUG ===");
        Print("[VoidlinePVP] DEBUG: Total client zones: " + clientZones.Count());
        Print("[VoidlinePVP] === END CLIENT ZONE DEBUG ===");
        
        if (clientZones.Count() == 0)
        {
            Print("[VoidlinePVP] No client zones available or empty array");
            return;
        }
        
        // Draw circles for each zone
        for (int i = 0; i < clientZones.Count(); i++)
        {
            VoidlinePVPZoneClientData zone = clientZones[i];
            if (zone && zone.isActive && zone.showMarkersOnMap)  // Only show active zones with markers enabled
            {
                Print("[VoidlinePVP] Drawing zone: " + zone.name + " at " + zone.position + " with radius " + zone.radius);
                DrawZoneCircle(mapWidget, zone);
            }
            else if (zone && zone.isActive && !zone.showMarkersOnMap)
            {
                Print("[VoidlinePVP] Zone " + zone.name + " is active but markers are disabled - skipping drawing");
            }
        }
        
        Print("[VoidlinePVP] Finished loading PVP zone markers");
    }
    
    static void DrawZoneCircle(MapWidget mapWidget, VoidlinePVPZoneClientData zoneData)
    {
        if (!mapWidget || !zoneData)
            return;
        
        vector zonePos = zoneData.position;
        float radius = zoneData.radius;
        int color = zoneData.color;
        
        // Calculate circle parameters - more points for larger zones
        int numPoints;
        if (radius <= 100)
            numPoints = 16; // Small zones: fewer points
        else if (radius <= 500)  
            numPoints = 32; // Medium zones: normal points
        else if (radius <= 2000)
            numPoints = 64; // Large zones: more points
        else
            numPoints = 256; // Huge zones: lots of points
            
        float angleStep = 2 * Math.PI / numPoints;
        
        // Create circle by adding multiple user marks
        for (int i = 0; i < numPoints; i++)
        {
            float angle1 = i * angleStep;
            int nextIndex = i + 1;
            if (nextIndex >= numPoints)
                nextIndex = 0;
            float angle2 = nextIndex * angleStep;
            
            // Calculate points on circle
            vector point1 = Vector(zonePos[0] + radius * Math.Cos(angle1),zonePos[1],zonePos[2] + radius * Math.Sin(angle1));
            vector point2 = Vector(zonePos[0] + radius * Math.Cos(angle2),zonePos[1],zonePos[2] + radius * Math.Sin(angle2));
            
            // Add user marks to create circle segments
            string markerText = "";
            if (zoneData.showNameOnMap) // Only show name if enabled
            {
                markerText = zoneData.name;
            }
            
            if (i == 0) // Only add text on first marker
            {
                mapWidget.AddUserMark(point1, markerText, color, "\\DZ\\gear\\navigation\\data\\map_bush_ca.paa");
            }
            else
            {
                mapWidget.AddUserMark(point1, "", color, "\\DZ\\gear\\navigation\\data\\map_bush_ca.paa");
            }
        }
        
        Print("[VoidlinePVP] Drew circle for zone: " + zoneData.name);
    }
}
