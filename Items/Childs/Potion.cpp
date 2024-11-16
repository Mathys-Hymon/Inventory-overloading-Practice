#include "Potion.h"

Potion::Potion(std::uint8_t type, int price, std::string name) : Item(type, price, name)
{
}

std::uint8_t Potion::GetType()
{
    return std::uint8_t();
}

const std::string Potion::GetName()
{
    return std::string();
}

const bool Potion::HasTag(std::uint8_t type)
{
    return false;
}

void Potion::addTag(std::uint8_t type)
{
}

void Potion::removeTag(std::uint8_t type)
{
}

Potion::~Potion()
{
}
