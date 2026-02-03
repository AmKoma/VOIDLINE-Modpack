class mmg_military_case_base extends mmg_storage_openable_noLock_base
{
    override bool CanPutIntoHands(EntityAI parent)
    {
        return true;
    }
}