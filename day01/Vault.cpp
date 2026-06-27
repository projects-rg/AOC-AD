#include "Vault.h"

Vault::Vault(const Combo& combo)
{
    // Apply each rotation in order; applyRotation keeps the running zero count.
    for (const Rotation& rotation : combo.rotations())
        applyRotation(rotation);
}

int Vault::zeroCount() const noexcept
{
    return m_zeroCount;
}

void Vault::applyRotation(const Rotation& rotation)
{
    // Left lowers the number, right raises it.
    const int delta = (rotation.direction == Direction::Right)
        ? rotation.distance
        : -rotation.distance;

    // Move the dial, then wrap back into 0..99.
    // ((value % size) + size) % size keeps the result non-negative even
    // when a left turn takes us past 0 (e.g. 5 - 10 wraps to 95).
    m_position = ((m_position + delta) % DialSize + DialSize) % DialSize;

    if (m_position == 0)
        ++m_zeroCount;
}
