#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>
#include <string>

class ICharacter;

class AMateria{
    
        protected:
            std::string  type;
        public:
             AMateria();
              virtual ~AMateria();
             // TODO: Dont forget  call the decounstrecter
             AMateria(std::string const &type);
             AMateria(const AMateria& other);
             AMateria& operator=(const AMateria &other);
             std::string const & getType() const;  // NOTE: Return the materia type
             virtual AMateria* clone() const = 0;
             virtual void use(ICharacter&target);
    
};




#endif
