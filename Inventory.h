#pragma once

#include "Item.h"
#include "VectorExtensions.h"
#include <vector>


class Inventory {
public:
    Inventory();
	~Inventory();

    bool HasItemWithTag(uint8_t type) const;

    void RemoveItem(Item* item);
	void AddItem(Item* item);
	void ShowInventory() const;

private:
    std::vector<Item*> items;
};
