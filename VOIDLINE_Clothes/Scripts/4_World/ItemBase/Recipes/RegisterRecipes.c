modded class PluginRecipesManagerBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		
		RegisterRecipe(new INKCraftCamoNetPoncho);		
		RegisterRecipe(new INKCraftBlackCamoNetPoncho);		
		RegisterRecipe(new INKCraftWhiteCamoNetPoncho);
		RegisterRecipe(new INKCraftBrownCamoNetPoncho);
	}
};