class VoidlinePVPZoneManager
{
    private static ref VoidlinePVPZoneManager m_Instance;
    private ref array<ref VoidlinePVPZone> m_PVPZones;
    private ref array<ref VoidlinePVPZone> m_TerritoryZones;
    private ref map<PlayerBase, bool> m_PlayersInPVP;
    private ref map<string, ref VoidlinePVPZone> m_ZonesByName;

    // Territory flag zone settings
    private bool m_TerritoryZonesEnabled;
    private float m_TerritoryZoneRadius;
    private int m_TerritoryZoneColor;
    private bool m_TerritoryZonesTimeBased;
    private bool m_TerritoryShowNameOnMap;
    private bool m_TerritoryShowMarkersOnMap;
    private ref VoidlinePVPZoneSchedule m_TerritorySchedule;
    private string m_TerritoryZonePrefix;
    private int m_TerritoryScanInterval; // minutes
    
    // Global zone settings
    private bool m_GlobalShowMarkersOnMap;

    // PVE Kill Penalty Settings (Hardline Integration)
    private bool m_PVEKillPenaltyEnabled;
    private int m_PVEKillPenaltyAmount;

    void VoidlinePVPZoneManager()
    {
        m_PVPZones = new array<ref VoidlinePVPZone>();
        m_TerritoryZones = new array<ref VoidlinePVPZone>();
        m_PlayersInPVP = new map<PlayerBase, bool>();
        m_ZonesByName = new map<string, ref VoidlinePVPZone>();
        m_TerritorySchedule = new VoidlinePVPZoneSchedule();

        // Initialize territory settings
        m_TerritoryZonesEnabled = false;
        m_TerritoryZoneRadius = 150;
        m_TerritoryZoneColor = VoidlinePVPConstants.COLOR_TERRITORY_CYAN;
        m_TerritoryZonesTimeBased = false;
        m_TerritoryShowNameOnMap = true;
        m_TerritoryShowMarkersOnMap = true;
        m_TerritoryZonePrefix = "Territory PVP: ";
        m_TerritoryScanInterval = 5;
        
        // Initialize global settings
        m_GlobalShowMarkersOnMap = true;

        // Initialize PVE Kill Penalty settings
        m_PVEKillPenaltyEnabled = true;
        m_PVEKillPenaltyAmount = 2500;

        // Load zones from configuration
        LoadPVPZonesFromConfig();
    }

    static VoidlinePVPZoneManager GetInstance()
    {
        if (!m_Instance)
            m_Instance = new VoidlinePVPZoneManager();
        return m_Instance;
    }

    void LoadPVPZonesFromConfig()
    {
        Print("[VoidlinePVP] Loading PVP zones from configuration...");

        // Create config directory if it doesn't exist
        MakeDirectory(VoidlinePVPConstants.CONFIG_PATH);

        // Load or create configuration
        ref VoidlinePVPConfig config = LoadConfigFromJSON();
        if (!config)
        {
            Print("[VoidlinePVP] Failed to load configuration, creating default config");
            config = CreateDefaultConfig();
            SaveConfigToJSON(config);
        }

        // Clear existing zones
        m_PVPZones.Clear();

        // Load global settings
        m_GlobalShowMarkersOnMap = config.showMarkersOnMap;
        Print("[VoidlinePVP] Global show markers setting: " + m_GlobalShowMarkersOnMap);

        // Load PVE Kill Penalty settings
        m_PVEKillPenaltyEnabled = (config.PVEKillPenalty == 1);
        m_PVEKillPenaltyAmount = config.PVEKillPenaltyAmount;
        Print("[VoidlinePVP] PVE Kill Penalty: " + m_PVEKillPenaltyEnabled + " (Amount: " + m_PVEKillPenaltyAmount + ")");

        // Load regular zones from config
        ParseRegularPVPZones(config);

        // Load territory zones if enabled
        if (config.territorySettings.enabled)
        {
            ParseTerritorySettings(config.territorySettings);
        }

        Print(string.Format("[VoidlinePVP] Loaded %1 total PVP zones", m_PVPZones.Count()));

        // Start monitoring
        StartZoneMonitoring();
    }

    void StartZoneMonitoring()
    {
        Print("[VoidlinePVP] Starting zone monitoring system...");

        // Start zone checking timer
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckPlayersInZones, 1000, true);

        // Start time-based zone checking timer
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckTimeBasedZones, 60000, true);

        // Start territory flag scanning timer to handle new/deleted flags
        if (m_TerritoryZonesEnabled)
        {
            int scanIntervalMs = m_TerritoryScanInterval * 60 * 1000; // Convert minutes to milliseconds
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateTerritoryZones, scanIntervalMs, true);
            Print("[VoidlinePVP] Territory zone monitoring enabled - scan interval: " + m_TerritoryScanInterval + " minutes");
        }

        Print("[VoidlinePVP] Zone monitoring started successfully");
    }

    ref VoidlinePVPConfig LoadConfigFromJSON()
    {
        if (!FileExist(VoidlinePVPConstants.ZONES_CONFIG_FULL_PATH))
        {
            Print("[VoidlinePVP] Configuration file not found: " + VoidlinePVPConstants.ZONES_CONFIG_FULL_PATH);
            return null;
        }

        ref VoidlinePVPConfig config = new VoidlinePVPConfig();
        JsonFileLoader<VoidlinePVPConfig>.JsonLoadFile(VoidlinePVPConstants.ZONES_CONFIG_FULL_PATH, config);

        if (!config)
        {
            Print("[VoidlinePVP] Failed to load JSON configuration");
            return null;
        }

        // Migration: Check if new PVE Kill Penalty fields need to be added to existing config
        bool configUpdated = false;

        // If PVEKillPenaltyAmount is 0, it means the old config doesn't have this field - set default
        if (config.PVEKillPenaltyAmount == 0)
        {
            config.PVEKillPenaltyAmount = 2500; // Default value
            config.PVEKillPenalty = 1;          // Enable by default
            configUpdated = true;
            Print("[VoidlinePVP] Migration: Added PVE Kill Penalty settings to config (enabled, amount: 2500)");
        }

        // Save config if it was updated with new fields
        if (configUpdated)
        {
            SaveConfigToJSON(config);
            Print("[VoidlinePVP] Config file updated with new settings");
        }

        Print("[VoidlinePVP] Successfully loaded configuration from JSON");
        return config;
    }

    void SaveConfigToJSON(VoidlinePVPConfig config)
    {
        if (!config)
        {
            Print("[VoidlinePVP] Cannot save null configuration");
            return;
        }

        JsonFileLoader<VoidlinePVPConfig>.JsonSaveFile(VoidlinePVPConstants.ZONES_CONFIG_FULL_PATH, config);
        Print("[VoidlinePVP] Configuration saved to: " + VoidlinePVPConstants.ZONES_CONFIG_FULL_PATH);
    }

    ref VoidlinePVPConfig CreateDefaultConfig()
    {
        ref VoidlinePVPConfig config = new VoidlinePVPConfig();

        // Create example regular zone
        ref VoidlinePVPZoneDefinition exampleZone = new VoidlinePVPZoneDefinition();
        exampleZone.name = "Example PVP Zone";
        exampleZone.description = "This is an example PVP zone - edit zones.json to customize";
        exampleZone.position = Vector(7500, 0, 7500); // Center of Chernarus
        exampleZone.radius = 300.0;
        exampleZone.zoneType = "manual";
        exampleZone.isActive = true;
        exampleZone.isTimeBased = false;
        exampleZone.showNameOnMap = true; // Show zone name on map
        exampleZone.color = VoidlinePVPConstants.COLOR_PVP_RED;

        config.regularZones.Insert(exampleZone);

        // Configure territory settings
        config.territorySettings.enabled = true;
        config.territorySettings.defaultRadius = 150.0;
        config.territorySettings.defaultColor = VoidlinePVPConstants.COLOR_TERRITORY_CYAN;
        config.territorySettings.useCustomRadius = false;
        config.territorySettings.inheritActiveStatus = true;
        config.territorySettings.isTimeBased = false;
        config.territorySettings.showNameOnMap = true; // Show territory zone names on map
        config.territorySettings.showMarkersOnMap = true; // Show territory zone markers on map
        
        // Set default territory schedule (example: weekends)
        config.territorySettings.schedule.activeDays.Insert(6); // Saturday
        config.territorySettings.schedule.activeDays.Insert(7); // Sunday
        config.territorySettings.schedule.startTime = "18:00";
        config.territorySettings.schedule.endTime = "22:00";
        config.territorySettings.schedule.timezoneOffset = 1;

        // Set default scan interval
        config.scanIntervalMinutes = 5;
        config.debugLogging = false;

        // PVE Kill Penalty Settings (Hardline Integration)
        config.PVEKillPenalty = 1;           // 1 = enabled, 0 = disabled
        config.PVEKillPenaltyAmount = 2500;  // Reputation penalty for killing outside PVP zones

        return config;
    }

    void ParseRegularPVPZones(VoidlinePVPConfig config)
    {
        if (!config || !config.regularZones)
        {
            Print("[VoidlinePVP] No regular zones configuration found");
            return;
        }

        Print("[VoidlinePVP] Parsing " + config.regularZones.Count() + " regular PVP zones from config...");

        for (int i = 0; i < config.regularZones.Count(); i++)
        {
            ref VoidlinePVPZoneDefinition zoneDef = config.regularZones[i];
            if (!zoneDef)
                continue;

            // Only create zone if it's active
            if (!zoneDef.isActive)
            {
                Print("[VoidlinePVP] Skipping inactive zone: " + zoneDef.name);
                continue;
            }

            // Use the position from config
            vector position = zoneDef.position;

            Print("[VoidlinePVP] Creating zone: " + zoneDef.name + " at " + position.ToString() + " (radius: " + zoneDef.radius + ")");

            // Create the zone with showNameOnMap setting from config and global showMarkersOnMap setting
            VoidlinePVPZone zone = new VoidlinePVPZone(position, zoneDef.radius, zoneDef.name, zoneDef.description, zoneDef.color, zoneDef.zoneType, zoneDef.showNameOnMap, m_GlobalShowMarkersOnMap);

            // Handle time-based zones
            if (zoneDef.isTimeBased && zoneDef.schedule)
            {
                Print("[VoidlinePVP] Setting up time-based schedule for zone: " + zoneDef.name);
                zone.SetSchedule(zoneDef.schedule.activeDays, zoneDef.schedule.startTime, zoneDef.schedule.endTime, zoneDef.schedule.timezoneOffset);
            }

            Print("[VoidlinePVP] Zone '" + zoneDef.name + "' created - Currently active: " + zone.IsCurrentlyActive());

            AddPVPZone(zone);
        }

        Print("[VoidlinePVP] Successfully parsed " + config.regularZones.Count() + " regular zones");
    }

    void ParseTerritorySettings(VoidlinePVPTerritorySettings territorySettings)
    {
        if (!territorySettings)
        {
            Print("[VoidlinePVP] No territory settings provided, using defaults");
            m_TerritoryZonesEnabled = false;
            m_TerritoryZoneRadius = 150;
            m_TerritoryZoneColor = VoidlinePVPConstants.COLOR_TERRITORY_CYAN;
            m_TerritoryZonesTimeBased = false;
            m_TerritoryScanInterval = 5;
            return;
        }

        Print("[VoidlinePVP] Applying territory settings from configuration...");

        // Apply settings from config object
        m_TerritoryZonesEnabled = territorySettings.enabled;
        m_TerritoryZoneRadius = territorySettings.defaultRadius;
        m_TerritoryZoneColor = territorySettings.defaultColor;
        m_TerritoryZonesTimeBased = territorySettings.isTimeBased;
        m_TerritoryShowNameOnMap = territorySettings.showNameOnMap;
        m_TerritoryShowMarkersOnMap = territorySettings.showMarkersOnMap;
        m_TerritoryScanInterval = territorySettings.scanIntervalMinutes;

        // Setup territory schedule if time-based
        if (m_TerritoryZonesTimeBased && territorySettings.schedule)
        {
            m_TerritorySchedule.SetSchedule(territorySettings.schedule.activeDays, territorySettings.schedule.startTime, territorySettings.schedule.endTime, territorySettings.schedule.timezoneOffset);
            Print("[VoidlinePVP] Territory time-based schedule configured");
        }

        Print("[VoidlinePVP] Territory settings applied:");
        Print("[VoidlinePVP] - Enabled: " + m_TerritoryZonesEnabled);
        Print("[VoidlinePVP] - Radius: " + m_TerritoryZoneRadius);
        Print("[VoidlinePVP] - Color: " + m_TerritoryZoneColor);
        Print("[VoidlinePVP] - Time-based: " + m_TerritoryZonesTimeBased);
        Print("[VoidlinePVP] - Show Name On Map: " + m_TerritoryShowNameOnMap);
        Print("[VoidlinePVP] - Use Custom Radius: " + territorySettings.useCustomRadius);
        Print("[VoidlinePVP] - Inherit Active Status: " + territorySettings.inheritActiveStatus);

        // Scan for existing territory flags if enabled
        if (m_TerritoryZonesEnabled)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ScanForTerritoryFlags, 1000, false);
        }
    }

    void AddPVPZone(VoidlinePVPZone zone)
    {
        if (!zone)
            return;

        m_PVPZones.Insert(zone);
        m_ZonesByName.Set(zone.GetName(), zone);

        // Register with expansion maps immediately if active
        if (zone.IsCurrentlyActive())
        {
            RegisterZoneWithExpansionMaps(zone);
        }

        Print("[VoidlinePVP] Added PVP zone: " + zone.GetName());
    }

    void RegisterZoneWithExpansionMaps(VoidlinePVPZone zone)
    {
        if (!zone || !zone.IsCurrentlyActive())
            return;

        // Send zone data to all connected clients via RPC
        VoidlinePVPRPCManager.GetInstance().BroadcastZoneData(zone.GetName(), zone.GetPosition(), zone.GetRadius(), zone.GetDescription(), zone.GetColor(), zone.IsCurrentlyActive(), zone.GetShowNameOnMap(), zone.GetShowMarkersOnMap());

        Print("[VoidlinePVP] Zone registered with clients: " + zone.GetName());
    }

    void GetAllTerritoryFlags(array<Object> outFlags)
    {
        // Nutze Expansion TerritoryModule um alle TerritoryFlags zu bekommen
        if (!ExpansionTerritoryModule.s_Instance)
        {
            Print("[VoidlinePVP] WARNING: ExpansionTerritoryModule not available");
            return;
        }
        
        map<int, TerritoryFlag> territoryFlags = ExpansionTerritoryModule.s_Instance.GetAllTerritoryFlags();
        if (!territoryFlags)
            return;
            
        for (int i = 0; i < territoryFlags.Count(); i++)
        {
            TerritoryFlag flag = territoryFlags.GetElement(i);
            if (flag)
                outFlags.Insert(flag);
        }
        
        Print("[VoidlinePVP] Found " + outFlags.Count() + " territory flags via Expansion");
    }

    void ScanForTerritoryFlags()
    {
        if (!m_TerritoryZonesEnabled)
            return;

        Print("[VoidlinePVP] Scanning for territory flags...");

        array<Object> allFlags = new array<Object>();
        GetAllTerritoryFlags(allFlags);

        Print("[VoidlinePVP] Scanning " + allFlags.Count() + " TerritoryFlag objects...");

        int flagsFound = 0;

        for (int i = 0; i < allFlags.Count(); i++)
        {
            Object obj = allFlags[i];
            if (!obj)
                continue;

            flagsFound++;
            vector flagPos = obj.GetPosition();
            string zoneName = m_TerritoryZonePrefix + "Player Base #" + flagsFound;

            Print("[VoidlinePVP] Found territory flag #" + flagsFound + " at " + flagPos.ToString());

            // Check if we already have a zone near this position
            bool zoneExists = false;
            for (int j = 0; j < m_TerritoryZones.Count(); j++)
            {
                if (vector.Distance(m_TerritoryZones[j].GetPosition(), flagPos) < 100)
                {
                    zoneExists = true;
                    break;
                }
            }

            if (!zoneExists)
            {
                Print("[VoidlinePVP] Creating territory PVP zone at: " + flagPos.ToString());

                VoidlinePVPZone territoryZone = new VoidlinePVPZone(flagPos, m_TerritoryZoneRadius, zoneName, "Territory Flag PVP Zone", m_TerritoryZoneColor, "territory", m_TerritoryShowNameOnMap, m_TerritoryShowMarkersOnMap);

                // Apply time-based schedule if enabled
                if (m_TerritoryZonesTimeBased && m_TerritorySchedule)
                {
                    territoryZone.SetScheduleFromObject(m_TerritorySchedule);
                }

                m_TerritoryZones.Insert(territoryZone);
                m_ZonesByName.Set(zoneName, territoryZone);

                Print("[VoidlinePVP] Created territory PVP zone: " + zoneName + " - Currently active: " + territoryZone.IsCurrentlyActive());

                // Always register and broadcast territory zones (they handle their own active state)
                RegisterZoneWithExpansionMaps(territoryZone);
                VoidlinePVPRPCManager.GetInstance().BroadcastZoneData(territoryZone.GetName(), territoryZone.GetPosition(), territoryZone.GetRadius(), territoryZone.GetDescription(), territoryZone.GetColor(), territoryZone.IsCurrentlyActive(), territoryZone.GetShowNameOnMap(), territoryZone.GetShowMarkersOnMap());
                Print("[VoidlinePVP] Territory zone broadcasted to all clients - Active: " + territoryZone.IsCurrentlyActive());
            }
        }

        Print("[VoidlinePVP] Territory scan complete. Found " + flagsFound + " territory flags, created " + m_TerritoryZones.Count() + " zones");
    }

    void UpdateTerritoryZones()
    {
        if (!m_TerritoryZonesEnabled)
            return;

        Print("[VoidlinePVP] Updating territory zones - checking for new/deleted flags...");

        array<Object> allFlags = new array<Object>();
        GetAllTerritoryFlags(allFlags);

        array<vector> currentFlagPositions = new array<vector>();

        // Find all current territory flags
        for (int i = 0; i < allFlags.Count(); i++)
        {
            Object obj = allFlags[i];
            if (!obj)
                continue;

            currentFlagPositions.Insert(obj.GetPosition());
        }

        Print("[VoidlinePVP] Found " + currentFlagPositions.Count() + " territory flags, have " + m_TerritoryZones.Count() + " zones");

        // Remove zones for deleted flags
        array<ref VoidlinePVPZone> zonesToRemove = new array<ref VoidlinePVPZone>();
        
        for (int j = 0; j < m_TerritoryZones.Count(); j++)
        {
            VoidlinePVPZone zone = m_TerritoryZones[j];
            vector zonePos = zone.GetPosition();
            
            bool flagExists = false;
            for (int k = 0; k < currentFlagPositions.Count(); k++)
            {
                if (vector.Distance(zonePos, currentFlagPositions[k]) < 100) // 100m tolerance
                {
                    flagExists = true;
                    break;
                }
            }
            
            if (!flagExists)
            {
                Print("[VoidlinePVP] Territory flag removed - cleaning up zone: " + zone.GetName());
                zonesToRemove.Insert(zone);
            }
        }

        // Remove obsolete zones
        for (int l = 0; l < zonesToRemove.Count(); l++)
        {
            VoidlinePVPZone zoneToRemove = zonesToRemove[l];
            
            // Remove from client maps first
            VoidlinePVPRPCManager.GetInstance().BroadcastZoneVisibilityUpdate(zoneToRemove.GetName(), false);
            
            // Remove from our tracking
            m_TerritoryZones.RemoveItem(zoneToRemove);
            m_ZonesByName.Remove(zoneToRemove.GetName());
            
            Print("[VoidlinePVP] Removed territory zone: " + zoneToRemove.GetName());
        }

        // Add zones for new flags
        for (int m = 0; m < currentFlagPositions.Count(); m++)
        {
            vector flagPos = currentFlagPositions[m];
            
            bool zoneExists = false;
            for (int n = 0; n < m_TerritoryZones.Count(); n++)
            {
                if (vector.Distance(m_TerritoryZones[n].GetPosition(), flagPos) < 100)
                {
                    zoneExists = true;
                    break;
                }
            }
            
            if (!zoneExists)
            {
                string zoneName = m_TerritoryZonePrefix + "Player Base";
                Print("[VoidlinePVP] New territory flag detected - creating zone at: " + flagPos.ToString());
                
                VoidlinePVPZone territoryZone = new VoidlinePVPZone(flagPos, m_TerritoryZoneRadius, zoneName, "Territory Flag PVP Zone", m_TerritoryZoneColor, "territory", m_TerritoryShowNameOnMap, m_TerritoryShowMarkersOnMap);

                // Apply time-based schedule if enabled
                if (m_TerritoryZonesTimeBased && m_TerritorySchedule)
                {
                    territoryZone.SetScheduleFromObject(m_TerritorySchedule);
                }

                m_TerritoryZones.Insert(territoryZone);
                m_ZonesByName.Set(zoneName, territoryZone);

                Print("[VoidlinePVP] Created new territory zone: " + zoneName + " - Currently active: " + territoryZone.IsCurrentlyActive());

                // Broadcast to clients if active
                if (territoryZone.IsCurrentlyActive())
                {
                    RegisterZoneWithExpansionMaps(territoryZone);
                    VoidlinePVPRPCManager.GetInstance().BroadcastZoneData(territoryZone.GetName(), territoryZone.GetPosition(), territoryZone.GetRadius(), territoryZone.GetDescription(), territoryZone.GetColor(), territoryZone.IsCurrentlyActive(), territoryZone.GetShowNameOnMap(), territoryZone.GetShowMarkersOnMap());
                }
            }
        }

        Print("[VoidlinePVP] Territory zone update complete");
    }

    void CheckPlayersInZones()
    {
        if (!GetGame().IsServer())
            return;

        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);

        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (!player || !player.IsAlive())
                continue;

            CheckPlayerZoneStatus(player);
        }
    }

    void CheckPlayerZoneStatus(PlayerBase player)
    {
        if (!player)
            return;

        bool wasInPVP = false;
        if (m_PlayersInPVP.Contains(player))
            wasInPVP = m_PlayersInPVP.Get(player);

        bool isInPVP = false;
        VoidlinePVPZone currentZone = null;

        // Check all active PVP zones
        for (int i = 0; i < m_PVPZones.Count(); i++)
        {
            VoidlinePVPZone zone = m_PVPZones[i];
            if (zone.IsCurrentlyActive() && zone.IsPlayerInZone(player))
            {
                isInPVP = true;
                currentZone = zone;
                break;
            }
        }

        // Check territory zones if no regular zone found
        if (!isInPVP)
        {
            for (int j = 0; j < m_TerritoryZones.Count(); j++)
            {
                if (m_TerritoryZones[j].IsCurrentlyActive() && m_TerritoryZones[j].IsPlayerInZone(player))
                {
                    isInPVP = true;
                    currentZone = m_TerritoryZones[j];
                    break;
                }
            }
        }

        // Handle zone entry/exit
        if (isInPVP != wasInPVP)
        {
            m_PlayersInPVP.Set(player, isInPVP);

            if (isInPVP && currentZone)
            {
                OnPlayerEnterPVPZone(player, currentZone);
            }
            else if (!isInPVP)
            {
                OnPlayerExitPVPZone(player);
            }
        }
    }

    void OnPlayerEnterPVPZone(PlayerBase player, VoidlinePVPZone zone)
    {
        if (!player || !zone)
            return;

        string playerName = player.GetIdentity().GetName();
        string zoneName = zone.GetName();
        string message = "You entered PVP Zone: " + zoneName;

        Print("[VoidlinePVP] SERVER: Player '" + playerName + "' entered zone '" + zoneName + "'");

        // Notify player via RPC
        VoidlinePVPRPCManager.GetInstance().NotifyZoneEntry(player.GetIdentity(), message);

        // Also send zone data to make sure client has the zone info
        VoidlinePVPRPCManager.GetInstance().SendZoneData(player.GetIdentity(), zoneName, zone.GetPosition(), zone.GetRadius(), zone.GetDescription(), zone.GetColor(), zone.IsCurrentlyActive(), zone.GetShowNameOnMap());

        Print("[VoidlinePVP] Zone entry notification sent to: " + playerName);
    }

    void OnPlayerExitPVPZone(PlayerBase player)
    {
        if (!player)
            return;

        string playerName = player.GetIdentity().GetName();
        string message = "You left the PVP Zone";

        Print("[VoidlinePVP] SERVER: Player '" + playerName + "' exited PVP zone");

        // Notify player via RPC
        VoidlinePVPRPCManager.GetInstance().NotifyZoneExit(player.GetIdentity(), message);

        Print("[VoidlinePVP] Zone exit notification sent to: " + playerName);
    }

    void CheckTimeBasedZones()
    {
        if (!GetGame().IsServer())
            return;

        bool zonesUpdated = false;

        // Check all regular zones
        for (int i = 0; i < m_PVPZones.Count(); i++)
        {
            bool wasActive = m_PVPZones[i].IsCurrentlyActive();
            m_PVPZones[i].UpdateTimeBasedActivity();
            bool isActive = m_PVPZones[i].IsCurrentlyActive();

            if (wasActive != isActive)
            {
                zonesUpdated = true;
                OnZoneActivityChanged(m_PVPZones[i], isActive);
            }
        }

        // Check territory zones
        for (int j = 0; j < m_TerritoryZones.Count(); j++)
        {
            bool wasActive2 = m_TerritoryZones[j].IsCurrentlyActive();
            m_TerritoryZones[j].UpdateTimeBasedActivity();
            bool isActive2 = m_TerritoryZones[j].IsCurrentlyActive();

            if (wasActive2 != isActive2)
            {
                zonesUpdated = true;
                OnZoneActivityChanged(m_TerritoryZones[j], isActive2);
            }
        }

        if (zonesUpdated)
        {
            Print("[VoidlinePVP] Time-based zones updated");
        }
    }

    void OnZoneActivityChanged(VoidlinePVPZone zone, bool isActive)
    {
        if (!zone)
            return;

        string statusText;
        if (isActive)
            statusText = "ACTIVE";
        else
            statusText = "INACTIVE";

        Print("[VoidlinePVP] Zone " + zone.GetName() + " is now " + statusText);

        // Update all clients with new zone status
        VoidlinePVPRPCManager.GetInstance().BroadcastZoneVisibilityUpdate(zone.GetName(), isActive);
    }

    VoidlinePVPZone GetZoneByName(string name)
    {
        if (m_ZonesByName.Contains(name))
            return m_ZonesByName.Get(name);
        return null;
    }

    map<string, ref VoidlinePVPZone> GetZonesByName()
    {
        return m_ZonesByName;
    }

    array<ref VoidlinePVPZone> GetTerritoryZones()
    {
        return m_TerritoryZones;
    }

    array<ref VoidlinePVPZone> GetAllZones()
    {
        array<ref VoidlinePVPZone> allZones = new array<ref VoidlinePVPZone>();

        for (int i = 0; i < m_PVPZones.Count(); i++)
            allZones.Insert(m_PVPZones[i]);

        for (int j = 0; j < m_TerritoryZones.Count(); j++)
            allZones.Insert(m_TerritoryZones[j]);

        return allZones;
    }

    array<ref VoidlinePVPZone> GetActiveZones()
    {
        array<ref VoidlinePVPZone> activeZones = new array<ref VoidlinePVPZone>();

        // Add active regular zones
        for (int i = 0; i < m_PVPZones.Count(); i++)
        {
            if (m_PVPZones[i].IsCurrentlyActive())
                activeZones.Insert(m_PVPZones[i]);
        }

        // Add active territory zones
        for (int j = 0; j < m_TerritoryZones.Count(); j++)
        {
            if (m_TerritoryZones[j].IsCurrentlyActive())
                activeZones.Insert(m_TerritoryZones[j]);
        }

        return activeZones;
    }

    bool IsPlayerInAnyPVPZone(PlayerBase player)
    {
        if (!player)
            return false;

        // Check regular zones
        for (int i = 0; i < m_PVPZones.Count(); i++)
        {
            if (m_PVPZones[i].IsCurrentlyActive() && m_PVPZones[i].IsPlayerInZone(player))
                return true;
        }

        // Check territory zones
        for (int j = 0; j < m_TerritoryZones.Count(); j++)
        {
            if (m_TerritoryZones[j].IsCurrentlyActive() && m_TerritoryZones[j].IsPlayerInZone(player))
                return true;
        }

        return false;
    }

    /**
     * Check if a position is inside any currently active PVP zone
     * Used for AI position checks and other non-player entities
     * @param position - World position to check
     * @return True if position is inside any active PVP zone
     */
    bool IsPositionInAnyActivePVPZone(vector position)
    {
        // Check regular zones
        for (int i = 0; i < m_PVPZones.Count(); i++)
        {
            if (m_PVPZones[i].IsCurrentlyActive() && m_PVPZones[i].IsPositionInZone(position))
                return true;
        }

        // Check territory zones
        for (int j = 0; j < m_TerritoryZones.Count(); j++)
        {
            if (m_TerritoryZones[j].IsCurrentlyActive() && m_TerritoryZones[j].IsPositionInZone(position))
                return true;
        }

        return false;
    }

    // =========================================================================
    // EXTERNAL MOD API - For other mods to create/manage custom zones
    // =========================================================================
    
    /**
     * Creates a custom PVP zone for external mods (e.g. airdrops, events)
     * @param modName - Unique identifier for the mod creating the zone
     * @param zoneName - Name of the zone (will be prefixed with modName)
     * @param position - World position of the zone
     * @param radius - Zone radius in meters
     * @param description - Zone description shown to players
     * @param color - Zone color (use VoidlinePVPConstants colors)
     * @param duration - Duration in seconds (0 = permanent until manually removed)
     * @param showNameOnMap - Whether to show zone name on map (default: true)
     * @return Full zone name that can be used to remove the zone later
     */
    string CreateCustomZone(string modName, string zoneName, vector position, float radius, string description, int color, int duration = 0, bool showNameOnMap = true)
    {
        if (!modName || modName == "" || !zoneName || zoneName == "")
        {
            Print("[VoidlinePVP] ERROR: CreateCustomZone requires valid modName and zoneName");
            return "";
        }

        string fullZoneName = modName + ": " + zoneName;
        
        // Check if zone already exists
        if (m_ZonesByName.Contains(fullZoneName))
        {
            Print("[VoidlinePVP] WARNING: Custom zone already exists: " + fullZoneName);
            return fullZoneName;
        }

        Print("[VoidlinePVP] Creating custom zone for mod '" + modName + "': " + fullZoneName);
        Print("[VoidlinePVP] Position: " + position.ToString() + ", Radius: " + radius + "m, ShowName: " + showNameOnMap);

        // Create the zone with showNameOnMap parameter and global showMarkersOnMap setting
        VoidlinePVPZone customZone = new VoidlinePVPZone(position, radius, fullZoneName, description, color, "custom", showNameOnMap, m_GlobalShowMarkersOnMap);
        
        // Add to our tracking
        m_PVPZones.Insert(customZone);
        m_ZonesByName.Set(fullZoneName, customZone);

        // Register with clients immediately
        RegisterZoneWithExpansionMaps(customZone);
        VoidlinePVPRPCManager.GetInstance().BroadcastZoneData(customZone.GetName(), customZone.GetPosition(), customZone.GetRadius(), customZone.GetDescription(), customZone.GetColor(), customZone.IsCurrentlyActive(), customZone.GetShowNameOnMap(), customZone.GetShowMarkersOnMap());

        Print("[VoidlinePVP] Custom zone created and broadcasted: " + fullZoneName);

        return fullZoneName;
    }

    /**
     * Removes a custom zone created by external mod
     * @param fullZoneName - The full zone name returned by CreateCustomZone
     * @return True if zone was found and removed
     */
    bool RemoveCustomZone(string fullZoneName)
    {
        if (!fullZoneName || fullZoneName == "")
        {
            Print("[VoidlinePVP] ERROR: RemoveCustomZone requires valid zone name");
            return false;
        }

        if (!m_ZonesByName.Contains(fullZoneName))
        {
            Print("[VoidlinePVP] WARNING: Custom zone not found for removal: " + fullZoneName);
            return false;
        }

        VoidlinePVPZone zoneToRemove = m_ZonesByName.Get(fullZoneName);
        if (!zoneToRemove)
            return false;

        Print("[VoidlinePVP] Removing custom zone: " + fullZoneName);

        // Remove from client maps first
        VoidlinePVPRPCManager.GetInstance().BroadcastZoneVisibilityUpdate(fullZoneName, false);

        // Remove from our tracking
        m_PVPZones.RemoveItem(zoneToRemove);
        m_ZonesByName.Remove(fullZoneName);

        // Notify players who might be in the zone
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);
        for (int i = 0; i < players.Count(); i++)
        {
            PlayerBase player = PlayerBase.Cast(players[i]);
            if (player && zoneToRemove.IsPlayerInZone(player))
            {
                VoidlinePVPRPCManager.GetInstance().NotifyZoneExit(player.GetIdentity(), "Custom zone '" + fullZoneName + "' has been removed");
            }
        }

        Print("[VoidlinePVP] Custom zone removed successfully: " + fullZoneName);
        return true;
    }

    /**
     * Internal method for auto-removal of timed zones
     */
    private void RemoveCustomZoneInternal(string fullZoneName)
    {
        Print("[VoidlinePVP] Auto-removing timed custom zone: " + fullZoneName);
        RemoveCustomZone(fullZoneName);
    }

    /**
     * Get all custom zones created by a specific mod
     * @param modName - Name of the mod
     * @return Array of zone names belonging to the mod
     */
    array<string> GetCustomZonesByMod(string modName)
    {
        array<string> modZones = new array<string>();
        
        if (!modName || modName == "")
            return modZones;

        string prefix = modName + ": ";
        
        array<string> allZoneNames = m_ZonesByName.GetKeyArray();
        for (int i = 0; i < allZoneNames.Count(); i++)
        {
            string zoneName = allZoneNames[i];
            if (zoneName.IndexOf(prefix) == 0) // Starts with prefix
            {
                modZones.Insert(zoneName);
            }
        }

        return modZones;
    }

    /**
     * Remove all custom zones created by a specific mod
     * @param modName - Name of the mod
     * @return Number of zones removed
     */
    int RemoveAllCustomZonesByMod(string modName)
    {
        array<string> modZones = GetCustomZonesByMod(modName);
        int removedCount = 0;

        Print("[VoidlinePVP] Removing all custom zones for mod: " + modName + " (" + modZones.Count() + " zones)");

        for (int i = 0; i < modZones.Count(); i++)
        {
            if (RemoveCustomZone(modZones[i]))
                removedCount++;
        }

        Print("[VoidlinePVP] Removed " + removedCount + " custom zones for mod: " + modName);
        return removedCount;
    }

    /**
     * Check if a custom zone exists
     * @param fullZoneName - The full zone name
     * @return True if zone exists
     */
    bool CustomZoneExists(string fullZoneName)
    {
        return m_ZonesByName.Contains(fullZoneName);
    }

    // =========================================================================
    // END EXTERNAL MOD API
    // =========================================================================

    // =========================================================================
    // PVE KILL PENALTY API (Hardline Integration)
    // =========================================================================

    /**
     * Check if PVE Kill Penalty is enabled
     * @return True if penalty is enabled
     */
    bool IsPVEKillPenaltyEnabled()
    {
        return m_PVEKillPenaltyEnabled;
    }

    /**
     * Get the PVE Kill Penalty amount
     * @return Reputation amount to remove on PVE kill
     */
    int GetPVEKillPenaltyAmount()
    {
        return m_PVEKillPenaltyAmount;
    }

    // =========================================================================
    // END PVE KILL PENALTY API
    // =========================================================================
}
