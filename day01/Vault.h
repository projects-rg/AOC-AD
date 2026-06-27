#pragma once
#include "Combo.h"

// constructer triggers rotations
class Vault
{
public:
    explicit Vault(const Combo& combo);

    // counter for == 0.
    int zeroCount() const noexcept;

private:
    void applyRotation(const Rotation& rotation);

    static constexpr int DialSize = 100;     // dial has 0-99 so 100 total
    static constexpr int StartPosition = 50; // dial always starts here

    int m_position{ StartPosition };
    int m_zeroCount{ 0 };
};
