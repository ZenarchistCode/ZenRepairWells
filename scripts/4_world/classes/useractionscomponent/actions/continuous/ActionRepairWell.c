class ActionRepairWellCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent = 18;
		if (m_ActionData.m_MainItem.GetType() == "PipeWrench")
			time_spent = 10;

		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

class ActionRepairWell : ActionContinuousBase
{
	void ActionRepairWell()
	{
		m_CallbackClass = ActionRepairWellCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.SMALL);
	}

	override string GetText()
	{
		return "#repair";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Well well = Well.Cast(target.GetObject());

		if (!well)
			return false;

		// Server checks
		if (GetGame().IsDedicatedServer() && well.IsRepaired())
		{
			// Send a message to the client that the well is already repaired
			player.ZenWell_SendMsg(GetZenWellsConfig().MessageRepaired);
			return false;
		}

		return !well.IsRepaired();
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		PlayerBase player = action_data.m_Player;

		Well well = Well.Cast(action_data.m_Target.GetObject());

		if (!well)
			return;

		well.SetRepaired(true);

		int wellIndex = GetZenWellsConfig().GetRepairableWellIndex(well.GetPosition());
		GetZenWellsConfig().SetWellRepaired(wellIndex, well.GetPosition(), true, true); // If index == -1 then a new well will be saved.
		action_data.m_MainItem.DecreaseHealth("", "", GetZenWellsConfig().DamageTool);
	}
};