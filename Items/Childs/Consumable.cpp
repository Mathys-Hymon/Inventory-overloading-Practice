#include "Consumable.h"

Consumable::Consumable(std::uint8_t type, int price, std::string name) : Item(type, price, name)
{
}

std::uint8_t Consumable::GetType()
{
    return mType;
}

const std::string Consumable::GetName()
{
    return Item::GetName();
}

const bool Consumable::HasTag(std::uint8_t type)
{
	return Item::HasTag(type);
}

void Consumable::addTag(std::uint8_t type)
{
	Item::addTag(type);
}

void Consumable::removeTag(std::uint8_t type)
{
	Item::removeTag(type);
}

void Consumable::Bake()
{
	std::cout << "Baking " << GetName() << std::endl;
}

uint8_t Consumable::GetFoodType() const
{
	return 0;
}

Consumable::~Consumable()
{
}
