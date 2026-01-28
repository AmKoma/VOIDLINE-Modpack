class INK_CamoNetPoncho_Base extends Clothing
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionWringClothes);
	}
};	

class INK_CamoNetPoncho extends INK_CamoNetPoncho_Base {};
class Black_CamoNetPoncho extends INK_CamoNetPoncho_Base {};
class White_CamoNetPoncho extends INK_CamoNetPoncho_Base {};
class Brown_CamoNetPoncho extends INK_CamoNetPoncho_Base {};