#include "Inventory.h"

bool Inventory::HasItemWithTag(uint8_t type) const
{
        for (const auto& item : items) {
            if (item->HasTag(type)) {
                return true;
            }
        }
        return false;
}

void Inventory::RemoveItem(std::shared_ptr<Item> item)
{
    items -= item;
}

void Inventory::AddItem(std::shared_ptr<Item> item)
{
	items += item;
}

void Inventory::ShowInventory() const
{
	std::vector<std::shared_ptr<Item>> potions;
	std::vector<std::shared_ptr<Item>> weapons;
	std::vector<std::shared_ptr<Item>> materials;
	std::vector<std::shared_ptr<Item>> armor;
	std::vector<std::shared_ptr<Item>> shield;

	for (const auto& item : items) {
		switch (item->GetType())
		{
		case 0:
			potions += item;
			break;
		case 1:
			weapons += item;
			break;
		case 2:
			materials += item;
			break;
		case 3:
			armor += item;
			break;
		case 4:
			shield += item;
			break;
		default:
			break;
		}
	}
	potions.clear();
	weapons.clear();
	materials.clear();
	armor.clear();
	shield.clear();
}
