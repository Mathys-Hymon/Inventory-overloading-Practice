#pragma once
#include "../Item.h"
#include "../../IFlammable.h"

class Weapon : public Item, public IFlammable
{
public:
	Weapon(std::uint8_t type, int price, std::string name);

	void Burn() override;
	float SpreadSpeed() override;

	~Weapon();

protected:

};

