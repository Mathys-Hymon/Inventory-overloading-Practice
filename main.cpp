#include <iostream>
#include "FoodProcessor.h"
#include "Inventory.h"
#include "vector"

#include "Items/Childs/Consumable.h"
#include "Items/Childs/Material.h"
#include "Items/Childs/Potion.h"
#include "Items/Childs/Weapon.h"
#include "Items/Childs/Armor.h"

Inventory _inventory;
FoodProcessor foodProcessor;

void Choice();
void AddItem(std::string name, int type);

int main()
{
    Consumable* mushroom = new Consumable(ItemType::Consumable + ItemType::Rare, FoodType::Mushroom, 20, "Fancy_Mushroom");
    _inventory.AddItem(mushroom);
    Consumable* meat = new Consumable(ItemType::Consumable + ItemType::Epic, FoodType::Meat, 20, "Raw_Meat");
    _inventory.AddItem(meat);

    AddItem("Sword", 4);
    AddItem("Bow", 4);
    AddItem("Wood", 2);
    AddItem("Helmet", 5);
    AddItem("Health_Potion", 3);

    Choice();

    return 0;
}



void Choice()
{
    std::cout << "\n\n\n";

    std::cout << "1. Add item\n";
    std::cout << "2. Remove item\n";
    std::cout << "3. Show inventory\n";
    std::cout << "4. Burn Item\n";
    std::cout << "5. Cook\n\n";

    std::cout << "6. Exit\n\n\n";
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
        else if (choice < 1 || choice > 6) {
            std::cout << "Invalid choice, please enter again:\n";
            choice = -1;
        }
    }
    switch (choice)
    {
        // Add item
    case 1:
    {
		std::cout << "\n\n\nType :\n\n";
		std::cout << "1 - Consumable\n";
		std::cout << "2 - Material\n";
		std::cout << "3 - Potion\n";
		std::cout << "4 - Weapon\n";
		std::cout << "5 - Armor\n\n";
        std::cout << "Enter the type of item : ";
		int type;
		std::cin >> type;

		std::cout << "Enter the name of item: ";
        std::string name;
        std::cin >> name;
        if (name.size() > 15)
        {
            std::cout << "Name is too long\n";
            std::cout << "\n\n\n";
            Choice();
            break;
        }

		AddItem(name, type);
		Choice();
		break;
    }
	// Remove item
    case 2:
    {
        _inventory.ShowInventory();
        std::cout << "Enter the name of item: ";
        std::string name;
        std::cin >> name;
        _inventory.RemoveItem(name);
        _inventory.ShowInventory();
        
        Choice();
        break;
    }
	// Show inventory
    case 3:
    {
        _inventory.ShowInventory();
        Choice();
        break;
    }
	// Burn item
	case 4: {
		_inventory.ShowInventory();
		std::cout << "which item do you want to burn? : ";
		std::string name;
		std::cin >> name;
		if (_inventory.GetItem(name) == nullptr)
		{
			std::cout << "Sorry, you dont have this item\n";
			Choice();
			break;
		}

		if (dynamic_cast<IFlammable*>(_inventory.GetItem(name)))
		{
			std::cout << name <<" has gone up in smoke\n";
			_inventory.RemoveItem(name);
		}
		else
		{
			std::cout << "Sorry, this item can't burn\n";
		}

		Choice();
		break;
	}
		  // Cook
	case 5:
	{
		_inventory.ShowInventory();
		std::cout << "which item do you want to cook? : ";
		std::vector<IBakable*> foodBakable;
        std::vector<Item*> foodItem;
		std::string name;

        while (name != "Cook")
        {
            if (foodBakable.size() < 6)
            {
				if (foodBakable.size() > 0) { std::cout << "Do you want to add anything else ? if no type : Cook       "; }

                std::cin >> name;
                if (name != "Cook")
                {
                    if (_inventory.GetItem(name) == nullptr)
                    {
                        std::cout << "Sorry, you dont have this item\n";
                        break;
                    }

                    if (dynamic_cast<IBakable*>(_inventory.GetItem(name)))
                    {
                        foodBakable.push_back(dynamic_cast<IBakable*>(_inventory.GetItem(name)));
						foodItem.push_back(_inventory.GetItem(name));
                    }
                    else
                    {
                        std::cout << "Sorry, this item can't be cooked\nWhat do you want to cook instead? : ";
                    }
                }
				else if (name == "Cook" && foodBakable.size() < 2)
				{
					std::cout << "You need to add at least one item to cook\n";
					name = " ";
				}
            }
			else
			{
				name = "You cant add more items !";
				break;
			}

        }

		if (foodBakable.size() >= 2)
		{
            for (int i = 0; i < foodItem.size(); i++)
            {
                foodBakable[i]->Bake();
                _inventory.RemoveItem(foodItem[i]);
            }

            foodProcessor.Cook(foodBakable);
		}

		Choice();
		break;
	}
	// Exit
    case 6:
    {
        break;
    }
    default:
        break;
    }
}

void AddItem(std::string name, int type)
{
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
        uint8_t tempType;
		std::cout << "\n\n\nType :\n\n";
		std::cout << "1 - Meat\n";
		std::cout << "2 - Vegetable\n";
		std::cout << "3 - Mushroom\n";
		std::cout << "4 - Fish\n";
		std::cout << "5 - Seasoning\n\n";

		std::cout << "Enter the type of food: ";
        int tempFoodName;
		std::cin >> tempFoodName;

		if (tempFoodName < 1 || tempFoodName > 5)
		{
			tempFoodName = 1;
		}
		switch (tempFoodName)
		{
		case 1:
			tempType = FoodType::Meat;
			break;
		case 2:
            tempType = FoodType::Herb;
			break;
		case 3:
			tempType = FoodType::Mushroom;
			break;
		case 4:
			tempType = FoodType::Fish;
			break;
		case 5:
			tempType = FoodType::Seasoning;
			break;
		default:
			tempType = FoodType::Meat;
			break;
		}

        Consumable* consumableItem = new Consumable(ItemType::Consumable + tempRarity, tempType, price, name);
        _inventory.AddItem(consumableItem);
        break;
    }
    case 2:
    {
        Material* materialItem = new Material(ItemType::Material + tempRarity, price, name);
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
        Armor* armorItem = new Armor(ItemType::Armor + tempRarity, price, 5, name);
        _inventory.AddItem(armorItem);
        break;
    }
	std::cout << "Item added successfully\n";

    }
}