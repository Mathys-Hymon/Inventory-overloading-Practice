#pragma once

#include "Item.h"
#include <memory>
#include <deque>


class Inventory {
public:

    bool hasItemWithFlag(uint8_t type) const {
        for (const auto& item : items) {
            if (item->HasTag(type)) {
                return true;
            }
        }
        return false;
    }

    void removeItem(std::shared_ptr<Item> item);

    //void sortItemsByType() {
    //    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
    //        return a->getFlags() < b->getFlags();
    //        });
    //}

private:
    std::deque<std::shared_ptr<Item>> items;
};
