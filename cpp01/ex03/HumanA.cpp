#include "./HumanA.hpp"
#include "Weapon.hpp"




HumanA::HumanA(std::string human , Weapon& weapon):name(human) , weapon(weapon){

}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}