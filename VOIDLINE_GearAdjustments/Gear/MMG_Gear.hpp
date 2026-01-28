// ############# Helmets

// Tactical Helmet
class tactical_helmet_base : Mich2001Helmet
{
    class Protection
    {
        melee = 0.5;
        firearm = 0.25;
    };

    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints = 80;
                healthLevels[] = {{1.0, {"JPC_Vest\data\helmet\tactical_helmet\tactical_helmet.rvmat"}}, {0.7, {"JPC_Vest\data\helmet\tactical_helmet\tactical_helmet.rvmat"}}, {0.5, {"JPC_Vest\data\helmet\tactical_helmet\tactical_helmet_damaged.rvmat"}}, {0.3, {"JPC_Vest\data\helmet\tactical_helmet\tactical_helmet_damaged.rvmat"}}, {0.0, {"JPC_Vest\data\helmet\tactical_helmet\tactical_helmet_destruct.rvmat"}}};
            };
        };
        class GlobalArmor
        {
            class Projectile
            {
                class Health
                {
                    damage = 0.35;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.35;
                };
            };
            class Melee
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class Infected
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class FragGrenade
            {
                class Health
                {
                    damage = 0.5;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.26;
                };
            };
        };
    };
}

class mmg_armored_helmet_visor_down : Clothing
{
    class Protection
    {
        melee = 0.5;
        firearm = 0.35;
    };
}

// Amored Helmet
class mmg_armored_helmet_base : Mich2001Helmet
{
    class Protection
    {
        melee = 0.8;
        firearm = 0.55;
    };

    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints = 200;
                healthLevels[] = {{1.0, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet.rvmat"}}, {0.5, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet.rvmat"}}, {0.3, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet_damaged.rvmat"}}, {0.2, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet_damaged.rvmat"}}, {0.0, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet_destruct.rvmat"}}};
            };
        };
        class GlobalArmor
        {
            class Projectile
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class Melee
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0.0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class Infected
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0.0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class FragGrenade
            {
                class Health
                {
                    damage = 0.5;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.26;
                };
            };
        };
    };
};

// Tactical Helmet
class striker_helmet_base : Mich2001Helmet
{
    class Protection
    {
        melee = 0.75;
        firearm = 0.45;
    };

    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints = 200;
                healthLevels[] = {{1.0, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet.rvmat"}}, {0.5, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet.rvmat"}}, {0.3, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet_damaged.rvmat"}}, {0.2, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet_damaged.rvmat"}}, {0.0, {"JPC_Vest\data\helmet\striker_helmet\striker_helmet_destruct.rvmat"}}};
            };
        };
        class GlobalArmor
        {
            class Projectile
            {
                class Health
                {
                    damage = 0.15;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.15;
                };
            };
            class Melee
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0.0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class Infected
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0.0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class FragGrenade
            {
                class Health
                {
                    damage = 0.5;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.26;
                };
            };
        };
    };
};

// ############# Vests

// JPC-Vest
class JPC_Vest_Base : Clothing
{
    class Protection
    {
        melee = 0.8;
        firearm = 0.45;
    };
};

// TT-Vest
class tt_vest_Base : Clothing
{
    class Protection
    {
        melee = 0.85;
        firearm = 0.55;
    };

    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints = 250;
                transferToAttachmentsCoef = 0.5;
                healthLevels[] = {{1.0, {"JPC_Vest\data\Vest\tt_vest\tt_vest.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest.rvmat"}}, {0.7, {"JPC_Vest\data\Vest\tt_vest\tt_vest.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest.rvmat"}}, {0.5, {"JPC_Vest\data\Vest\tt_vest\tt_vest_damaged.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest_damaged.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest_damaged.rvmat"}}, {0.3, {"JPC_Vest\data\Vest\tt_vest\tt_vest_damaged.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest_damaged.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest_damaged.rvmat"}}, {0.0, {"JPC_Vest\data\Vest\tt_vest\tt_vest_destruct.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest_destruct.rvmat", "JPC_Vest\data\Vest\tt_vest\tt_vest_destruct.rvmat"}}};
            };
        };
        class GlobalArmor
        {
            class Projectile
            {
                class Health
                {
                    damage = 0.35;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.35;
                };
            };
            class Melee
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0.0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class Infected
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0.0;
                };
                class Shock
                {
                    damage = 0.25;
                };
            };
            class FragGrenade
            {
                class Health
                {
                    damage = 0.5;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.26;
                };
            };
        };
    };
};

// MK-III Vest
class heavyvest_base : Clothing
{
    class Protection
    {
        melee = 0.9;
        firearm = 0.60;
    };

    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints = 350;
                healthLevels[] = {{1.0, {"JPC_Vest\data\Vest\heavyvest\heavyvest.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest.rvmat"}}, {0.7, {"JPC_Vest\data\Vest\heavyvest\heavyvest.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest.rvmat"}}, {0.5, {"JPC_Vest\data\Vest\heavyvest\heavyvest_damaged.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest_damaged.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest_damaged.rvmat"}}, {0.3, {"JPC_Vest\data\Vest\heavyvest\heavyvest_damaged.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest_damaged.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest_damaged.rvmat"}}, {0.0, {"JPC_Vest\data\Vest\heavyvest\heavyvest_destruct.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest_destruct.rvmat", "JPC_Vest\data\Vest\heavyvest\heavyvest_destruct.rvmat"}}};
            };
        };
        class GlobalArmor
        {
            class Projectile
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.15;
                };
            };
            class Melee
            {
                class Health
                {
                    damage = 0.15;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.15;
                };
            };
            class Infected
            {
                class Health
                {
                    damage = 0.15;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.15;
                };
            };
            class FragGrenade
            {
                class Health
                {
                    damage = 0.25;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.15;
                };
            };
        };
    };
};

/// MK-V Vest
class mk5_vest_base : Clothing
{
    class Protection
    {
        melee = 1.0;
        firearm = 0.80;
    };

    class DamageSystem
    {
        class GlobalHealth
        {
            class Health
            {
                hitpoints = 650;
                healthLevels[] = {{1.0, {"JPC_Vest\data\Vest\mk5_vest\ratnik.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik.rvmat"}}, {0.7, {"JPC_Vest\data\Vest\mk5_vest\ratnik.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik.rvmat"}}, {0.5, {"JPC_Vest\data\Vest\mk5_vest\ratnik_damaged.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik_damaged.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik_damaged.rvmat"}}, {0.3, {"JPC_Vest\data\Vest\mk5_vest\ratnik_damaged.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik_damaged.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik_damaged.rvmat"}}, {0.0, {"JPC_Vest\data\Vest\mk5_vest\ratnik_destruct.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik_destruct.rvmat", "JPC_Vest\data\Vest\mk5_vest\ratnik_destruct.rvmat"}}};
            };
        };
        class GlobalArmor
        {
            class Projectile
            {
                class Health
                {
                    damage = 0.10;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.05;
                };
            };
            class Melee
            {
                class Health
                {
                    damage = 0.05;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.05;
                };
            };
            class Infected
            {
                class Health
                {
                    damage = 0.05;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.05;
                };
            };
            class FragGrenade
            {
                class Health
                {
                    damage = 0.2;
                };
                class Blood
                {
                    damage = 0;
                };
                class Shock
                {
                    damage = 0.1;
                };
            };
        };
    };
};