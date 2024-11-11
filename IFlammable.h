#pragma once

class IFlammable {
public:
	virtual void Burn() = 0;
	virtual float SpreadSpeed() = 0;
};