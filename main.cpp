#include <iostream>
#include "FoodProcessor.h"
#include "Inventory.h"

#include "Items/Childs/Consumable.h"/*
#include "Items/Childs/Materials.h"
#include "Items/Childs/Potion.h"
#include "Items/Childs/Shield.h"
#include "Items/Childs/Weapon.h"
#include "Items/Childs/Armor.h"*/

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
        std::cout << "Enter the type of item : ";
		std::string type;
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



        std::uint8_t tags = ItemType::Armor + ItemType::Epic;

        Consumable* consumableItem = new Consumable(tags, 2, name);
        _inventory.AddItem(consumableItem);

        Choice();
        break;

        /* switch (tag)
         {
         case ItemType::Consumable:
         {
             Consumable* consumableItem = new Consumable(tag, price, name);
             _inventory.AddItem(consumableItem);
             break;
         }*/
         //case ItemType::Materials:
         //{
         //    Materials* materialsItem = new Materials(tag, price, name);
         //    _inventory.AddItem(materialsItem);
         //    break;
         //}
         //case ItemType::Potion:
         //{
         //    Potion* potionItem = new Potion(tag, price, name);
         //    _inventory.AddItem(potionItem);
         //    break;
         //}
         //case ItemType::Shield:
         //{
         //    Shield* shieldItem = new Shield(tag, price, name);
         //    _inventory.AddItem(shieldItem);
         //    break;
         //}
         //case ItemType::Weapon:
         //{
         //    Weapon* weaponItem = new Weapon(tag, price, name);
         //    _inventory.AddItem(weaponItem);
         //    break;
         //}
         //case ItemType::Armor:
         //{
         //    Armor* armorItem = new Armor(tag, price, name);
         //    _inventory.AddItem(armorItem);
         //    break;
         //}

         //default:
         //    break;
         //}
         //break;
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

