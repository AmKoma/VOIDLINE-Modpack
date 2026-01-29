modded class PropertyModifiers
{
	override void UpdateModifiers()
	{
		super.UpdateModifiers();

		if (m_OwnerItem)
		{
			PlayerBase player = PlayerBase.Cast(m_OwnerItem.GetHierarchyRootPlayer());
			if (player && player.GetTerjeSkills())
			{
				// SteadyAim perk - reduces weapon sway
				float steadyPerkValue;
				if (player.GetTerjeSkills().GetPerkValue("gnsmth", "steadyaim", steadyPerkValue))
				{
					float swayMod = Math.Clamp(1.0 + steadyPerkValue, 0.1, 1.0);
					m_SwayModifiers[0] = m_SwayModifiers[0] * swayMod;
					m_SwayModifiers[1] = m_SwayModifiers[1] * swayMod;
					m_SwayModifiers[2] = m_SwayModifiers[2] * swayMod;
				}

				// WeaponMastery unlock perk - additional sway reduction
				if (player.GetTerjeSkills().GetPerkLevel("gnsmth", "wpnmstr") > 0)
				{
					m_SwayModifiers[0] = m_SwayModifiers[0] * 0.85;
					m_SwayModifiers[1] = m_SwayModifiers[1] * 0.85;
					m_SwayModifiers[2] = m_SwayModifiers[2] * 0.85;
				}
			}
		}
	}
}
