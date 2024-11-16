#pragma once
#include "../Item.h"

class Armor : public Item
{
public:
	Armor(std::uint8_t type, int price, std::string name);

	virtual std::uint8_t GetType();
	const std::string GetName();
	const bool HasTag(std::uint8_t type);
	void addTag(std::uint8_t type);
	void removeTag(std::uint8_t type);

	~Armor();

protected:

};

