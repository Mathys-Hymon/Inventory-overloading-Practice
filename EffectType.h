#pragma once
#include "string"
#include <cstdint>

namespace EffectType {
	enum Effect {
		NightVision = 1 << 0,  // Allows the player to see in the dark 
		Speed = 1 << 1,  // Increases movement speed 
		Slowness = 1 << 2,  // Decreases movement speed
		Haste = 1 << 3,  // Increases mining speed
		MiningFatigue = 1 << 4,  // Decreases mining speed
		Strength = 1 << 5,  // Increases melee damage
		Healing = 1 << 6,  // Instantly restores health
		Null = 1 << 7   // noEffects
	};
        std::string getEffectName(uint8_t effect) {
            switch (effect) {
			case Effect::NightVision:
                    return "NightVision";
                case Effect::Speed:
                    return "Speed";
                case Effect::Slowness:
                    return "Slowness";
                case Effect::Haste:
                    return "Haste";
                case Effect::MiningFatigue:
                    return "MiningFatigue";
                case Effect::Strength:
                    return "Strength";
                case Effect::Healing:
                    return "Healing";
                case Effect::Null:
                    return "null";
                default:
                    return "Unknown";
            }
    }
	inline uint8_t operator+(const uint8_t& a, const Effect& b) {
		return a | b;
	}
	inline uint8_t operator+(const Effect& a, const uint8_t& b) {
		return a | b;
	}
	inline uint8_t operator+(const Effect& a, const Effect& b) {
		return a | b;
	}

	inline uint8_t operator - (uint8_t const& a, Effect const& b) {
		return a ^ b;
	}
	inline void operator += (uint8_t& a, Effect const& b) {
		a |= b;
	}
	inline void operator -= (uint8_t& a, Effect const& b) {
		a ^= b;
	}
}