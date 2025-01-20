
#include "./HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string human):name(human) , weapon(NULL){

}

HumanB::~HumanB(){};


void HumanB::attack(){ 
    if(weapon)
         std::cout << name << " attacks with their " << weapon->getType() << std::endl;

}

void HumanB::setWeapon(Weapon& weapon){
     this->weapon = &weapon;
}