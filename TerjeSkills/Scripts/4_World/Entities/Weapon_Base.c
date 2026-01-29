modded class Weapon_Base
{
	// Gunsmith skill - stored health values for degradation tracking between shots
	// C++ engine applies damage BEFORE EEFired, so we compare against last shot's health
	protected float m_TerjeWpnLastHealth = -1;
	protected float m_TerjeSuppLastHealth = -1;

	// Gunsmith skill - XP gain on shooting + weapon/suppressor degradation reduction
	override void EEFired(int muzzleType, int mode, string ammoType)
	{
		float wpnHealthNow;
		float suppHealthNow;
		float wpnLost;
		float supLost;
		float shootGainChance;
		int shootGainExp;
		float wpnMaintPerkValue;
		float healthRestore;
		float skillModValue;
		float passiveRestore;
		float supCarePerkValue;
		float supRestore;
		ItemBase suppressor;
		PlayerBase player;

		// Read current health (C++ damage already applied at this point)
		wpnHealthNow = GetHealth("", "Health");
		suppHealthNow = 0;
		suppressor = ItemBase.Cast(GetAttachedSuppressor());
		if (suppressor)
		{
			suppHealthNow = suppressor.GetHealth("", "Health");
		}

		super.EEFired(muzzleType, mode, ammoType);

		if (GetGame() && GetGame().IsDedicatedServer())
		{
			player = PlayerBase.Cast(GetHierarchyRootPlayer());
			if (player && player.GetTerjeSkills())
			{
				// Gain gunsmith XP on shooting (chance-based)
				if (GetTerjeSettingFloat(TerjeSettingsCollection.SKILLS_GUNSMITH_SHOOT_GAIN_CHANCE, shootGainChance) && Math.RandomFloat01() < shootGainChance)
				{
					if (GetTerjeSettingInt(TerjeSettingsCollection.SKILLS_GUNSMITH_SHOOT_GAIN_EXP, shootGainExp))
					{
						player.GetTerjeSkills().AddSkillExperience("gnsmth", shootGainExp);
					}
				}

				// WeaponMaintenance perk - reduce weapon degradation from firing
				// Compare against health stored after PREVIOUS shot to capture C++ damage
				if (m_TerjeWpnLastHealth > 0)
				{
					wpnLost = m_TerjeWpnLastHealth - wpnHealthNow;
					if (wpnLost > 0)
					{
						if (player.GetTerjeSkills().GetPerkValue("gnsmth", "wpnmaint", wpnMaintPerkValue))
						{
							healthRestore = wpnLost * Math.Clamp(Math.AbsFloat(wpnMaintPerkValue), 0, 1);
							AddHealth("", "Health", healthRestore);
						}

						// Passive skill modifier - small degradation reduction per level
						if (player.GetTerjeSkills().GetSkillModifierValue("gnsmth", "wpndegmod", skillModValue))
						{
							passiveRestore = wpnLost * Math.Clamp(Math.AbsFloat(skillModValue), 0, 1);
							AddHealth("", "Health", passiveRestore);
						}
					}
				}

				// SuppressorCare perk - reduce suppressor degradation from firing
				if (suppressor && m_TerjeSuppLastHealth > 0)
				{
					supLost = m_TerjeSuppLastHealth - suppHealthNow;
					if (supLost > 0)
					{
						if (player.GetTerjeSkills().GetPerkValue("gnsmth", "supcare", supCarePerkValue))
						{
							supRestore = supLost * Math.Clamp(Math.AbsFloat(supCarePerkValue), 0, 1);
							suppressor.AddHealth("", "Health", supRestore);
						}
					}
				}
			}
		}

		// Store health AFTER restoration for next shot comparison
		m_TerjeWpnLastHealth = GetHealth("", "Health");
		if (suppressor)
		{
			m_TerjeSuppLastHealth = suppressor.GetHealth("", "Health");
		}
		else
		{
			m_TerjeSuppLastHealth = -1;
		}
	}

	// Gunsmith skill - JamResistance perk
	// Runs on BOTH client and server to prevent desync
	// Client: always prevents jam when perk active (server state is authoritative)
	// Server: probabilistic prevention based on perk value
	override bool JamCheck(int muzzleIndex)
	{
		bool shouldJam;
		PlayerBase player;
		float jamResPerkValue;

		shouldJam = super.JamCheck(muzzleIndex);

		if (shouldJam)
		{
			player = PlayerBase.Cast(GetHierarchyRootPlayer());
			if (player && player.GetTerjeSkills())
			{
				if (player.GetTerjeSkills().GetPerkValue("gnsmth", "jamres", jamResPerkValue))
				{
					if (GetGame().IsDedicatedServer())
					{
						// Server: probabilistic jam prevention
						if (Math.RandomFloat01() < Math.AbsFloat(jamResPerkValue))
						{
							return false;
						}
					}
					else
					{
						// Client: always prevent to avoid desync
						// Server is authoritative and will sync actual jam state
						return false;
					}
				}
			}
		}

		return shouldJam;
	}

	// Gunsmith skill - ReliableWeapons perk (reduce weapon damage from all sources)
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		float relWpnPerkValue;
		float actualHP;
		float addHealth;
		PlayerBase ownerPlayer;

		if (GetGame() && GetGame().IsDedicatedServer() && IsWeapon())
		{
			ownerPlayer = PlayerBase.Cast(GetHierarchyRootPlayer());
			if (ownerPlayer && ownerPlayer.IsAlive() && ownerPlayer.GetTerjeSkills() != null)
			{
				if (ownerPlayer.GetTerjeSkills().GetPerkValue("gnsmth", "relwpn", relWpnPerkValue))
				{
					actualHP = GetHealth("", "Health");
					if (actualHP > 0 && damageResult != null)
					{
						addHealth = damageResult.GetDamage("", "Health") * Math.Clamp(Math.AbsFloat(relWpnPerkValue), 0, 1);
						if (addHealth > 0)
						{
							AddHealth("", "Health", addHealth);
						}
					}
				}
			}
		}

		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}
}
