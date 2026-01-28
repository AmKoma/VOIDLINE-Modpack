modded class DayZPlayerImplement extends DayZPlayer
{
	void OnMovementChanged()
	{
		
	}
	
	void OnSprintStart()
	{
		
	}
	
	void OnSprintEnd()
	{
		
	}	

	override void HandleView()
	{
		
		super.HandleView();
		
		HumanInputController hic = GetInputController();
		
		if ( !m_MovementState.IsRaised() && hic.IsZoomToggle() )        
		{
			m_CameraEyeZoomLevel = ECameraZoomType.NORMAL;
		}
	}

}	