#pragma once
#include <cstdint>

namespace ItemType {
	enum Type {
		Potion = 1 << 0,
		Weapon = 1 << 1,
		Materials = 1 << 2,
		Armor = 1 << 3,
		Shield = 1 << 4,
		Consumable = 1 << 5,

		Common = 1 << 6,
		Rare = 1 << 7,
		Epic = 1 << 8,
	};

	inline uint8_t operator + (uint8_t const& a, Type const& b) {
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
	inline bool operator == (uint8_t const& a, Type const& b) {
		return a & b;
	}
}