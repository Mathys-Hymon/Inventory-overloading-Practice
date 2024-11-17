#pragma once
#include "string"
#include <cstdint>

namespace ItemType {
	enum Type {
		Potion = 1 << 0,
		Weapon = 1 << 1,
		Material = 1 << 2,
		Armor = 1 << 3,
		Consumable = 1 << 4,

		Common = 1 << 5,
		Rare = 1 << 6,
		Epic = 1 << 7,
	};

	inline uint8_t operator+(const uint8_t& a, const Type& b) {
		return a | b;
	}
	inline uint8_t operator+(const Type& a, const uint8_t& b) {
		return a | b;
	}
	inline uint8_t operator+(const Type& a, const Type& b) {
		return a | b;
	}

	inline uint8_t operator - (uint8_t const& a, Type const& b) {
		return a ^ b;
	}
	inline void operator += (uint8_t& a, Type const& b) {
		a |= b;
	}
	inline void operator -= (uint8_t& a, Type const& b) {
		a ^= b;
	}
}