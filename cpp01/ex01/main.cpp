

#include "Zombie.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>





int main() {
    std::cout << "\n=== Testing normal cases ===" << std::endl;
    {
        Zombie* horde1 = zombieHorde(5, "Normal");
        if (horde1) {
            for (int i = 0; i < 5; i++)
                horde1[i].announce();
            delete[] horde1;
        }
    }
    return 0;
}