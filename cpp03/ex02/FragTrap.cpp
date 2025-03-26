





#include "FragTrap.hpp"




FragTrap::FragTrap(std::string name):ClapTrap(name){
     
    this->_HitPoint = 100;
    this->_EnergyPoint = 100;
    this->_AttackDemage = 30;

    std::cout << "FragTrap Constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap  &src): ClapTrap(src){
    
       std::cout << "FragTrap  copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src){
     
    if(this != &src)
        ClapTrap::operator=(src);
    std::cout << "FragTrap  assignment  Constructor called" << std::endl;
    
    return *this;
}
void FragTrap::attack(const std::string& target) {
    if (_EnergyPoint > 0 && _HitPoint > 0) {
        _EnergyPoint--;
        std::cout << "FragTrap " << _Name << " viciously attacks " << target 
                  << ", causing " << _AttackDemage << " points of damage!" << std::endl;
    } else {
        std::cout << "FragTrap " << _Name << " is too exhausted to attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _Name << " enthusiastically requests high fives from everyone!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called for " << this->_Name << std::endl;
}





