#include <iostream>
#include "FoodProcessor.h"
#include "Inventory.h"

#include "Items/Childs/Consumable.h"
#include "Items/Childs/Material.h"
#include "Items/Childs/Potion.h"
#include "Items/Childs/Weapon.h"
#include "Items/Childs/Armor.h"

Inventory _inventory;

void Choice();

int main()
{

    FoodProcessor foodProcessor;
    std::vector<std::shared_ptr<IBakable>> ingredients;
    // Example usage of foodProcessor
    auto cookedItem = foodProcessor.Cook(ingredients);

    Choice();

    return 0;
}


void Choice()
{
    std::cout << "\n\n\n";

    std::cout << "1. Add item\n";
    std::cout << "2. Remove item\n";
    std::cout << "3. Show inventory\n";
    std::cout << "4. Exit\n\n\n";
    std::cout << "Enter your choice: ";

    int choice = -1;

    while (choice == -1)
    {

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice, please enter again:\n";
            choice = -1;
        }
        else if (choice < 1 || choice > 4) {
            std::cout << "Invalid choice, please enter again:\n";
            choice = -1;
        }
    }
    switch (choice)
    {
        // Add item
    case 1:
    {
		std::cout << "1 - Consumable\n";
		std::cout << "2 - Materials\n";
		std::cout << "3 - Potion\n";
		std::cout << "4 - Weapon\n";
		std::cout << "5 - Armor\n\n\n";
        std::cout << "Enter the type of item : ";
		int type;
		std::cin >> type;

		std::cout << "Enter the name of item: ";
        std::string name;
        std::cin >> name;
        if (name.size() > 10)
        {
            std::cout << "Name is too long\n";
            std::cout << "\n\n\n";
            Choice();
            break;
        }

		int price = rand() % 100 + 1;
		int rarityInt = rand() % 3 + 1;
		std::uint8_t tempRarity = 0;

        switch (rarityInt)
        {
		case 1:
			tempRarity = ItemType::Common;
			break;
		case 2:
			tempRarity = ItemType::Rare;
			break;
		case 3:
			tempRarity = ItemType::Epic;
			break;

        default:
            tempRarity = ItemType::Common;
			break;

        }

         switch (type)
         {
         case 1:
         {
             Consumable* consumableItem = new Consumable(ItemType::Consumable + tempRarity, price, name);
             _inventory.AddItem(consumableItem);
             break;
         }
         case 2:
         {
             Material* materialItem = new Material(ItemType::Materials + tempRarity, price, name);
             _inventory.AddItem(materialItem);
             break;
         }
         case 3:
         {
             Potion* potionItem = new Potion(ItemType::Potion + tempRarity, price, name);
             _inventory.AddItem(potionItem);
             break;
         }
         case 4:
         {
             Weapon* weaponItem = new Weapon(ItemType::Weapon + tempRarity, price, name);
             _inventory.AddItem(weaponItem);
             break;
         }
         case 5:
         {
             Armor* armorItem = new Armor(ItemType::Armor + tempRarity, price, name);
             _inventory.AddItem(armorItem);
             break;
         }

         default:
             Choice();
             break;
         }

		 Choice();
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
        Choice();
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

