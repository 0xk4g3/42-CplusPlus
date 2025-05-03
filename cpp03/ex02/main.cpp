#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");
    FragTrap frag("FR4G-TP");
    
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();
    
    frag.attack("Boss");
    frag.takeDamage(25);
    frag.beRepaired(20);
    frag.highFivesGuys();
    
    return 0;
}
