

#ifndef    ZOMBIE_HPP
# define  ZOMBIE_HPP
#define N 4



#include <iostream>

class Zombie {

    private:
    std::string _name;   

    public:
     void SetName(std::string name);
     Zombie();
     void announce();
     ~Zombie();


};

Zombie* zombieHorde(int n, std::string name);

#endif

