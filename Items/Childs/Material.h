#pragma once
#include "../Item.h"
#include "../../IFlammable.h"

class Material : public Item, public IFlammable
{
public:
	Material(std::uint8_t type, int price, std::string name);

	virtual std::uint8_t GetType();
	const std::string GetName();
	const bool HasTag(std::uint8_t type);
	void addTag(std::uint8_t type);
	void removeTag(std::uint8_t type);

	void Burn() override;
	float SpreadSpeed() override;

	~Material();

protected:

};

