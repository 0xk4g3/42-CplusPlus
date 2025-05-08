#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"





class Character : public ICharacter{
        private: 
            std::string name;
            AMateria* inventory[4];
        public: 
            Character();
            Character(std::string const & name);
            virtual ~Character();
            Character(const Character& other);
            Character& operator=(const Character& other);
            AMateria* getMateria(int idx) const;
          
            // NOTE: * here start ICharacter interface method -- 
           virtual std::string const & getName() const;
           virtual void equip(AMateria* m) ;
           virtual void  unequip(int idx) ; 
           virtual void use(int idx, ICharacter& target) ;
};

#endif
