#include "Inventory.h"

// Default constructor
Inventory::Inventory()
{
	_items.reserve(1);
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
void Inventory::AddItem(Item* pItem) {
    bool isAdded = false;

    // Parcours en partant de la fin, pour ajouter l'élément après le dernier du même type
    for (int i = _items.size() - 1; i >= 0; --i) {
        if (_items[i]->GetType() == pItem->GetType()) {
            _items.insert(_items.begin() + i + 1, pItem);
            std::cout << "item " + pItem->GetName() + " added at index " << i + 1 << "\n";
            isAdded = true;
            break;
        }
    }

    // Si aucun item du même type n'a été trouvé, on utilise _items += pItem
    if (!isAdded) {
        _items += pItem;
        std::cout << "item " + pItem->GetName() + " added at the end\n";
    }
}

// Show the inventory
void Inventory::ShowInventory()
{
    // Separate vectors for different item types
    std::vector<Item*> potions;
    std::vector<Item*> weapons;
    std::vector<Item*> materials;
    std::vector<Item*> consummable;
    std::vector<Item*> armor;
    std::vector<Item*> shield;

    // Categorize items based on their type
    for (int i = 0; i < _items.size(); i++) {

        if (_items[i]->HasTag(ItemType::Potion))
        {
			potions += _items[i];
		}
		else if (_items[i]->HasTag(ItemType::Weapon))
		{
			weapons += _items[i];
		}
		else if (_items[i]->HasTag(ItemType::Materials))
		{
			materials += _items[i];
		}
		else if (_items[i]->HasTag(ItemType::Armor))
		{
			armor += _items[i];
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
            
            for (int j = 0; j < (23 - potions[i]->GetName().size()) / 2; j++)
            {
				std::cout << " ";
            }
            std::cout << potions[i]->GetName();
            for (int j = 0; j < (23 - potions[i]->GetName().size()) / 2; j++)
            {
                std::cout << " ";
            }
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

            for (int j = 0; j < (23 - armor[i]->GetName().size()) / 2; j++)
            {
                std::cout << " ";
            }
            std::cout << potions[i]->GetName();
            for (int j = 0; j < (23 - armor[i]->GetName().size()) / 2; j++)
            {
                std::cout << " ";
            }
        }
        else {
            std::cout << "                      ";
        }
        std::cout << "|";
        if (i < shield.size()) {

            for (int j = 0; j < (23 - shield[i]->GetName().size()) / 2; j++)
            {
                std::cout << " ";
            }
            std::cout << potions[i]->GetName();
            for (int j = 0; j < (23 - shield[i]->GetName().size()) / 2; j++)
            {
                std::cout << " ";
            }
        }
        else {
            std::cout << "                       ";
        }
        std::cout << "|\n";
    }
    std::cout << _items.size() + " / " << _maxSize << " ";

    for (int i = 0; i < 120 - (std::to_string(_items.size()) + " / " + std::to_string(_maxSize) + " ").size(); i++)
    {
        std::cout << "-";
    }
    //std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "\n\n\n";

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

