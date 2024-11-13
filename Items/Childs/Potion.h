#pragma once
#include "../Item.h"

class Potion : public Item
{
public:
	Potion(std::uint8_t type, int price, std::string name);
	~Potion();

protected:
};

