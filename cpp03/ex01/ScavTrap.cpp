

#include "ScavTrap.hpp"



ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
     
      this->_HitPoint = 100;
    this->_EnergyPoint = 50;
    this->_AttackDemage = 20;
    
    std::cout << "ScavTrap Constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src){ 
       std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
     

    if(this != &src)
       ClapTrap::operator=(src);
    
    std::cout << "ScavTrap assignment Constructor called" << std::endl;

        return *this;

}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called for " << this->_Name << std::endl;
}



void ScavTrap::attack(const std::string& target) {
    if (_EnergyPoint > 0 && _HitPoint > 0) {
        _EnergyPoint--;
        std::cout << "ScavTrap " << _Name << " viciously attacks " << target 
                  << ", causing " << _AttackDemage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _Name << " is too exhausted to attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode!" << std::endl;
}
