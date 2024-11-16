#pragma once
#include "../Item.h"
#include "../../IBakable.h"

class Consumable : public Item, public IBakable
{
public:
	Consumable(std::uint8_t type, int price, std::string name);

	virtual std::uint8_t GetType();
	const std::string GetName();
	const bool HasTag(std::uint8_t type);
	void addTag(std::uint8_t type);
	void removeTag(std::uint8_t type);

	void Bake() override;
	uint8_t GetFoodType() const override;

	~Consumable();

protected:

};

