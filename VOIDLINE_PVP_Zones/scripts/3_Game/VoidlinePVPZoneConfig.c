// Zone configuration classes for JSON loading - following PVEZ pattern

class VoidlinePVPZoneScheduleConfig
{
    ref TIntArray activeDays;           // Days of week (1=Monday, 7=Sunday)
    string startTime;                   // Format: "HH:MM"
    string endTime;                     // Format: "HH:MM"
    int timezoneOffset;                 // UTC offset in hours
    
    void VoidlinePVPZoneScheduleConfig()
    {
        activeDays = new TIntArray;
        startTime = "00:00";
        endTime = "23:59";
        timezoneOffset = 1; // UTC+1 default
    }
};

class VoidlinePVPZoneDefinition
{
    string name;                        // Zone display name
    string description;                 // Zone description
    vector position;                    // Zone center position [x, z, y]
    float radius;                       // Zone radius in meters
    string zoneType;                    // "manual", "territory", "timed"
    bool isActive;                      // Zone enabled/disabled
    bool isTimeBased;                   // Whether zone uses schedule
    int color;                          // ARGB color for map display
    bool showNameOnMap;                 // Whether to show zone name on map
    ref VoidlinePVPZoneScheduleConfig schedule; // Time-based schedule
    
    void VoidlinePVPZoneDefinition()
    {
        name = "Unnamed Zone";
        description = "";
        position = "0 0 0";
        radius = 300.0;
        zoneType = "manual";
        isActive = true;
        isTimeBased = false;
        color = 0xFFFF0000; // Red default
        showNameOnMap = true; // Show name by default
        schedule = new VoidlinePVPZoneScheduleConfig();
    }
};

class VoidlinePVPTerritorySettings
{
    bool enabled;                       // Territory integration enabled
    float defaultRadius;                // Default radius for territory zones
    int defaultColor;                   // Default color for territory zones
    bool useCustomRadius;               // Whether to override territory radius
    bool inheritActiveStatus;           // Whether to inherit territory active status
    bool isTimeBased;                   // Whether territories use time-based scheduling
    bool showNameOnMap;                 // Whether to show territory zone names on map
    bool showMarkersOnMap;              // Whether to show territory zone markers/circles on map
    ref VoidlinePVPZoneScheduleConfig schedule; // Time-based schedule for territories
    int scanIntervalMinutes;            // How often to scan for territory flags
    
    void VoidlinePVPTerritorySettings()
    {
        enabled = true;
        defaultRadius = 150.0;
        defaultColor = 0xFF00FFFF; // Cyan default
        useCustomRadius = false;
        inheritActiveStatus = true;
        isTimeBased = false;
        showNameOnMap = true; // Show names by default
        showMarkersOnMap = true; // Show markers by default
        schedule = new VoidlinePVPZoneScheduleConfig();
        scanIntervalMinutes = 5;
    }
};

class VoidlinePVPConfig
{
    ref array<ref VoidlinePVPZoneDefinition> regularZones;
    ref VoidlinePVPTerritorySettings territorySettings;
    int scanIntervalMinutes;            // How often to check zones
    bool debugLogging;                  // Enable debug output
    bool showMarkersOnMap;              // Global setting: whether to show zone markers on map

    // PVE Kill Penalty Settings (Hardline Integration)
    int PVEKillPenalty;                 // 1 = enabled, 0 = disabled - Penalty for killing players outside PVP zones
    int PVEKillPenaltyAmount;           // Amount of reputation to REMOVE when killing outside PVP zone (default: 2500)

    void VoidlinePVPConfig()
    {
        regularZones = new array<ref VoidlinePVPZoneDefinition>;
        territorySettings = new VoidlinePVPTerritorySettings();
        scanIntervalMinutes = 5;
        debugLogging = false;
        showMarkersOnMap = true; // Show markers by default

        // PVE Kill Penalty - set to 0 so migration can detect old configs
        // Actual defaults are set in CreateDefaultConfig() and migration
        PVEKillPenalty = 0;
        PVEKillPenaltyAmount = 0;
    }
};