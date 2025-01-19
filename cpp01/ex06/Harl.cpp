

#include "./Harl.hpp"


#include "./Harl.hpp"


Harl::Harl(void) {}
Harl::~Harl(void) {}


void Harl::debug(void) {
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! "
              << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started "
              << "working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! "
              << "I want to speak to the manager now." << std::endl;
}
int findLevel(std::string input){ 

    std::string levels[] = {
          "DEBUG",
          "INFO",
          "WARNING",
          "ERROR"
      };
      for(int i = 0; i <  4 ; i++){
        if(input == levels[i])
            return i;
      }
    
    return -1;
}
void Harl::complain(std::string level){
     void(Harl::*funcs[])() = {
         &Harl::debug , 
         &Harl::info,
         &Harl::warning , 
         &Harl::error
         };
         
        int InputLevel = findLevel(level);
        
     
        switch (InputLevel) {
                case 0:
                    std::cout <<"[ DEBUG ]" << std::endl;
                    (this->*funcs[0])();
                    __attribute__((fallthrough));
                case 1:
                    std::cout <<"[ INFO ]" << std::endl;
                    (this->*funcs[1])();
                      __attribute__((fallthrough));
                   
                case 2:
                    std::cout <<"[ WARNING ]" << std::endl;
                    (this->*funcs[2])();
                      __attribute__((fallthrough));
                   
                case 3:
                    std::cout <<"[ ERROR ]" << std::endl;
                    (this->*funcs[3])();
                    break;
                default :
                 std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
              
        }

     
}
Harl& Harl::operator=(const Harl& other){
      
      if (this != &other) 
        (void)other;       
     return *this;


}

Harl::Harl(const Harl& other){
     
     (void)other;
}