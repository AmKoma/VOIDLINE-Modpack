/**
 * VoidlineEAIPVPZoneOverride
 *
 * Overrides eAI behavior to prevent AI from attacking players
 * when both the AI and player are OUTSIDE of any active PVP zone.
 *
 * Inside PVP zones: Normal eAI faction behavior applies
 * Outside PVP zones: AI treats all players as friendly (no attacks)
 */
modded class eAIBase
{
    /**
     * Override PlayerIsEnemy to check PVP zone status
     * If both AI and player are outside any PVP zone, player is NOT an enemy
     */
    override bool PlayerIsEnemy(EntityAI other, bool track = false, out bool isPlayerMoving = false, out bool friendly = false, out bool targeted = false)
    {
        // Only apply PVP zone logic on server
        if (GetGame().IsServer())
        {
            PlayerBase player;
            if (Class.CastTo(player, other))
            {
                // Get AI position
                vector aiPosition = GetPosition();
                // Get player position
                vector playerPosition = player.GetPosition();

                // Check if AI is outside PVP zone
                bool aiInPVP = VoidlinePVPZoneManager.GetInstance().IsPositionInAnyActivePVPZone(aiPosition);
                // Check if player is outside PVP zone
                bool playerInPVP = VoidlinePVPZoneManager.GetInstance().IsPositionInAnyActivePVPZone(playerPosition);

                // If BOTH are outside PVP zones, treat player as friendly (not an enemy)
                if (!aiInPVP && !playerInPVP)
                {
                    friendly = true;

                    // Check if player is moving for tracking purposes
                    if (player.Expansion_GetActualVelocity().LengthSq() > 0 || player.IsClimbing() || player.IsFalling() || player.IsFighting() || player.IsLeaning())
                        isPlayerMoving = true;

                    #ifdef VOIDLINE_PVP_DEBUG
                    Print("[VoidlinePVP] eAI Override: AI at " + aiPosition.ToString() + " treats player at " + playerPosition.ToString() + " as FRIENDLY (both outside PVP zone)");
                    #endif

                    return false; // NOT an enemy
                }

                #ifdef VOIDLINE_PVP_DEBUG
                if (aiInPVP || playerInPVP)
                {
                    Print("[VoidlinePVP] eAI Override: AI in PVP=" + aiInPVP + ", Player in PVP=" + playerInPVP + " - using normal faction behavior");
                }
                #endif
            }
        }

        // Default: Use standard eAI faction behavior
        return super.PlayerIsEnemy(other, track, isPlayerMoving, friendly, targeted);
    }
}
