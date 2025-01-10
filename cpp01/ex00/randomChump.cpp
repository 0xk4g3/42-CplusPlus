

#include "Zombie.hpp"



void randomChump(std::string name){
     if (name.empty()) 
        name = "Unnamed"; 
    
    Zombie Nzombie(name);

    Nzombie.announce();
}