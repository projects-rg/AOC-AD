#include "Combo.h"
#include <fstream>
#include <stdexcept>

Combo::Combo(std::string filePath)
    : m_filePath(std::move(filePath)) //con list assignment
{
    loadFromFile();
}

const std::vector<Rotation>& Combo::rotations() const noexcept
{
    return m_rotations;
}

// Open the file once and ignore the blank lines if any exist
void Combo::loadFromFile()
{
    std::ifstream file(m_filePath);
    if (!file)
        throw std::runtime_error("Could not open input file: " + m_filePath);

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue; // ignore (exit broke?)

        m_rotations.push_back(parseLine(line));
    }
}

// Convert line into rotate.
// char 1 is direction.
Rotation Combo::parseLine(const std::string& line)
{
    Direction direction;
    switch (line.front())
    {
    case 'L': direction = Direction::Left;  break;
    case 'R': direction = Direction::Right; break;
    default:
        throw std::runtime_error("Invalid rotation direction in line: " + line);
    }

    const int distance = std::stoi(line.substr(1));
    return Rotation{ direction, distance };
}
