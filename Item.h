#pragma once
#include "ItemType.h"
#include "iostream"

class Item
{
public:
	Item(std::uint8_t type, int price, std::string name);
	virtual ~Item() = 0;

    std::uint8_t GetType();
	const std::string GetName();
    const bool HasTag(std::uint8_t type);
	void addTag(std::uint8_t type);
	void removeTag(std::uint8_t type);

protected:

	std::uint8_t mType = 0;
	int mPrice = 0;
	std::string mName = " ";


};



