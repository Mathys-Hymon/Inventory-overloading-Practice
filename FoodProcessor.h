#pragma once
#include "Item.h"
#include "IBakable.h"
#include <memory>
#include <vector>

class FoodProcessor {
public:
    std::shared_ptr<Item> Cook(const std::vector<std::shared_ptr<IBakable>>& ingredients) {
        // Logic to determine the output item based on ingredients
        // Example: return VegetableStew or MushroomSteak based on ingredient combination
        return nullptr; // Placeholder
    }
};