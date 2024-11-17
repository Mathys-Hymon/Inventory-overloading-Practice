#include "Consumable.h"

Consumable::Consumable(std::uint8_t pType, std::uint8_t pFoodType, int pPrice, std::string pName) : Item(pType, pPrice, pName), _foodType(pFoodType)
{
}

std::uint8_t Consumable::GetType()
{
    return _type;
}

const std::string Consumable::GetName()
{
    return Item::GetName();
}

const bool Consumable::HasTag(std::uint8_t pType)
{
	return Item::HasTag(pType);
}

void Consumable::addTag(std::uint8_t pType)
{
	Item::addTag(pType);
}

void Consumable::removeTag(std::uint8_t pType)
{
	Item::removeTag(pType);
}

void Consumable::Bake()
{
	std::cout << "Baking " << GetName() << std::endl;
}

uint8_t Consumable::GetFoodType() const
{
	return _foodType;
}

Consumable::~Consumable()
{
}
