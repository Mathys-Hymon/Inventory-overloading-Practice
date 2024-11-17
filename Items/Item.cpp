#include "Item.h"

Item::Item(std::uint8_t pType, int pPrice, std::string pName)
{
	// Constructor for the Item class
	_name = pName;
	_type = pType;
	_price = pPrice;
}

Item::~Item()
{
}

const std::string Item::GetName()
{
	// Returns the name of the item
	return _name;
}

const bool Item::HasTag(std::uint8_t pType)
{
	// Checks if the item has a specific tag
	return (_type & pType) != 0;
}

const std::string Item::GetRarity()
{
	if (HasTag(ItemType::Common))
	{
		return "\033[38;2;173;216;230m";
	}
	else if (HasTag(ItemType::Rare))
	{
		return "\033[33m";
	}
	else if (HasTag(ItemType::Epic))
	{
		return "\033[38;2;221;160;221m";
	}
	else
	{
		return "\033[38;2;173;216;230m";
	}
}

void Item::addTag(std::uint8_t pType)
{
	// Adds a tag to the item
	_type += pType;
}

void Item::removeTag(std::uint8_t pType)
{
	// Removes a tag from the item
	_type -= pType;
}
