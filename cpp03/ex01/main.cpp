
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    
    return 0;
}
