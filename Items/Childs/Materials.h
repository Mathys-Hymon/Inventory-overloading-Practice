#pragma once
#include "../Item.h"
#include "../../IFlammable.h"

class Materials : public Item, public IFlammable
{
public:
	Materials(std::uint8_t type, int price, std::string name);

	void Burn() override;
	float SpreadSpeed() override;

	~Materials();

protected:

};

