modded class Wrench extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRepairWell);
	}
}