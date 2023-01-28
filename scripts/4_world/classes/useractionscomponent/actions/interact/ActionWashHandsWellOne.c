modded class ActionWashHandsWellOne extends ActionInteractLoopBase
{
	// Called while washing hands. The reason I do it this way is so the player begins to drink and then is forced out of animation - makes it more immersive/obvious the well is broken.
	override bool CanContinue(ActionData action_data)
	{
		if (!action_data || !action_data.m_Player)
			return false;

		if (action_data.m_Player.IsPreventedWellUsage()) // player.IsPreventedWellUsage() is sync'd to client AND server, server sends an explanation - client cancels animation.
		{
			if (GetGame().IsDedicatedServer())
			{
				action_data.m_Player.ZenWell_SendMsg(GetZenWellsConfig().MessageNotDrink);
			}

			return false;
		}

		return super.CanContinue(action_data);
	}

	// Called when action begins server-side. Checks if well is disabled, if so it informs the player client to cancel action.
	override void OnStartServer(ActionData action_data)
	{
		if (!action_data || !action_data.m_Player)
			return;

		Well well = Well.Cast(action_data.m_Target.GetObject());

		if (!well) // If this is not a vanilla well, stop here. Some mods have their own "wells" that aren't Well types.
		{
			action_data.m_Player.SetPreventWellUsage(false);
			return;
		}

		if (!well.IsRepaired())
		{
			action_data.m_Player.SetPreventWellUsage(true); // Prevent player from drinking.
		}
		else
		{
			action_data.m_Player.SetPreventWellUsage(false); // Do not prevent player from drinking.
		}
	}
};