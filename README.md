# VOIDLINE Modpack

Server-side modpack for DayZ, developed by **KOMA**.

## Modules

### VOIDLINE_Clothes
Custom clothing and equipment items.
- **CamoNet Poncho** -- craftable ghillie-style poncho in 4 variants (default, black, white, brown)
- **RifleBag** -- rifle carrying bag in multiple camo patterns (black, desert, green, tan, winter)

### VOIDLINE_GearAdjustments
Rebalanced protection and damage values for third-party gear (MMG / JPC_Vest).
- Tactical, armored and striker helmets with custom ballistic/melee/frag armor values
- JPC, TT, MK-III and MK-V vests with tiered protection scaling
- Windstride gear adjustments

### VOIDLINE_Movement
Custom player movement and camera tuning.
- Adjusted sprint acceleration and max speed
- Refined strafe and direction filtering
- Tuned camera shake on firing
- Modified look/aim limits

### VOIDLINE_PVP_Zones
Dynamic PVP zone system with full server/client synchronization.
- Multiple zone types: manual, territory-based and time-scheduled
- JSON-configurable zone definitions with radius, position and schedule
- Expansion map marker integration with color-coded zone display
- eAI and Hardline compatibility
- RPC-based client sync with zone entry/exit notifications

### VOIDLINE_RevGuns
Custom weapon configurations and content for the RevGuns mod.
- Retextured and rebalanced weapons: CDX50, M110, HK417, HT76, M200
- Custom firing and handling sounds per weapon
- eAI weapon restriction -- prevents players from picking up AI-exclusive weapon variants

### VOIDLINE_Stringtables
Shared localization strings used across VOIDLINE modules.

## Dependencies

| Dependency | Required by |
|---|---|
| DayZ (vanilla) | All modules |
| [RevGuns](https://steamcommunity.com/sharedfiles/filedetails/?id=2903620683) | Movement, RevGuns |
| [JPC Vest](https://steamcommunity.com/workshop/filedetails/?id=2804741135) | GearAdjustments |
| [TerjeMods](https://steamcommunity.com/sharedfiles/filedetails/?id=2718848543) | Movement |
| [DayZ Expansion](https://steamcommunity.com/sharedfiles/filedetails/?id=2572331007) | PVP_Zones (AI + Hardline) |

## Installation

1. Pack each `VOIDLINE_*` folder as a PBO using DayZ Tools or a third-party PBO packer
2. Place the resulting PBOs into your server's mod directory
3. Add the mod to your server startup parameters
4. Configure `VOIDLINE_PVP_Zones` via `$profile:VoidlinePVP/zones.json`

## License

This project is licensed under a **custom attribution license**. You are free to use, modify and redistribute this modpack **as long as proper credit is given** to the original author (KOMA / VOIDLINE).

See [LICENSE](LICENSE) for full terms.

## Credits

- **KOMA** -- Author
- **Terje** -- Author [TerjeMods](https://github.com/TerjeBruoygard)
- **ReDos** -- Contributions (Clothes, GearAdjustments, Stringtables)
