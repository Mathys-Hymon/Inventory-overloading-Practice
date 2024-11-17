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

    for (int i = _items.size() - 1; i >= 0; --i) {
        if (_items[i]->GetType() == pItem->GetType()) {
            _items.insert(_items.begin() + i + 1, pItem);
            std::cout << "item " + pItem->GetName() + " added at index " << i + 1 << "\n";
            isAdded = true;
            break;
        }
    }

    if (!isAdded) {
        _items += pItem;
        std::cout << "item " + pItem->GetName() + " added at the end\n";
    }
}

// Show the inventory
void Inventory::ShowInventory()
{

	if (_items.size() == 0)
	{
		std::cout << "Inventory is empty\n";
		return;
	}


    // Separate vectors for different item types
    std::vector<Item*> potions;
    std::vector<Item*> weapons;
    std::vector<Item*> materials;
    std::vector<Item*> consumable;
    std::vector<Item*> armor;

    // Categorize items based on their type
    for (int i = 0; i < _items.size(); i++) {

        if (_items[i]->HasTag(ItemType::Potion))
        {
			potions += _items[i];
		}
	    if (_items[i]->HasTag(ItemType::Weapon))
		{
			weapons += _items[i];
		}
	    if (_items[i]->HasTag(ItemType::Material))
		{
			materials += _items[i];
		}
	    if (_items[i]->HasTag(ItemType::Armor))
		{
			armor += _items[i];
		}
        if (_items[i]->HasTag(ItemType::Consumable))
        {
            consumable += _items[i];
        }
    }

    std::cout << "\n\nRarity : \n\n" << "\033[38;2;173;216;230m" << "Blue" << "\033[0m" << " - Common\n"<<"\033[33m" << "Yellow" << "\033[0m" << " - Rare\n" << "\033[38;2;221;160;221m"  << "Purple"  <<"\033[0m" << " - Epic\n" ;
    // Print the inventory table
    std::cout << "\n|        Potions       |       Weapons        |       Materials      |        Armors        |     Consummables     |"
        << std::endl;
    std::cout << "|----------------------|----------------------|----------------------|----------------------|----------------------|" << std::endl;

    // Print each row of the inventory table
    for (int i = 0; i < std::max({ potions.size(), weapons.size(), materials.size(), armor.size(), consumable.size() }); i++) {
        std::cout << "|";
        if (i < potions.size()) {
            
            int loopNumber = (22 - potions[i]->GetName().size()) / 2;

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }

            std::cout << potions[i]->GetRarity() << potions[i]->GetName() << "\033[0m";


            if (potions[i]->GetName().size() % 2 != 0 || potions[i]->GetName().size() == 1)
            {
                loopNumber++;
            }

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
        }
        else std::cout << "                      ";

        std::cout << "|";

        if (i < weapons.size()) {
            int loopNumber = (22 - weapons[i]->GetName().size()) / 2;

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
            std::cout << weapons[i]->GetRarity() << weapons[i]->GetName() << "\033[0m";

            if (weapons[i]->GetName().size() % 2 != 0 || weapons[i]->GetName().size() == 1)
            {
                loopNumber++;
            }

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
        }
        else std::cout << "                      ";

        std::cout << "|";
        if (i < materials.size()) {
            int loopNumber = (22 - materials[i]->GetName().size()) / 2;

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
            std::cout << materials[i]->GetRarity() << materials[i]->GetName()  << "\033[0m";

            if (materials[i]->GetName().size() % 2 != 0 || materials[i]->GetName().size() == 1)
            {
                loopNumber++;
            }

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
        }
        else std::cout << "                      ";

        std::cout << "|";

        if (i < armor.size()) 
        {

            int loopNumber = (22 - armor[i]->GetName().size()) / 2;

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
            std::cout << armor[i]->GetRarity() << armor[i]->GetName() << "\033[0m";

            if (armor[i]->GetName().size() % 2 != 0 || armor[i]->GetName().size() == 1)
            {
                loopNumber++;
            }

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
        }
        else std::cout << "                      ";

        std::cout << "|";

        if (i < consumable.size()) {


            int loopNumber = (22 - consumable[i]->GetName().size()) / 2;

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
            std::cout << consumable[i]->GetRarity() << consumable[i]->GetName() << "\033[0m";


            if (consumable[i]->GetName().size() % 2 != 0 || consumable[i]->GetName().size() == 1)
            {
                loopNumber++;
            }

            for (int j = 0; j < loopNumber; j++)
            {
                std::cout << " ";
            }
        }
        else std::cout << "                      ";

        std::cout << "|\n";
    }

    std::cout << _items.size() << " / " << _maxSize << " ";

    for (int i = 0; i < 123 - (std::to_string(_items.size()) + " / " + std::to_string(_maxSize) + " ").size(); i++)
    {
        std::cout << "-";
    }
    std::cout << "\n\n\n";

    // Clear the vectors
    potions.clear();
    weapons.clear();
    materials.clear();
    armor.clear();
    consumable.clear();
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

