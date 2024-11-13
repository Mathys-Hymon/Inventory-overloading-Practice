#pragma once
#include "../Item.h"

class Shield : public Item
{
public:
	Shield(std::uint8_t type, int price, std::string name);
	~Shield();

protected:

};

