#include "Inventory.h"

bool Inventory::hasItemWithTag(uint8_t type) const
{
        for (const auto& item : items) {
            if (item->HasTag(type)) {
                return true;
            }
        }
        return false;
}

void Inventory::removeItem(std::shared_ptr<Item> item)
{
	items.erase(std::remove(items.begin(), items.end(), item), items.end());
}