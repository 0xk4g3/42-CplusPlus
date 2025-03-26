


#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap{ 
            
        protected:
            std::string _Name;
            unsigned int _HitPoint;
            unsigned int _EnergyPoint;
            unsigned int  _AttackDemage;
        public:
            ClapTrap(std::string name);
            /* Strat of the orthodox */
            ClapTrap(const ClapTrap &src);
            ClapTrap& operator=(const ClapTrap &src);
            /* end of the orthodos */
            void attack(const std::string& target);
           void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);
            
            ~ClapTrap();
};






#endif
