

#include "Zombie.hpp"


Zombie::Zombie(std::string ZombieName):_name(ZombieName.empty() ? "Unnamed" : ZombieName){};


void Zombie::announce(){
      
      std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie(){
    std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}
