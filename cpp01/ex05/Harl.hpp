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
     Harl(const Harl& other);  
     Harl& operator=(const Harl& other);
     void complain(std::string level);
};

#endif