#include "Item.h"

Item::Item(std::uint8_t type, int price, std::string name)
{
	mName = name;
	mType = type;
	mPrice = price;
}

std::uint8_t Item::GetType()
{
	return mType;
}

const bool Item::HasTag(std::uint8_t type)
{
	return mType == type;
}

void Item::addTag(std::uint8_t type)
{
	mType += type;
}

void Item::removeTag(std::uint8_t type)
{
	mType -= type;
}
