#include "Weapon.h"

Weapon::Weapon(std::uint8_t type, int price, std::string name) : Item(type, price, name)
{
}

std::uint8_t Weapon::GetType()
{
    return std::uint8_t();
}

const std::string Weapon::GetName()
{
    return std::string();
}

const bool Weapon::HasTag(std::uint8_t type)
{
    return false;
}

void Weapon::addTag(std::uint8_t type)
{
}

void Weapon::removeTag(std::uint8_t type)
{
}

Weapon::~Weapon()
{
}
