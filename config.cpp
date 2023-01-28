// This mod is a slightly improved version of CatchRain by PoPo - all credit to him: https://steamcommunity.com/sharedfiles/filedetails/?id=2648040518

class CfgPatches
{
	class ZenRepairWells
	{
		requiredVersion = 0.1;
		units[] =
		{
			""
		};
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Books",
		};
	};
};

class CfgMods
{
	class ZenRepairWells
	{
		dir = "ZenRepairWells";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenRepairWells";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenRepairWells/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenRepairWells/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenRepairWells/scripts/5_mission" };
			};
		};
	};
};