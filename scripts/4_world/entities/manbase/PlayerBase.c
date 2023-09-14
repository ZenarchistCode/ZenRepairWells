modded class PlayerBase
{
	protected bool m_PreventWellUsage = false; // If true, then the player is stopped from using wells client-side.

	override void Init()
	{
		super.Init();

		// Register variables that need to be sync'd to the client & server
		RegisterNetSyncVariableBool("m_PreventWellUsage");
	}

	// Set whether or not the player is to be prevented from using the well.
	void SetPreventWellUsage(bool stop)
	{
		m_PreventWellUsage = stop;
		SetSynchDirty();
	}

	// Returns whether or not the player is currently prevented from using the well.
	bool IsPreventedWellUsage()
	{
		return m_PreventWellUsage;
	}

	// Sends a message to the client from the server
	void ZenWell_SendMsg(string message)
	{
		if (!IsAlive() || IsPlayerDisconnected() || !GetIdentity())
			return;

		Param1<string> msgParam;
		msgParam = new Param1<string>(message);
		GetGame().RPCSingleParam(this, ERPCs.RPC_USER_ACTION_MESSAGE, msgParam, true, GetIdentity());
	}

	// Sends a delayed message to the client from the server
	void ZenWell_SendMsgDelayed(string message, float timeDelay)
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenWell_SendMsg, timeDelay, false, message);
	}
}