class VoidlinePVPZone
{
    vector m_Position;
    float m_Radius;
    string m_Name;
    string m_Description;
    bool m_IsActive;
    bool m_IsTimeBased;
    bool m_IsCurrentlyActiveByTime;
    int m_Color; // ARGB color for map display
    bool m_ShowNameOnMap; // Whether to show zone name on map
    bool m_ShowMarkersOnMap; // Whether to show zone markers/circles on map
    ref VoidlinePVPZoneSchedule m_Schedule;
    string m_ZoneType; // "manual", "territory", "custom"
    
    void VoidlinePVPZone(vector position, float radius, string name, string description = "", int color = 0xFFFF0000, string zoneType = "manual", bool showNameOnMap = true, bool showMarkersOnMap = true)
    {
        m_Position = position;
        m_Radius = radius;
        m_Name = name;
        m_Description = description;
        m_IsActive = true;
        m_IsTimeBased = false;
        m_IsCurrentlyActiveByTime = true;
        m_Color = color;
        m_ShowNameOnMap = showNameOnMap;
        m_ShowMarkersOnMap = showMarkersOnMap;
        m_ZoneType = zoneType;
        m_Schedule = new VoidlinePVPZoneSchedule();
    }
    
    void SetSchedule(array<int> days, string startTime, string endTime, int timezoneOffset = 0)
    {
        m_IsTimeBased = true;
        m_Schedule.SetSchedule(days, startTime, endTime, timezoneOffset);
        
        // Sofort den aktuellen Zeit-Status überprüfen
        UpdateTimeBasedActivity();
    }
    
    void SetScheduleFromObject(VoidlinePVPZoneSchedule schedule)
    {
        if (!schedule)
            return;
            
        m_IsTimeBased = true;
        m_Schedule.SetSchedule(schedule.GetActiveDays(), schedule.GetStartTime(), schedule.GetEndTime(), schedule.GetTimezoneOffset());
        
        // Sofort den aktuellen Zeit-Status überprüfen
        UpdateTimeBasedActivity();
    }
    
    void UpdateTimeBasedActivity()
    {
        if (!m_IsTimeBased)
        {
            m_IsCurrentlyActiveByTime = true;
            return;
        }
        
        bool wasActive = m_IsCurrentlyActiveByTime;
        m_IsCurrentlyActiveByTime = m_Schedule.IsActiveNow();
        
        // Log time-based activation changes mit mehr Details
        if (wasActive != m_IsCurrentlyActiveByTime)
        {
            Print("[VoidlinePVP] Zone '" + m_Name + "' time-based activity changed: " + m_IsCurrentlyActiveByTime);
        }
        
        // Debug logging für jede Überprüfung
        Print("[VoidlinePVP] DEBUG: Zone '" + m_Name + "' time check - IsTimeBased: " + m_IsTimeBased + ", IsActiveNow: " + m_IsCurrentlyActiveByTime);
    }
    
    bool IsPlayerInZone(PlayerBase player)
    {
        // Spielerposition und Zonenzentrum holen
        vector playerPos = player.GetPosition();
        return IsPositionInZone(playerPos);
    }

    /**
     * Check if a position is within this zone (2D check, ignores Y axis)
     * Used for AI position checks and other non-player entities
     */
    bool IsPositionInZone(vector position)
    {
        vector zonePos = m_Position;

        // Nur X und Z Koordinaten für 2D-Distanz verwenden
        float deltaX = position[0] - zonePos[0]; // X-Differenz
        float deltaZ = position[2] - zonePos[2]; // Z-Differenz (Y wird übersprungen)
        float distance2D = Math.Sqrt(deltaX * deltaX + deltaZ * deltaZ);

        // Prüfen ob 2D-Distanz innerhalb des Radius liegt
        return distance2D <= m_Radius;
    }
    
    void SetActive(bool active)
    {
        m_IsActive = active;
    }
    
    bool IsActive()
    {
        return m_IsActive && (!m_IsTimeBased || m_IsCurrentlyActiveByTime);
    }
    
    bool IsCurrentlyActive()
    {
        return IsActive();
    }
    
    bool IsActiveByTime()
    {
        return m_IsCurrentlyActiveByTime;
    }
    
    bool IsTimeBased()
    {
        return m_IsTimeBased;
    }
    
    vector GetPosition()
    {
        return m_Position;
    }
    
    float GetRadius()
    {
        return m_Radius;
    }
    
    string GetName()
    {
        return m_Name;
    }
    
    string GetDescription()
    {
        return m_Description;
    }
    
    int GetColor()
    {
        return m_Color;
    }
    
    void SetColor(int color)
    {
        m_Color = color;
    }
    
    string GetZoneType()
    {
        return m_ZoneType;
    }
    
    VoidlinePVPZoneSchedule GetSchedule()
    {
        return m_Schedule;
    }
    
    bool GetShowNameOnMap()
    {
        return m_ShowNameOnMap;
    }
    
    void SetShowNameOnMap(bool showName)
    {
        m_ShowNameOnMap = showName;
    }
    
    bool GetShowMarkersOnMap()
    {
        return m_ShowMarkersOnMap;
    }
    
    void SetShowMarkersOnMap(bool showMarkers)
    {
        m_ShowMarkersOnMap = showMarkers;
    }
}
