#pragma once
#include <string>
#include <vector>

// Which way the dial is turned.
enum class Direction
{
    Left,   // -
    Right   // +
};

struct Rotation
{
    Direction direction{};
    int distance{};
};

// Read input file and get rotations
// reading from file and parsing is hidden in .cpp file,
// so when called will see a clean list of rotations.
class Combo
{
public:
    explicit Combo(std::string filePath);

    // readonly access, rotations should never be allowed to be updated by caller. Only set
    const std::vector<Rotation>& rotations() const noexcept;

private:
    void loadFromFile();
    static Rotation parseLine(const std::string& line);

    std::string m_filePath;
    std::vector<Rotation> m_rotations;
};
