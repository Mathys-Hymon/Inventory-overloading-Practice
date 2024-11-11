#pragma once

class IBakable {
public:
    virtual ~IBakable() = default;
    virtual void bake() = 0;
	virtual uint8_t getFoodType() const = 0;
};

namespace foodtype
{
	enum Type {
		Meat = 1 << 0,
		Fish = 1 << 1,
		Mushroom = 1 << 2,
		Vegetable = 1 << 3,
		Seasoning = 1 << 4,
	};
};