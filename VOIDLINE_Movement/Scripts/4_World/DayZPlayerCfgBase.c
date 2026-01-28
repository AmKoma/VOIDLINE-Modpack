modded class DayZPlayerTypeUtils
{
	override static void DayZPlayerTypeCreate(DayZPlayerType pType)
	{
		DayZPlayerTypeRegisterItems(pType);
		DayZPlayerTypeRegisterSounds(pType);
		DayZPlayerCameras.RegisterCameras(pType);

		pType.SetLookLimits(-85, 85, -160, 160);
		pType.SetAimLimits(-85, 85, -180, 180);
		pType.SetCameraShootParams(250, 0.01, 0.866);
		pType.RegisterHitComponentsForAI();
	}

	override static void DayZPlayerTypeInitMovement(DayZPlayerType pType)
	{
		SHumanCommandMoveSettings hmcs = pType.CommandMoveSettingsW();

		// Sprint etwas entschärft
		hmcs.m_fRunSpringTimeout          = 0.15;   // 0.08 -> 0.15
		hmcs.m_fRunSpringMaxChange        = 6.0;    // 8.0 -> 6.0

		// Strafe/Direction minimal langsamer
		hmcs.m_fDirFilterTimeout          = 0.05;   // 0.03 -> 0.05
		hmcs.m_fDirFilterSprintTimeout    = 0.04;   // 0.02 -> 0.04
		hmcs.m_fDirFilterSpeed            = Math.DEG2RAD * 600; // 720 -> 600

		// Sprint turns
		hmcs.m_fMaxSprintAngle            = Math.DEG2RAD * 70;  // 70 -> 65

		// Turn etwas weicher
		hmcs.m_fTurnAngle                 = 55;     // 55 -> 50
		hmcs.m_fTurnEndUpdateNTime        = 0.18;   // 0.18 -> 0.25
		hmcs.m_fTurnNextNTime             = 0.22;   // 0.22 -> 0.30

		// Heading-Change-Limiter sehr hoch lassen (quasi kein Cap)
		hmcs.m_fHeadingChangeLimiterIdle  = 1e7;
		hmcs.m_fHeadingChangeLimiterWalk  = 1e7;
		hmcs.m_fHeadingChangeLimiterRun   = 1e7;

		// Lean etwas gedrosselt
		hmcs.m_fLeaningSpeed              = 7.0;    // 8.0 -> 7.0

		// Wasser-Penalties etwas härter
		hmcs.m_fWaterLevelSpeedRectrictionLow  = 0.40; // 0.35 -> 0.40
		hmcs.m_fWaterLevelSpeedRectrictionHigh = 0.85; // 0.75 -> 0.85

		// Water-Level max-speed gates
		hmcs.m_iMaxSpeedNormal_WaterLevelLow   = -1;
		hmcs.m_iMaxSpeedFast_WaterLevelLow     = -1;
		hmcs.m_iMaxSpeedNormal_WaterLevelHigh  = 2;
		hmcs.m_iMaxSpeedFast_WaterLevelHigh    = 3;

		SHumanCommandClimbSettings hcls = pType.CommandClimbSettingsW();
	};
}

modded class DayzPlayerItemBehaviorCfg
{
	void DayzPlayerItemBehaviorCfg()
	{
		// etwas smoother, aber nicht mehr „overclocked“
		m_fMoveHeadingFilterSpeed = Math.DEG2RAD * 600; // 720 -> 600
	};
}
