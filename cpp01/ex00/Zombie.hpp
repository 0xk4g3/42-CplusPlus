

#ifndef    ZOMBIE_HPP
# define  ZOMBIE_HPP

#include <cstdio>
#include <iostream>

class Zombie {

    private:
    std::string _name;   

    public:
     Zombie(std::string ZombieName);
     void announce();
     ~Zombie();


};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif