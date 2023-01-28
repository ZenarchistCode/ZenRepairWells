modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		GetZenWellsConfig();
		Print("[ZenRepairWells] OnInit - Loaded config successfully.");
	}

	// Called when the server shuts down - seems to work fine for our purposes.
	void ~MissionServer()
	{
		// Only save well config on server shutdown to avoid potential lag if the file gets large
		GetZenWellsConfig().Save();
	}
}