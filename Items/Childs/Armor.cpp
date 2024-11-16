#include "Armor.h"

Armor::Armor(std::uint8_t type, int price, std::string name) : Item(type, price, name)
{
}

std::uint8_t Armor::GetType()
{
    return std::uint8_t();
}

const std::string Armor::GetName()
{
    return std::string();
}

const bool Armor::HasTag(std::uint8_t type)
{
    return false;
}

void Armor::addTag(std::uint8_t type)
{
}

void Armor::removeTag(std::uint8_t type)
{
}

Armor::~Armor()
{
}
