/**
 * VoidlinePVPHardlineOverride
 *
 * Overrides ExpansionHardlineModule to control reputation based on PVP zones.
 *
 * Inside PVP zones: Normal Hardline reputation gain (+2500 for player/AI kill)
 * Outside PVP zones: ONLY penalty applies (-2500), NO Expansion rep gain
 *
 * This completely replaces Expansion's rep system for kills outside PVP zones.
 */
modded class ExpansionHardlineModule
{
    /**
     * Override HandlePlayerKilledPlayer to check PVP zone status FIRST
     * - In PVP zone: Normal Expansion behavior (call super)
     * - Outside PVP zone: Skip Expansion, apply ONLY our penalty
     */
    override protected void HandlePlayerKilledPlayer(PlayerBase killer, PlayerBase victim, int reputation, bool victimIsAI = false)
    {
        // Only process on server
        if (!GetGame().IsServer())
        {
            super.HandlePlayerKilledPlayer(killer, victim, reputation, victimIsAI);
            return;
        }

        // Skip suicide
        if (killer == victim)
        {
            super.HandlePlayerKilledPlayer(killer, victim, reputation, victimIsAI);
            return;
        }

        // Get PVP Zone Manager
        VoidlinePVPZoneManager zoneManager = VoidlinePVPZoneManager.GetInstance();
        if (!zoneManager)
        {
            Print("[VoidlinePVP] Hardline Override: Could not get ZoneManager instance");
            super.HandlePlayerKilledPlayer(killer, victim, reputation, victimIsAI);
            return;
        }

        // Check if PVE Kill Penalty is enabled
        if (!zoneManager.IsPVEKillPenaltyEnabled())
        {
            // PVE penalty disabled - use normal Expansion behavior everywhere
            super.HandlePlayerKilledPlayer(killer, victim, reputation, victimIsAI);
            return;
        }

        // Get positions
        vector killerPos = killer.GetPosition();
        vector victimPos = victim.GetPosition();

        // Check if kill happened inside any active PVP zone
        bool killerInPVP = zoneManager.IsPositionInAnyActivePVPZone(killerPos);
        bool victimInPVP = zoneManager.IsPositionInAnyActivePVPZone(victimPos);

        // If BOTH are in PVP zone - normal Expansion behavior (rep gain)
        if (killerInPVP && victimInPVP)
        {
            Print("[VoidlinePVP] Hardline: PVP Kill - using normal Expansion rep (+rep)");
            super.HandlePlayerKilledPlayer(killer, victim, reputation, victimIsAI);
            return;
        }

        // Kill happened outside PVP zone - DO NOT call super (no Expansion rep gain)
        // Apply ONLY our penalty!
        int penaltyAmount = zoneManager.GetPVEKillPenaltyAmount();

        string victimType = "Player";
        if (victimIsAI)
        {
            victimType = "AI/Bot";
        }

        Print("[VoidlinePVP] Hardline: PVE Kill detected (" + victimType + ")!");
        Print("[VoidlinePVP] Hardline: Killer in PVP: " + killerInPVP + ", Victim in PVP: " + victimInPVP);
        Print("[VoidlinePVP] Hardline: Applying ONLY penalty: -" + penaltyAmount + " reputation (NO Expansion rep gain!)");

        // Apply ONLY the penalty - no Expansion rep gain
        killer.Expansion_DecreaseReputation(penaltyAmount);

        // Notify via mission event (optional - for other mods to hook into)
        MissionBaseWorld missionWorld = MissionBaseWorld.Cast(GetGame().GetMission());
        if (missionWorld)
        {
            missionWorld.Expansion_OnPlayerKilledPlayer(killer, victim, -penaltyAmount, victimIsAI);
        }
    }
}
