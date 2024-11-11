#pragma once

#include "Item.h"
#include <vector>


class Inventory {
public:

    bool hasItemWithTag(uint8_t type) const;

    void removeItem(std::shared_ptr<Item> item);

    //void sortItemsByType() {
    //    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
    //        return a->getFlags() < b->getFlags();
    //        });
    //}

private:
    std::vector<std::shared_ptr<Item>> items;
};
