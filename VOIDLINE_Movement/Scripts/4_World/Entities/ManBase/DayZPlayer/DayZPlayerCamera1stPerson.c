modded class DayZPlayerCamera1stPerson extends DayZPlayerCameraBase
{
	static const float CONST_UD_MIN = -85.0;
	static const float CONST_UD_MAX =  85.0;

	static const float CONST_LR_MIN = -160.0;
	static const float CONST_LR_MAX =  160.0;

	// ---- Tunables ----
	protected float m_FovScale   = 1.18; // >1.0 = breiter als Vanilla; Zoom bleibt intakt
	protected float m_ShakeMult  = 1.60; // 1.0 = Vanilla; 1.3–2.0 = stärker

	// ---- Runtime ----
	protected int    m_iBoneIndex;
	protected vector m_OffsetLS;

	protected float  m_fUpDownAngle;
	protected float  m_fUpDownAngleAdd;
	protected float  m_fLeftRightAngle;
	protected float  m_fLeftRightAngleAdd;

	void DayZPlayerCamera1stPerson(DayZPlayer pPlayer, HumanInputController pInput)
	{
		m_iBoneIndex = pPlayer.GetBoneIndexByName("Head");
		if (m_iBoneIndex == -1)
		{
			Print("DayZPlayerCamera1stPerson: main bone not found");
		}
		// x = right, y = up, z = forward (local space)
		m_OffsetLS = "0.04 0.04 0";
	}

	override void OnActivate(DayZPlayerCamera pPrevCamera, DayZPlayerCameraResult pPrevCameraResult)
	{
		super.OnActivate(pPrevCamera, pPrevCameraResult);

		if (pPrevCamera)
		{
			vector baseAngles = pPrevCamera.GetBaseAngles();
			m_fUpDownAngle    = baseAngles[0];
			m_fLeftRightAngle = baseAngles[1];

			vector addAngles  = pPrevCamera.GetAdditiveAngles();
			m_fUpDownAngleAdd    = addAngles[0];
			m_fLeftRightAngleAdd = addAngles[1];
		}
	}

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		// Eingaben verarbeiten
		m_CurrentCameraYaw   = UpdateLRAngleUnlocked(m_fLeftRightAngle,  m_fLeftRightAngleAdd, CONST_LR_MIN, CONST_LR_MAX, pDt);
		m_CurrentCameraPitch = UpdateUDAngleUnlocked(m_fUpDownAngle,     m_fUpDownAngleAdd,    CONST_UD_MIN, CONST_UD_MAX, pDt);

		// Transform aufbauen
		Math3D.YawPitchRollMatrix(GetCurrentOrientation(), pOutResult.m_CameraTM);
		pOutResult.m_CameraTM[3]     = m_OffsetLS;

		// Kamera-Flags
		pOutResult.m_iDirectBone     = m_iBoneIndex;
		pOutResult.m_iDirectBoneMode = 1;
		pOutResult.m_fUseHeading     = 1.0;
		pOutResult.m_fInsideCamera   = 1.0;
		pOutResult.m_fNearPlane      = 0.04;

		// ---- Shake: in/out-sicher verstärken ----
		float lr_before = m_fLeftRightAngle;
		float ud_before = m_fUpDownAngleAdd;
		float lr = lr_before;   // Kopien!
		float ud = ud_before;

		ProcessCameraShake(pDt, lr, ud);   // KEINE berechneten Ausdrücke übergeben

		m_fLeftRightAngle = lr_before + (lr - lr_before) * m_ShakeMult;
		m_fUpDownAngleAdd = ud_before + (ud - ud_before) * m_ShakeMult;
		// -----------------------------------------

		InitCameraOnPlayer();

		// ---- Zoom & FOV:
		// 1) Engine-Logik (Zoom, User-Settings etc.)
		StdFovUpdate(pDt, pOutResult);

		// 2) Danach breiter machen, ohne Zoom zu killen
		//    (Multiplier multipliziert den von StdFovUpdate berechneten Wert)
		pOutResult.m_fFovMultiplier = pOutResult.m_fFovMultiplier * m_FovScale;

		UpdateCameraNV(PlayerBase.Cast(m_pPlayer));
	}

	override vector GetBaseAngles()
	{
		vector a; a[0] = m_fUpDownAngle; a[1] = m_fLeftRightAngle; a[2] = 0; return a;
	}

	override vector GetAdditiveAngles()
	{
		vector a; a[0] = m_fUpDownAngleAdd; a[1] = m_fLeftRightAngleAdd; a[2] = 0; return a;
	}

	override string GetCameraName()
	{
		return "DayZPlayerCamera1stPerson";
	}
}
