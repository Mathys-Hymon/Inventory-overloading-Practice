#pragma once
#include "../Item.h"

class Potion : Item
{
public:
	Potion(std::uint8_t type, int price, std::string name);

	virtual std::uint8_t GetType();
	const std::string GetName();
	const bool HasTag(std::uint8_t type);
	void addTag(std::uint8_t type);
	void removeTag(std::uint8_t type);

	~Potion();

protected:
};

