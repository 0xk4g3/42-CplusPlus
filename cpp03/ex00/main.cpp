#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.attack("Another Target");
    clap.takeDamage(10);
    clap.beRepaired(5);
    clap.attack("Final Target");
    
    return 0;
}
