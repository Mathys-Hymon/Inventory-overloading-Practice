#pragma once

#include "Item.h"
#include <vector>
#include <memory>

#include "Item.h"
#include <vector>
#include <memory>
#include <algorithm>

class Inventory {
public:
    Inventory& operator+=(std::shared_ptr<Item> item) {
        items.push_back(item);
        return *this;
    }

    Inventory& operator-=(std::shared_ptr<Item> item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
        return *this;
    }

    bool hasItemWithFlag(uint8_t type) const {
        for (const auto& item : items) {
            if (item->HasTag(type)) {
                return true;
            }
        }
        return false;
    }

    void removeItem(std::shared_ptr<Item> item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    void sortItemsByType() {
        std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            return a->getFlags() < b->getFlags();
            });
    }

private:
    std::vector<std::shared_ptr<Item>> items;
};
