// =====================================================================================
// Modernized 3rd-Person Camera (Patch Only: replaces stock camera classes)
// Place in: YourMod/scripts/4_World/modern_camera_patch.c
// Notes:
// - Keine Ternaries. Verwendet m_pInput.IsRaised() (nicht DayZPlayer.IsRaised()).
// - Etwas weiter weg als Vanilla; Distanz/Schulter/Höhe werden dynamisch & smooth angepasst.
// - Kein FP->TP "Push-Out"; Shoulder-Switch smooth; leichter Sprint-Roll.
// =====================================================================================

// ============================================================================
// 3rd person base (patched)
// ============================================================================
modded class DayZPlayerCamera3rdPerson
{
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		// --- Eingabe / State wie im Original ---
		m_pPlayer.GetMovementState(m_MovementState);

		// Winkel-Update (entspricht Original-Grenzen)
		m_CurrentCameraYaw = UpdateLRAngleUnlocked(m_fLeftRightAngle, m_fLeftRightAngleAdd, CONST_LR_MIN, CONST_LR_MAX, pDt);
		m_CurrentCameraPitch = UpdateUDAngleUnlocked(m_fUpDownAngle, m_fUpDownAngleAdd, CONST_UD_MIN, CONST_UD_MAX, pDt);

		ProcessCameraShake(pDt, m_fLeftRightAngle, m_fUpDownAngleAdd);

		// Schulter-Seite glatt (wie Original)
		if (m_pInput.Camera3rdIsRightShoulder())
		{
			m_fCameraLRShoulder = Math.SmoothCD(m_fCameraLRShoulder, 1.0, m_fCameraLRShoulderVel, 0.14, 1000, pDt);
		}
		else
		{
			m_fCameraLRShoulder = Math.SmoothCD(m_fCameraLRShoulder, -1.0, m_fCameraLRShoulderVel, 0.14, 1000, pDt);
		}

		float shoulderDist = m_fCameraLRShoulder * m_fShoulderWidth + m_MovementState.m_fLeaning * m_fLeanDistance;

		// Orientierungs-Matrix
		Math3D.YawPitchRollMatrix(GetCurrentOrientation(), pOutResult.m_CameraTM);

		// Basis-Bone-Position
		if (m_iBoneIndex != -1)
		{
			pOutResult.m_CameraTM[3] = m_pPlayer.GetBonePositionMS(m_iBoneIndex);
		}
		else
		{
			pOutResult.m_CameraTM[3] = "0 0 0";
		}

		// Offsets vorbereiten (Schulter in LS/MS addieren)
		vector msOffset = m_CameraOffsetMS;
		vector lsOffset = m_CameraOffsetLS;

		if (m_bShoulderInLS)
		{
			lsOffset[0] = lsOffset[0] + shoulderDist;
		}
		else
		{
			msOffset[0] = msOffset[0] + shoulderDist;
		}

		// Endposition
		pOutResult.m_CameraTM[3] = pOutResult.m_CameraTM[3] + pOutResult.m_CameraTM[0] * lsOffset[0] + pOutResult.m_CameraTM[1] * lsOffset[1] + pOutResult.m_CameraTM[2] * lsOffset[2] + msOffset;

		// --- Modernisierung: globale Distanz-Anhebung + Speed-Shift ---
		// Parameter lokal, keine Ternär-Operatoren
		const float DIST_BASE_MULT = 1.15;	 // allgemein etwas weiter weg
		const float DIST_BASE_ADD = 0.35;	 // additive Basis-Erhöhung in Metern
		const float SHIFT_PER_MS = 0.06;	 // Zuwachs pro m/s
		const float SHIFT_MAX = 0.60;		 // Obergrenze des Speed-Shifts
		const float SHIFT_SMOOTH_TAU = 0.25; // Glättungszeit in Sekunden

		// Geschwindigkeit (m/s)
		vector vlin = GetVelocity(m_pPlayer);
		float speed = vlin.Length();

		// Ziel-Shift
		float targetShift = speed * SHIFT_PER_MS;
		if (targetShift > SHIFT_MAX)
		{
			targetShift = SHIFT_MAX;
		}
		if (targetShift < 0.0)
		{
			targetShift = 0.0;
		}

		// Ziel-Distanz (auf Basis der zustandsspezifischen m_fDistance)
		float targetDistance = m_fDistance * DIST_BASE_MULT + DIST_BASE_ADD + targetShift;

		// Sanfte Annäherung (Persistenz lokal statisch pro Methode)
		static float s_DynamicDistance = 0.0;
		static float s_DistVel[1];

		if (s_DynamicDistance <= 0.0)
		{
			s_DynamicDistance = targetDistance;
		}

		s_DynamicDistance = Math.SmoothCD(s_DynamicDistance, targetDistance, s_DistVel, SHIFT_SMOOTH_TAU, 1000, pDt);

		// Ausgabe-Flags
		pOutResult.m_fDistance = s_DynamicDistance;
		pOutResult.m_fUseHeading = 1.0;
		pOutResult.m_fInsideCamera = 0.0;
		pOutResult.m_fPredictCollisionRadius = m_fPredictCollisionRadius;

		// Standard-Hooks
		InitCameraOnPlayer();
		StdFovUpdate(pDt, pOutResult);
		UpdateCameraNV(PlayerBase.Cast(m_pPlayer));
	}
}

modded class DayZPlayerCamera3rdPersonProneBase
{
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		// Pitch wie Original
		m_CurrentCameraPitch = UpdateUDAngleUnlocked(m_fUpDownAngle, m_fUpDownAngleAdd, CONST_UD_MIN, CONST_UD_MAX, pDt);

		// Erste Yaw-Setzung (Orient + Head), wie Original
		float orientYaw = m_pPlayer.GetOrientation()[0];
		float headYaw = m_pInput.GetHeadingAngle() * Math.RAD2DEG;
		m_CurrentCameraYaw = -fixAngle_180_180(orientYaw + headYaw);

		ProcessCameraShake(pDt, m_fLeftRightAngle, m_fUpDownAngleAdd);

		// Schulter-Seite glatt wie Original
		if (m_pInput.Camera3rdIsRightShoulder())
		{
			m_fCameraLRShoulder = Math.SmoothCD(m_fCameraLRShoulder, 1.0, m_fCameraLRShoulderVel, 0.14, 1000, pDt);
		}
		else
		{
			m_fCameraLRShoulder = Math.SmoothCD(m_fCameraLRShoulder, -1.0, m_fCameraLRShoulderVel, 0.14, 1000, pDt);
		}

		float shoulderDist = m_fCameraLRShoulder * m_fShoulderWidth;

		// Matrix mit erster Yaw/Pitch
		Math3D.YawPitchRollMatrix(GetCurrentOrientation(), pOutResult.m_CameraTM);

		// Basis-Bone mit Glättung (wie Original)
		if (m_iBoneIndex != -1)
		{
			vector bonePos = m_pPlayer.GetBonePositionMS(m_iBoneIndex);
			m_BaseOffset[0] = Math.SmoothCD(m_BaseOffset[0], bonePos[0], m_BaseOffsetVelX, 0.14, 1000, pDt);
			m_BaseOffset[1] = Math.SmoothCD(m_BaseOffset[1], bonePos[1], m_BaseOffsetVelY, 0.14, 1000, pDt);
			m_BaseOffset[2] = Math.SmoothCD(m_BaseOffset[2], bonePos[2], m_BaseOffsetVelZ, 0.14, 1000, pDt);
		}

		// Offsets
		vector msOffset = m_CameraOffsetMS;
		vector lsOffset = m_CameraOffsetLS;
		lsOffset[0] = lsOffset[0] + shoulderDist;

		// Position aufbauen
		pOutResult.m_CameraTM[3] = m_BaseOffset + pOutResult.m_CameraTM[0] * lsOffset[0] + pOutResult.m_CameraTM[1] * lsOffset[1] + pOutResult.m_CameraTM[2] * lsOffset[2] + msOffset;

		// Zweite Yaw-Behandlung (LookAt), wie Original
		m_CurrentCameraYaw = UpdateLRAngleLookAt(-180, 180, pDt);
		Math3D.YawPitchRollMatrix(GetCurrentOrientation(), pOutResult.m_CameraTM);

		// --- Modernisierung: globale Distanz-Anhebung + Speed-Shift auch im Prone ---
		const float DIST_BASE_MULT = 1.15;
		const float DIST_BASE_ADD = 0.35;
		const float SHIFT_PER_MS = 0.06;
		const float SHIFT_MAX = 0.60;
		const float SHIFT_SMOOTH_TAU = 0.25;

		vector vlin = GetVelocity(m_pPlayer);
		float speed = vlin.Length();

		float targetShift = speed * SHIFT_PER_MS;
		if (targetShift > SHIFT_MAX)
		{
			targetShift = SHIFT_MAX;
		}
		if (targetShift < 0.0)
		{
			targetShift = 0.0;
		}

		float targetDistance = m_fDistance * DIST_BASE_MULT + DIST_BASE_ADD + targetShift;

		static float s_DynamicDistanceProne = 0.0;
		static float s_DistVelProne[1];

		if (s_DynamicDistanceProne <= 0.0)
		{
			s_DynamicDistanceProne = targetDistance;
		}

		s_DynamicDistanceProne = Math.SmoothCD(s_DynamicDistanceProne, targetDistance, s_DistVelProne, SHIFT_SMOOTH_TAU, 1000, pDt);

		// Ausgabe-Flags
		pOutResult.m_fDistance = s_DynamicDistanceProne;
		pOutResult.m_fUseHeading = 1.0;
		pOutResult.m_fInsideCamera = 0.0;
		pOutResult.m_fPositionModelSpace = 1.0;
		pOutResult.m_bUpdateWhenBlendOut = false;

		// Standard-Hooks
		InitCameraOnPlayer();
		StdFovUpdate(pDt, pOutResult);
		UpdateCameraNV(PlayerBase.Cast(m_pPlayer));
	}
}
