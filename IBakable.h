#pragma once

class IBakable {
public:
    virtual ~IBakable() = default;
    virtual void bake() = 0;
};