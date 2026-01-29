modded class CleanWeapon
{
	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		float healthBefore = 0;
		if (ingredients[1])
		{
			healthBefore = ingredients[1].GetHealth("", "Health");
		}

		super.Do(ingredients, player, results, specialty_weight);

		if (GetGame() && GetGame().IsDedicatedServer() && player && player.GetTerjeSkills() && ingredients[1])
		{
			float repairPerkValue;
			float healthAfter;
			float healthGained;
			float bonusHealth;
			float currentHealth;
			float maxHealth;
			int cleanExpGain;
			bool hasPristinePerk;

			maxHealth = ingredients[1].GetMaxHealth("", "Health");
			hasPristinePerk = player.GetTerjeSkills().GetPerkLevel("gnsmth", "prstrep") > 0;

			// ImprovedRepair perk - add bonus health after repair
			if (player.GetTerjeSkills().GetPerkValue("gnsmth", "imprep", repairPerkValue))
			{
				healthAfter = ingredients[1].GetHealth("", "Health");
				healthGained = healthAfter - healthBefore;
				if (healthGained > 0)
				{
					bonusHealth = healthGained * repairPerkValue;
					ingredients[1].AddHealth("", "Health", bonusHealth);

					// Cap below pristine if player does not have PristineRepair perk
					if (!hasPristinePerk && maxHealth > 0 && ingredients[1].GetHealth("", "Health") >= maxHealth)
					{
						ingredients[1].SetHealth("", "Health", maxHealth - 0.01);
					}
				}
			}

			// PristineRepair unlock perk - set weapon to pristine after any successful repair
			if (hasPristinePerk)
			{
				currentHealth = ingredients[1].GetHealth("", "Health");
				if (maxHealth > 0 && currentHealth > healthBefore)
				{
					ingredients[1].SetHealth("", "Health", maxHealth);
				}
			}

			// Gain gunsmith XP for cleaning/repairing weapons
			if (GetTerjeSettingInt(TerjeSettingsCollection.SKILLS_GUNSMITH_CLEAN_WEAPON_EXP_GAIN, cleanExpGain))
			{
				player.GetTerjeSkills().AddSkillExperience("gnsmth", cleanExpGain);
			}
		}
	}
}
