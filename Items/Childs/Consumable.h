#pragma once
#include "../Item.h"
#include "../../IBakable.h"

class Consumable : public Item, public IBakable
{
public:
	Consumable(std::uint8_t pType,std::uint8_t pFoodType, int pPrice, std::string pName);

	virtual std::uint8_t GetType();
	const std::string GetName();
	const bool HasTag(std::uint8_t pType);
	void addTag(std::uint8_t pType);
	void removeTag(std::uint8_t pType);

	void Bake() override;
	uint8_t GetFoodType() const override;

	~Consumable();

protected:
	uint8_t _foodType;
};

