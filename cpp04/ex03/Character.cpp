#include "Character.hpp"





Character::Character(): name(""){
     
    for(int i = 0 ; i < 4 ; i++){
         inventory[i] = NULL;
    }
     std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const & name ) : name(name){ 
        
            for(int i = 0 ; i < 4 ; i++){
                 
                inventory[i] = NULL;
            }
      std::cout << "Character named constructor called" << std::endl;
}

Character::Character(const Character& other ) : name(other.name){

        std::cout << "Character copy constructor called" << std::endl;
       
        for(int i = 0; i < 4 ; i++){
             this->inventory[i] = NULL;
        }
        for(int i = 0  ; i < 4 ; i++){
             if(other.inventory[i]){
                  this->inventory[i] = other.inventory[i]->clone();
             }
        }
}

Character::~Character(){
     std::cout << "Character destructor called" << std::endl;

     for(int i = 0 ; i < 4 ; i++){
          
         if(inventory[i]){
            delete inventory[i];
         }
     }
}



Character& Character::operator=(const Character& other){
     
        std::cout << "Character assignment operator called" << std::endl;

        if(this != &other){
             
            this->name = other.name;
            for(int i = 0; i < 4 ; i++){
                 if(this->inventory[i]){
                      delete this->inventory[i];
                      this->inventory[i] = NULL;
                 }
            }
            for(int i = 0 ; i < 4 ; i++){ 
               if(other.inventory[i]){
                    this->inventory[i] = other.inventory[i]->clone();
               }
            }
        }
        return *this;
}



//HACK:: The interface implementation 

std::string const & Character::getName() const { 

    return this->name;
}

void Character::equip(AMateria * m){ 
    
    if(!m){
        return ;
    }
    for(int i =0 ; i < 4 ; i++){ 
        if(inventory[i] == NULL){
             inventory[i]= m; 
             std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
             return;
        }       
    }
      std::cout << name << " has no empty slots to equip " << m->getType() << std::endl;
}
void Character::unequip(int idx) {
    if(idx < 0 || idx >= 4) { 
         std::cout << "Invalid slot index: " << idx << std::endl;
        return;
    }
    if(inventory[idx]) {
          std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
        inventory[idx] = NULL; // You set to NULL but don't return the pointer
    } else {
        std::cout << "No materia in slot " << idx << " to unequip" << std::endl; 
    }
}
void Character::use(int idx , ICharacter & target){
     if(idx < 0 || idx >= 4){
        
         std::cout << "Invalid slot index: " << idx << std::endl;
         return;
    }  
    
     if(inventory[idx]){
           inventory[idx]->use(target);
     }else{
       std::cout << "No materia in slot " << idx << " to use" << std::endl;
     }

}
AMateria* Character::getMateria(int idx) const {
    if (idx >= 0 && idx < 4) {
        return inventory[idx];
    }
    return NULL;
}
