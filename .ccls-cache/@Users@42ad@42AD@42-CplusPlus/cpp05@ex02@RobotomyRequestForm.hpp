#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

public:
   RobotomyRequestForm();
   RobotomyRequestForm(const std::string& target);
   RobotomyRequestForm(const RobotomyRequestForm& src);
   RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
    ~RobotomyRequestForm(); 
};

#endif
