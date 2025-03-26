#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ScavTrap.hpp"


class FragTrap : public ClapTrap {
    
        public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        FragTrap &operator=(const FragTrap &src);
        void attack(const std::string &traget);
        void highFivesGuys(void);
        ~FragTrap();

};

#endif
