#include "Inventory.h"

// Default constructor
Inventory::Inventory()
{
}

// Destructor
Inventory::~Inventory()
{
}

// Check if the inventory has an item with the given tag
bool Inventory::HasItemWithTag(uint8_t pType) const
{
    for (const auto& item : _items) {
        if (item->HasTag(pType)) {
            return true;
        }
    }
    return false;
}

// Remove an item from the inventory
void Inventory::RemoveItem(Item* pItem)
{
    _items -= pItem;
}

void Inventory::RemoveItem(std::string pItemName)
{
	for (const auto& item : _items) {
		if (item->GetName() == pItemName) {
			_items -= item;
			break;
		}
	}

}

// Add an item to the inventory
void Inventory::AddItem(Item* pItem)
{
    bool isAdded = false;
    for (int i = _items.size(); i > 0; i--)
    {
        if (pItem->GetType() == _items[i]->GetType())
        {
            _items.insert(_items.begin() + i + 1, pItem);
            isAdded = true;
            return;
        }
    }
    if (!isAdded)
    {
        _items += pItem;
    }
}

// Show the inventory
void Inventory::ShowInventory()
{
    // Separate vectors for different item types
    std::vector<Item*> potions;
    std::vector<Item*> weapons;
    std::vector<Item*> materials;
    std::vector<Item*> armor;
    std::vector<Item*> shield;

    // Categorize items based on their type
    for (const auto& item : _items) {
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

    // Print the inventory table
    std::cout << "|        Potions        |        Weapons        |       Materials       |        Armors        |        Shields        |"
        << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Print each row of the inventory table
    for (int i = 0; i < std::max({ potions.size(), weapons.size(), materials.size(), armor.size(), shield.size() }); i++) {
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

    std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

    // Prompt user for choice
    Choice();

    // Clear the vectors
    potions.clear();
    weapons.clear();
    materials.clear();
    armor.clear();
    shield.clear();
}

 // Get an item from the inventory
Item* Inventory::GetItem(std::string name)
{
	for (const auto& item : _items) {
		if (item->GetName() == name) {
			return item;
		}
	}
	return nullptr;
}

