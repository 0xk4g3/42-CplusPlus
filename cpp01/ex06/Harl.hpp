#ifndef HARL_HPP
#define HARL_HPP    


#include <iostream>
#include <cstring>


class Harl{
     
     private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
     public:
     Harl(void);
     ~Harl(void);
     Harl(const Harl& other);  // make copy constructor 
     Harl& operator=(const Harl& other); // coppay assignment operator
     void complain(std::string level);
};

#endif