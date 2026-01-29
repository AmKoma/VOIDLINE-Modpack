modded class RecoilBase
{
	override void PostInit(Weapon_Base weapon)
	{
		super.PostInit(weapon);

		if (m_Player && m_Player.GetTerjeSkills())
		{
			// RecoilControl perk - reduces recoil modifier
			float recoilPerkValue;
			if (m_Player.GetTerjeSkills().GetPerkValue("gnsmth", "rclctrl", recoilPerkValue))
			{
				float recoilMod = Math.Clamp(1.0 + recoilPerkValue, 0.1, 1.0);
				m_RecoilModifier[0] = m_RecoilModifier[0] * recoilMod;
				m_RecoilModifier[1] = m_RecoilModifier[1] * recoilMod;
				m_RecoilModifier[2] = m_RecoilModifier[2] * recoilMod;
			}

			// SteadyAim perk - reduces mouse offset distance (less visual kick)
			float steadyPerkValue;
			if (m_Player.GetTerjeSkills().GetPerkValue("gnsmth", "steadyaim", steadyPerkValue))
			{
				float steadyMod = Math.Clamp(1.0 + steadyPerkValue, 0.1, 1.0);
				m_MouseOffsetDistance = m_MouseOffsetDistance * steadyMod;
				m_CamOffsetDistance = m_CamOffsetDistance * steadyMod;

				// Recalculate mouse offset target with reduced distance
				m_MouseOffsetTarget = vector.YawToVector(m_Angle);
				m_MouseOffsetTarget = m_MouseOffsetTarget * m_MouseOffsetDistance;
			}

			// WeaponMastery unlock perk - additional flat recoil and sway reduction
			if (m_Player.GetTerjeSkills().GetPerkLevel("gnsmth", "wpnmstr") > 0)
			{
				m_RecoilModifier[0] = m_RecoilModifier[0] * 0.85;
				m_RecoilModifier[1] = m_RecoilModifier[1] * 0.85;
				m_MouseOffsetDistance = m_MouseOffsetDistance * 0.85;

				m_MouseOffsetTarget = vector.YawToVector(m_Angle);
				m_MouseOffsetTarget = m_MouseOffsetTarget * m_MouseOffsetDistance;
			}

			// Passive skill modifier - small recoil reduction per level
			float skillModValue;
			if (m_Player.GetTerjeSkills().GetSkillModifierValue("gnsmth", "wpndegmod", skillModValue))
			{
				float passiveMod = Math.Clamp(1.0 + (skillModValue * 0.5), 0.5, 1.0);
				m_RecoilModifier[0] = m_RecoilModifier[0] * passiveMod;
				m_RecoilModifier[1] = m_RecoilModifier[1] * passiveMod;
			}
		}
	}
}
