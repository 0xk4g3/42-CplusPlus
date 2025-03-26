
#include "ClapTrap.hpp"

 

//init the Constructor

ClapTrap::ClapTrap(std::string name):_Name(name),_HitPoint(10),_EnergyPoint(10),_AttackDemage(0){
    
    std::cout << "ClapTrap Constructor called for " << name  << std::endl;

}


ClapTrap::ClapTrap(const ClapTrap &src){ 
    std::cout << "The copy constructor called"  << std::endl;
    this->_Name = src._Name;
    this->_EnergyPoint = src._EnergyPoint;
    this->_AttackDemage = src._AttackDemage;
    this->_HitPoint = src._HitPoint;

}



ClapTrap &ClapTrap::operator=(const ClapTrap &src){
        
    std::cout << "The assigment operator called " << std::endl;
        if(this != &src)
        {
         this->_Name = src._Name;
         this->_EnergyPoint = src._EnergyPoint;
         this->_AttackDemage = src._AttackDemage;
         this->_HitPoint = src._HitPoint;
         }
        return *this;
}

// NOTE: THE REPAIR  AND THE ATATCK IT'S TAKE 1 POINT FROM THE  HIT Point
//
// // HACK:  OF COURSE THE CLAP CAN DO ANYTHING WHNE  NO POINT LEFT i

void ClapTrap::attack(const std::string& target){
    
     
     if(_EnergyPoint > 0 || _HitPoint > 0 ){
         _EnergyPoint--;
           std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _AttackDemage << " points of damage!" << std::endl;
     }else{

        std::cout << "ClapTrap " << _Name << " can't attack: no energy or hit points left!" << std::endl;
     }


}


void ClapTrap::takeDamage(unsigned int amount){ 
  
     if(_HitPoint <= amount)
        _HitPoint =0;
     else 
        _HitPoint -= amount;
 
     std::cout << "ClapTrap " << _Name << " takes " << amount << " points of damage! Hit points remaining: " << _HitPoint << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount){
    
       if(this->_HitPoint == 0 || this->_EnergyPoint == 0)
        std::cout << "ClapTrap " << _Name << " can't repair: no energy or hit points left!" << std::endl;
       else 
         {
            _EnergyPoint--;
            this->_HitPoint += amount;
         std::cout << "ClapTrap " << _Name << " repaired itself, gaining " << amount << " hit points! Hit points now: " << _HitPoint << std::endl;
         }
}


ClapTrap::~ClapTrap(){

     std::cout << "ClapTrap Destructor called for "  << _Name << std::endl;
 
}







