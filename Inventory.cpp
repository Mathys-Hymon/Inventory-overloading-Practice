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
bool Inventory::HasItemWithTag(uint8_t type) const
{
    for (const auto& item : items) {
        if (item->HasTag(type)) {
            return true;
        }
    }
    return false;
}

// Remove an item from the inventory
void Inventory::RemoveItem(Item* item)
{
    items -= item;
}

// Add an item to the inventory
void Inventory::AddItem(Item* item)
{
    bool isAdded = false;
    for (int i = items.size(); i > 0; i--)
    {
        if (item->GetType() == items[i]->GetType())
        {
            items.insert(items.begin() + i + 1, item);
            isAdded = true;
            return;
        }
    }
    if (!isAdded)
    {
        items += item;
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

// Handle user's choice
void Inventory::Choice()
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
        std::cout << "Enter the value of item: ";
        int value;
        std::cin >> value;
        std::cout << "Enter the tag of item: ";
        uint8_t tag;
        std::cin >> tag;
        //Item* item = new Item(tag, name, weight, value, tag);
        //AddItem(item);
        break;
    }
    case 2:
    {
        std::cout << "Enter the name of item: ";
        std::string name;
        std::cin >> name;
        for (const auto& item : items) {
            if (item->GetName() == name) {
                RemoveItem(item);
                std::cout << item->GetName() + " Removed successfully ! ";
                break;
            }
        }
        Choice();
        break;
    }
    case 3:
    {
        ShowInventory();
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
