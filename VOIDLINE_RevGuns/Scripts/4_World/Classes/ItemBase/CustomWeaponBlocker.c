modded class Weapon_Base
{
    override bool CanPutIntoHands(EntityAI parent)
    {
        if (IsBotWeapon() && !IsAI(parent))
            return false;

        return super.CanPutIntoHands(parent);
    }

    override bool CanPutInCargo(EntityAI parent)
    {
        if (IsBotWeapon() && !IsAI(parent))
            return false;

        return super.CanPutInCargo(parent);
    }

    override bool CanDisplayAttachmentSlot(int slot_id)
    {
        if (IsBotWeapon() && !IsAI(GetHierarchyRootPlayer()))
            return false;

        return super.CanDisplayAttachmentSlot(slot_id);
    }

    override bool CanDisplayCargo()
    {
        if (IsBotWeapon() && !IsAI(GetHierarchyRootPlayer()))
            return false;

        return super.CanDisplayCargo();
    }

    bool IsBotWeapon()
    {
        string className = GetType();
        return className == "eAI_M200" || className == "eAI_M110" || className == "eAI_HK417" || className == "eAI_CDX50" || className == "eAI_HT76";
    }

    bool IsAI(EntityAI parent)
    {
        if (!parent) return false;
        Man man = Man.Cast(parent.GetHierarchyRootPlayer());
        return man && man.IsInherited(eAIBase);
    }
}
