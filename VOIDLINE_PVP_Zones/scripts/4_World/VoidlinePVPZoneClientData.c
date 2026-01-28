// Simple client-side zone data structure for PlayerBase integration

class VoidlinePVPZoneClientData
{
    string name;
    vector position;
    float radius;
    string description;
    int color;
    bool isActive;
    bool showNameOnMap; // Whether to show zone name on map
    bool showMarkersOnMap; // Whether to show zone markers/circles on map
    
    void VoidlinePVPZoneClientData()
    {
        name = "";
        position = "0 0 0";
        radius = 0.0;
        description = "";
        color = 0xFFFFFFFF;
        isActive = false;
        showNameOnMap = true; // Default to true
        showMarkersOnMap = true; // Default to true
    }
}
