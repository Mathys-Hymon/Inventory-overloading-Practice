#include "Material.h"

Material::Material(std::uint8_t type, int price, std::string name) : Item(type, price, name)
{
}

std::uint8_t Material::GetType()
{
    return std::uint8_t();
}

const std::string Material::GetName()
{
    return std::string();
}

const bool Material::HasTag(std::uint8_t type)
{
    return false;
}

void Material::addTag(std::uint8_t type)
{
}

void Material::removeTag(std::uint8_t type)
{
}

void Material::Burn()
{
}

float Material::SpreadSpeed()
{
    return 0.0f;
}

Material::~Material()
{
}
