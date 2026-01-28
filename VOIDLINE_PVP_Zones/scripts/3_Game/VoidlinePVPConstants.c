// Game-level constants and definitions for VOIDLINE PVP System

class VoidlinePVPConstants
{
    // RPC Identifiers
    const static string RPC_RECEIVE_ZONE_DATA = "VoidlinePVP_ReceiveZoneData";
    const static string RPC_NOTIFY_PVP_ENTRY = "VoidlinePVP_NotifyPVPZoneEntry";
    const static string RPC_NOTIFY_PVP_EXIT = "VoidlinePVP_NotifyPVPZoneExit";
    const static string RPC_UPDATE_ZONE_VISIBILITY = "VoidlinePVP_UpdateZoneVisibility";
    
    // Zone Colors (ARGB format)
    const static int COLOR_PVP_RED = 0xFFFF0000;
    const static int COLOR_PVP_ORANGE = 0xFFFF8800;
    const static int COLOR_PVP_YELLOW = 0xFFFFFF00;
    const static int COLOR_TERRITORY_CYAN = 0xFF00FFFF;
    const static int COLOR_INACTIVE_GRAY = 0xFF808080;
    
    // Time constants
    const static int SECONDS_PER_MINUTE = 60;
    const static int MINUTES_PER_HOUR = 60;
    const static int HOURS_PER_DAY = 24;
    const static int DAYS_PER_WEEK = 7;
    
    // Days of week (1=Monday, 7=Sunday)
    const static int DAY_MONDAY = 1;
    const static int DAY_TUESDAY = 2;
    const static int DAY_WEDNESDAY = 3;
    const static int DAY_THURSDAY = 4;
    const static int DAY_FRIDAY = 5;
    const static int DAY_SATURDAY = 6;
    const static int DAY_SUNDAY = 7;
    
    // Default values
    const static float DEFAULT_ZONE_RADIUS = 300.0;
    const static float DEFAULT_TERRITORY_RADIUS = 150.0;
    const static int DEFAULT_SCAN_INTERVAL_MINUTES = 5;
    const static int DEFAULT_TIMEZONE_OFFSET = 1; // UTC+1 (MEZ)
    
    // Zone type identifiers
    const static string ZONE_TYPE_MANUAL = "manual";
    const static string ZONE_TYPE_TERRITORY = "territory";
    const static string ZONE_TYPE_TIMED = "timed";
    
    // Config paths
    const static string CONFIG_PATH = "$profile:VoidlinePVP/";
    const static string ZONES_CONFIG_FILE = "zones.json";
    const static string ZONES_CONFIG_FULL_PATH = "$profile:VoidlinePVP/zones.json";
    const static string LOG_PREFIX = "[VoidlinePVP]";
}
