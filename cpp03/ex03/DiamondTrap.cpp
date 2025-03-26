
#include "./DiamondTrap.hpp"






DiamondTrap::DiamondTrap(std::string name):
    ClapTrap(name + "_clap_name"),
    FragTrap(name),
    ScavTrap(name),
    _name(name)
{
    this->_AttackDemage = FragTrap::_AttackDemage;
    this->_EnergyPoint =  ScavTrap::_EnergyPoint;
    this->_HitPoint = FragTrap::_HitPoint;
std::cout << "DiamondTrap Constructor called for " << name << std::endl;
}



DiamondTrap::DiamondTrap(const DiamondTrap &src):ClapTrap(src),FragTrap(src),ScavTrap(src),_name(src._name){
     
    std::cout <<  "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
      
    if(this != &src)
    {
        ClapTrap::operator=(src);
        ScavTrap::operator=(src);
        FragTrap::operator=(src);
        _name =  src._name;
        
    }
        std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
    
    
}
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_Name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called for " << _name << std::endl;
}
