#include <iostream>
#include "FoodProcessor.h"
#include "Inventory.h"

#include "Items/Childs/Consumable.h"
#include "Items/Childs/Materials.h"
#include "Items/Childs/Potion.h"
#include "Items/Childs/Shield.h"
#include "Items/Childs/Weapon.h"
#include "Items/Childs/Armor.h"

Inventory _inventory;
int main()
{
	_inventory.ShowInventory();



	FoodProcessor foodProcessor;

    return 0;
}

void Choice()
{
    std::cout << "1. Add item\n";
    std::cout << "2. Remove item\n";
    std::cout << "3. Show inventory\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";

    int choice = -1;

    while (choice == -1)
    {
        std::cin >> choice;
        if (choice < 1 || choice > 4)
        {
            std::cout << "Invalid choice, please enter again: ";
            choice = -1;
        }
    }
    switch (choice)
    {
		// Add item
    case 1:
    {
        std::cout << "Enter the type of item: ";
        int type;
        std::cin >> type;
        std::cout << "Enter the name of item: ";
        std::string name;
        std::cin >> name;
        std::cout << "Enter the weight of item: ";
        float weight;
        std::cin >> weight;
        std::cout << "Enter the price of item: ";
        int price;
        std::cin >> price;
        std::cout << "Enter the tag of item: ";
        uint8_t tag;
        std::cin >> tag;

        switch (tag)
        {
		case ItemType::Consumable:
		{
			Consumable* consumableItem = new Consumable(tag, price, name);
			_inventory.AddItem(consumableItem);
			break;
		}
		case ItemType::Materials:
		{
			Materials* materialsItem = new Materials(tag, price, name);
			_inventory.AddItem(materialsItem);
			break;
		}
		case ItemType::Potion:
		{
			Potion* potionItem = new Potion(tag, price, name);
			_inventory.AddItem(potionItem);
			break;
		}
		case ItemType::Shield:
		{
			Shield* shieldItem = new Shield(tag, price, name);
			_inventory.AddItem(shieldItem);
			break;
		}
		case ItemType::Weapon:
		{
			Weapon* weaponItem = new Weapon(tag, price, name);
			_inventory.AddItem(weaponItem);
			break;
		}
		case ItemType::Armor:
		{
			Armor* armorItem = new Armor(tag, price, name);
			_inventory.AddItem(armorItem);
			break;
		}

        default:
            break;
        }
        break;
    }
    case 2:
    {
        std::cout << "Enter the name of item: ";
        std::string name;
        std::cin >> name;
		_inventory.RemoveItem(name);
        Choice();
        break;
    }
    case 3:
    {
        _inventory.ShowInventory();
        break;
    }
    case 4:
    {
        break;
    }
    default:
        break;
    }
}