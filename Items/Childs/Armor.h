#pragma once
#include "../Item.h"

class Armor : public Item
{
public:
	Armor(std::uint8_t type, int price, std::string name);
	~Armor();

protected:

};

