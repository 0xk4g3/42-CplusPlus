

#include "Zombie.hpp"


Zombie::Zombie(){};




void Zombie::announce(){
      
      std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name){
      _name = name;
}
Zombie::~Zombie(){
    std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}
