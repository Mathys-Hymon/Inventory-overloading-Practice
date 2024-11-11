#pragma once

#include "Item.h"
#include "VectorExtensions.h"
#include <vector>


class Inventory {
public:

    bool HasItemWithTag(uint8_t type) const;

    void RemoveItem(std::shared_ptr<Item> item);
	void AddItem(std::shared_ptr<Item> item);
	void ShowInventory() const;

private:
    std::vector<std::shared_ptr<Item>> items;
};
