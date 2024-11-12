#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

bool Inventory::HasItemWithTag(uint8_t type) const
{
        for (const auto& item : items) {
            if (item->HasTag(type)) {
                return true;
            }
        }
        return false;
}

void Inventory::RemoveItem(Item* item)
{
    items -= item;
}

void Inventory::AddItem(Item* item)
{
	items += item;
}

void Inventory::ShowInventory() const
{
	std::vector<Item*> potions;
	std::vector<Item*> weapons;
	std::vector<Item*> materials;
	std::vector<Item*> armor;
	std::vector<Item*> shield;

	for (const auto& item : items) {
		switch (item->GetType())
		{
		case ItemType::Potion:
			potions += item;
			break;
		case ItemType::Weapon:
			weapons += item;
			break;
		case ItemType::Materials:
			materials += item;
			break;
		case ItemType::Armor:
			armor += item;
			break;
		case ItemType::Shield:
			shield += item;
			break;
		default:
			break;
		}
	}

	std::cout << "|        Potions        |        Weapons        |       Materials       |        Armors        |        Shields        |"
 << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i <std::max({ potions.size(), weapons.size(), materials.size(), armor.size(), shield.size() }); i++) {
		std::cout << "|";
		if (i < potions.size()) {
			std::cout << potions[i]->GetName();
		}
		else {
			std::cout << "                       ";
		}
		std::cout << "|";
		if (i < weapons.size()) {
			std::cout << weapons[i]->GetName();
		}
		else {
			std::cout << "                       ";
		}
		std::cout << "|";
		if (i < materials.size()) {
			std::cout << materials[i]->GetName();
		}
		else {
			std::cout << "                       ";
		}
		std::cout << "|";
		if (i < armor.size()) {
			std::cout << armor[i]->GetName();
		}
		else {
			std::cout << "                      ";
		}
		std::cout << "|";
		if (i < shield.size()) {
			std::cout << shield[i]->GetName();
		}
		else {
			std::cout << "                       ";
		}
		std::cout << "|\n";
	}


	potions.clear();
	weapons.clear();
	materials.clear();
	armor.clear();
	shield.clear();
}
