#pragma once
#include "../Item.h"
#include "../../IBakable.h"

class Consumable : public Item, public IBakable
{
public:
	Consumable(std::uint8_t type, int price, std::string name);

	void Bake() override;
	uint8_t GetFoodType() const override;

	~Consumable();

protected:

};

