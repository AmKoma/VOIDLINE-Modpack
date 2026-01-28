class VoidlinePVPZoneSchedule
{
    private ref array<int> m_ActiveDays;
    private string m_StartTime;
    private string m_EndTime;
    private int m_TimezoneOffset;
    private bool m_IsEnabled;
    
    void VoidlinePVPZoneSchedule()
    {
        m_ActiveDays = new array<int>();
        m_StartTime = "18:00";
        m_EndTime = "22:00";
        m_TimezoneOffset = 0;
        m_IsEnabled = false;
    }
    
    void SetSchedule(array<int> days, string startTime, string endTime, int timezoneOffset)
    {
        if (!days || days.Count() == 0)
            return;
            
        m_ActiveDays.Clear();
        for (int i = 0; i < days.Count(); i++)
        {
            m_ActiveDays.Insert(days[i]);
        }
        
        m_StartTime = startTime;
        m_EndTime = endTime;
        m_TimezoneOffset = timezoneOffset;
        m_IsEnabled = true;
    }
    
    bool IsActiveNow()
    {
        if (!m_IsEnabled)
            return true; // Always active if no schedule is set
            
        // Get REAL TIME using Community Framework instead of game time!
        CF_Date realTime = CF_Date.Now();
        
        int year = realTime.GetYear();
        int month = realTime.GetMonth();
        int day = realTime.GetDay();
        int hour = realTime.GetHours();
        int minute = realTime.GetMinutes();
        
        // Get day of week (0=Sunday in CF_Date, convert to 1=Monday)
        int cfDayOfWeek = realTime.GetDayOfWeek(); // 0=Sun, 1=Mon, ..., 6=Sat
        int dayOfWeek;
        if (cfDayOfWeek == 0)
            dayOfWeek = 7; // Sunday becomes 7
        else
            dayOfWeek = cfDayOfWeek; // Mon=1, Tue=2, etc.
        
        // Debug logging with REAL TIME
        Print("[VoidlinePVP] REAL TIME Schedule Check - Current: " + year + "-" + month + "-" + day + " " + hour + ":" + minute);
        Print("[VoidlinePVP] REAL DAY of week: " + dayOfWeek + " (1=Mon, 7=Sun) - CF_Date returned: " + cfDayOfWeek);
        
        // Check if today is in active days
        bool isDayActive = false;
        Print("[VoidlinePVP] Checking if day " + dayOfWeek + " is in active days: " + m_ActiveDays.Count() + " configured days");
        for (int i = 0; i < m_ActiveDays.Count(); i++)
        {
            Print("[VoidlinePVP] Configured active day: " + m_ActiveDays[i]);
            if (m_ActiveDays[i] == dayOfWeek)
            {
                isDayActive = true;
                break;
            }
        }
        
        Print("[VoidlinePVP] Day active check result: " + isDayActive);
        
        if (!isDayActive)
        {
            Print("[VoidlinePVP] Zone INACTIVE: Current REAL day (" + dayOfWeek + ") not in active days");
            return false;
        }
            
        // Apply timezone offset
        hour += m_TimezoneOffset;
        if (hour >= 24)
            hour -= 24; 
            
        if (hour < 0)
            hour += 24;
        
        // Check time range
        return IsTimeActive(hour, minute);
    }
    
    private bool IsTimeActive(int hour, int minute)
    {
        int startHour, startMinute;
        ParseTime(m_StartTime, startHour, startMinute);
        
        int endHour, endMinute;
        ParseTime(m_EndTime, endHour, endMinute);
        
        int currentMinutes = hour * 60 + minute;
        int startMinutes = startHour * 60 + startMinute;
        int endMinutes = endHour * 60 + endMinute;
        
        Print("[VoidlinePVP] Time check - Current: " + hour + ":" + minute + " (" + currentMinutes + " min)");
        Print("[VoidlinePVP] Time check - Start: " + startHour + ":" + startMinute + " (" + startMinutes + " min)");
        Print("[VoidlinePVP] Time check - End: " + endHour + ":" + endMinute + " (" + endMinutes + " min)");
        
        bool timeActive;
        // Handle overnight schedules (end time is next day)
        if (endMinutes < startMinutes)
        {
            // Schedule spans midnight
            timeActive = (currentMinutes >= startMinutes || currentMinutes <= endMinutes);
            Print("[VoidlinePVP] Overnight schedule detected");
        }
        else
        {
            // Normal same-day schedule
            timeActive = (currentMinutes >= startMinutes && currentMinutes <= endMinutes);
            Print("[VoidlinePVP] Same-day schedule");
        }
        
        Print("[VoidlinePVP] Time active result: " + timeActive);
        return timeActive;
    }
    
    private void ParseTime(string timeStr, out int hour, out int minute)
    {
        hour = 0;
        minute = 0;
        
        int colonPos = timeStr.IndexOf(":");
        if (colonPos > 0)
        {
            string hourStr = timeStr.Substring(0, colonPos);
            string minuteStr = timeStr.Substring(colonPos + 1, timeStr.Length() - colonPos - 1);
            
            hour = hourStr.ToInt();
            minute = minuteStr.ToInt();
        }
    }
    
    // Getters
    array<int> GetActiveDays()
    {
        return m_ActiveDays;
    }
    
    string GetStartTime()
    {
        return m_StartTime;
    }
    
    string GetEndTime()
    {
        return m_EndTime;
    }
    
    int GetTimezoneOffset()
    {
        return m_TimezoneOffset;
    }
    
    bool IsEnabled()
    {
        return m_IsEnabled;
    }
    
    void SetEnabled(bool enabled)
    {
        m_IsEnabled = enabled;
    }
}
