

#include "Zombie.hpp"






int main() {
    std::cout << "\n=== Testing normal cases ===" << std::endl;
    {
        Zombie* horde1 = zombieHorde(N, "Normal");
        if (horde1) {
            for (int i = 0; i < N; i++)
                horde1[i].announce();
            delete[] horde1;
        }
    }
    return 0;
}