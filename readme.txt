What Is This?

This mod increases the complexity of survival by adding broken water pumps to the game that require repair before you can use them.

When you install the mod and run it for the first time, a JSON config file will be generated in your server profile folder (server_root/profiles/Zenarchist/ZenRepairWells.json)

Here you can specify the message that gets sent to the player when they try to use a broken well, as well as the message that gets sent when they try to repair a well that is already repaired.

You can also turn on/off wells being broken by default. If you set "DisableWellsByDefault": 1 then all the wells on the map will be broken, and in order to use them, players must find either a small wrench or a pipe wrench and repair the well. Set this to 0 if you want to decide which wells are broken.

Once the well is repaired, it will stay functional for as long as you specify in the JSON config ("TimeToBreak": 1209600 by default, which is 2 weeks in seconds).

When a well is repaired it will be added to the list of repairable wells. This list includes the well's map position and 3 parameters: "Invincible", "Repaired", and "BreakTime". If you want certain wells to be repaired by default/always working, repair a well to have its location added to the JSON file and then you can modify its settings there.

If you set Invincible to 1 then the well is always repaired (useful if you want to enable all the northern wells on Livonia but have all the southern wells broken and require repair, for example).

When a player repairs a well, "Repaired" will be set to 1 and all players can use that well without needing to repair it until its timer runs out.

Once the UNIX timestamp "BreakTime" expires, the well will be set back to broken ("Repaired": 0) and players can no longer use the well without repairing it first.

An example JSON config is included in the mod folder.

Installation Instructions:

Install this mod like any other mod - copy it into your server folder and add it to your mods list. It must be run on both server and client. Make sure to copy the .bikey into your server keys if you're not using a server management tool like OmegaManager which does that automatically.

This mod requires Community Framework as a dependency.

Repack & Source Code:

You can repack this mod if you like, and do anything else you want with it for that matter. Just keep in mind my future updates won't be applied so make sure to check back for new versions if you notice any bugs. The source code is on my GitHub at www.zenarchist.io

Enjoy!