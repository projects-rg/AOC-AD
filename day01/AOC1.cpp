// AOC1.cpp : program entry point.
// Day 1: count how many times the safe dial lands on 0.

#include <iostream>
#include <stdexcept>
#include "Combo.h"
#include "Vault.h"

int main()
{
    try
    {
        // Combo hides all the file reading and parsing.
        const Combo combo("");

        // Vault hides all the dial simulation.
        const Vault vault(combo);

        std::cout << "The dial landed on 0 a total of "
                  << vault.zeroCount() << " times.\n";
    }
    catch (const std::exception& ex)
    {
        // e.g. missing input file or a malformed line.
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }

    return 0;
}
