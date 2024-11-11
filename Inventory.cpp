#include "Inventory.h"

void Inventory::removeItem(std::shared_ptr<Item> item)
{
	items.erase(std::remove(items.begin(), items.end(), item), items.end());
}