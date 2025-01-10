

#include "Zombie.hpp"






Zombie *newZombie(std::string name){ 
      if (name.empty()) 
        name = "Unnamed"; 
    
     Zombie *Nzombie = new Zombie(name);
    return Nzombie;
}

