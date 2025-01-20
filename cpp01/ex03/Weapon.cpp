#include "./Weapon.hpp"




Weapon::Weapon(std::string init_type) : type(init_type) {};
Weapon::~Weapon(){};

const std::string& Weapon::getType() const{
    return type;
}


void Weapon::setType(std::string newType){
      type = newType;
}