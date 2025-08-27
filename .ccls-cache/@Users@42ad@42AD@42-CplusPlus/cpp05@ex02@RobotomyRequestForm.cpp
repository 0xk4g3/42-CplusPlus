#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("Deafutl",23,32){ 
    std::cout << "Constroctur Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm(_target,2,2){ 

    std::cout  << "constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):AForm::AForm(src){

    std::cout << "cpy constructor " << std::endl;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm src){ 
    
    if(this != &src) {
        AForm::operator=(src);
    }
    return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm() {

    std::cout << "deconstructor  called " <<std::endl;
} 
