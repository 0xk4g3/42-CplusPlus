#ifndef HUMANA_HPP 
#define HUMANA_HPP 

#include <cstring>
#include <iostream>
#include <string>

#include "Weapon.hpp"
class HumanA{ 
    private:
         std::string name;
         Weapon& weapon;
    public:
    HumanA(std::string human , Weapon& weapon);
    void attack(void);
};


#endif