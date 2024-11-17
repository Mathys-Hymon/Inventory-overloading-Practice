#pragma once
#include "Items/Item.h"
#include "IBakable.h"
#include "EffectType.h"
#include <memory>
#include <vector>

// Structure to hold recipe details
struct Recipe {
    std::string _output; 
    std::vector<uint8_t> _requiredTypes;
	uint8_t _effect;
	float _effectDuration;
};

class FoodProcessor {

public:
    FoodProcessor() {
        // Initialize recipes
        _recipes = {
            { "VegetableStew", { FoodType::Herb, FoodType::Seasoning }, EffectType::Healing, 15.0f },
            { "MushroomSteak", { FoodType::Mushroom, FoodType::Meat }, EffectType::Strength, 10.0f },
            { "Fish and Chips", { FoodType::Fish, FoodType::Herb }, EffectType::Speed, 12.0f },
            { "Herbal Tea", { FoodType::Herb, FoodType::Seasoning }, EffectType::Haste, 8.0f },
            { "Grilled Fish", { FoodType::Fish, FoodType::Seasoning }, EffectType::NightVision, 10.0f },
            { "Meaty Stir Fry", { FoodType::Meat, FoodType::Herb }, EffectType::Strength + EffectType::Speed, 15.0f },
            { "Mushroom Soup", { FoodType::Mushroom, FoodType::Seasoning }, EffectType::Healing, 12.0f },
            { "Exotic Salad", { FoodType::Herb, FoodType::Herb, FoodType::Seasoning }, EffectType::Haste + EffectType::Healing, 20.0f },
            { "Spicy Meat Skewers", { FoodType::Meat, FoodType::Seasoning }, EffectType::Strength, 10.0f },
            { "Seafood Platter", { FoodType::Fish, FoodType::Mushroom, FoodType::Seasoning }, EffectType::Speed + EffectType::NightVision, 18.0f },
            { "Herb Crusted Fish", { FoodType::Fish, FoodType::Herb, FoodType::Seasoning }, EffectType::Haste + EffectType::Healing, 14.0f },
            { "Meat and Mushroom Skewers", { FoodType::Meat, FoodType::Mushroom, FoodType::Seasoning }, EffectType::Strength + EffectType::Healing, 12.0f },
            { "Vegetable Curry", { FoodType::Herb, FoodType::Herb, FoodType::Seasoning }, EffectType::Healing + EffectType::Speed, 18.0f },
            { "Mushroom Omelette", { FoodType::Mushroom, FoodType::Seasoning }, EffectType::Haste, 10.0f },
            { "Meat Pie", { FoodType::Meat, FoodType::Seasoning }, EffectType::Strength + EffectType::Haste, 15.0f },
            { "Vegetable Stir Fry", { FoodType::Herb, FoodType::Seasoning }, EffectType::Speed, 10.0f },
            { "Herb Crusted Meat", { FoodType::Meat, FoodType::Herb, FoodType::Seasoning }, EffectType::Strength + EffectType::NightVision, 14.0f },
            { "Mushroom Risotto", { FoodType::Mushroom, FoodType::Seasoning }, EffectType::Healing, 10.0f },
            { "Fish Pie", { FoodType::Fish, FoodType::Seasoning }, EffectType::NightVision, 12.0f }
        };
    }

    void Cook(const std::vector<IBakable*> ingredients) 
    {
        bool recipeFound = false;
        // Check if the ingredients match any of the recipes
        for (const auto& recipe : _recipes) {
            if (recipe._requiredTypes.size() != ingredients.size()) {
                continue;
            }

            bool match = true;
            for (const auto& type : recipe._requiredTypes) {
                if (std::find_if(ingredients.begin(), ingredients.end(), [type](IBakable* ingredient) { return ingredient->GetFoodType() == type; }) == ingredients.end()) {
                    match = false;
                    break;
                }
            }
            if (match) {
                // Print the cooked food and its effect
                std::cout << "\n\nYou have cooked and eaten " + recipe._output + " and it gives you " + EffectType::getEffectName(recipe._effect) + " for " + std::to_string((int)recipe._effectDuration) + " seconds\n\n";
                recipeFound = true;
                break;
            }
        }
        if (!recipeFound) {
            // Print the message for cooking dubious food
            std::cout << "You have cooked and eaten Dubious Food that doesn't give you any effect";
        }
    }

private:
    std::vector<Recipe> _recipes;

};