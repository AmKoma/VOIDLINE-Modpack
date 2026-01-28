class CfgPatches
{
    class VOIDLINE_RevGuns
    {
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Weapons_Projectiles", "RevGuns", "RevM200"};
    };
};

class CfgAmmo
{
    class Bullet_Base;
    class Bullet_408_Rev : Bullet_Base
    {
        class DamageApplied
        {
            type = "Projectile";
            dispersion = 0.0;
            bleedThreshold = 1.0;
            defaultDamageOverride[] = {{0.5, 1.0}};
            class Health
            {
                damage = 500;
            };
            class Blood
            {
                damage = 200;
            };
            class Shock
            {
                damage = 200;
            };
        };
        class NoiseHit
        {
            strength = 50;
            type = "shot";
        };
    };
};