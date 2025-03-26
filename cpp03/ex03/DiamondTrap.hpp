
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP


#include "FragTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap{
        private:
            std::string _name;
        public:
         DiamondTrap(std::string name);
         DiamondTrap(const DiamondTrap &src);
         DiamondTrap& operator=(const DiamondTrap &src);
         void attack(const std::string &target);
         void whoAmI();
         ~DiamondTrap(); 

};

#endif
