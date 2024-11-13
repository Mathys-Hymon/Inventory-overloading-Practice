#include "Item.h"

Item::Item(std::uint8_t type, int price, std::string name)
{
	// Constructor for the Item class
	mName = name;
	mType = type;
	mPrice = price;
}

std::uint8_t Item::GetType()
{
	// Returns the type of the item
	return mType;
}

const std::string Item::GetName()
{
	// Returns the name of the item
	return mName;
}

const bool Item::HasTag(std::uint8_t type)
{
	// Checks if the item has a specific tag
	return mType == type;
}

void Item::addTag(std::uint8_t type)
{
	// Adds a tag to the item
	mType += type;
}

void Item::removeTag(std::uint8_t type)
{
	// Removes a tag from the item
	mType -= type;
}
