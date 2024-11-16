#pragma once
#include "../Item.h"

class Weapon : public Item
{
public:
	Weapon(std::uint8_t type, int price, std::string name);

	virtual std::uint8_t GetType();
	const std::string GetName();
	const bool HasTag(std::uint8_t type);
	void addTag(std::uint8_t type);
	void removeTag(std::uint8_t type);

	~Weapon();

protected:

};

