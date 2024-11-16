#pragma once

#include "Items/Item.h"
#include "VectorExtensions.h"
#include <vector>


class Inventory {
public:
    Inventory();
	~Inventory();

    bool HasItemWithTag(uint8_t pType) const;

    void RemoveItem(Item* pItem);
    void RemoveItem(std::string pItemName);
	void AddItem(Item* pItem);
	void ShowInventory();
	Item* GetItem(std::string pName);

private:
    std::vector<Item*> _items;
	float _maxSize = 100.0f;
};
