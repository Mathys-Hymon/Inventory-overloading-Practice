#pragma once
#include "../ItemType.h"
#include "iostream"

class Item
{
public:
	Item(std::uint8_t pType, int pPrice, std::string pName);
    ~Item();

    virtual std::uint8_t GetType() = 0;
	const std::string GetName();
    const bool HasTag(std::uint8_t pType);
	const std::string GetRarity();
	void addTag(std::uint8_t pType);
	void removeTag(std::uint8_t pType);

protected:
	std::uint8_t _type = 0;
	int _price = 0;
	std::string _name = " ";


};
