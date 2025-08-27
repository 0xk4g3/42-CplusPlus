#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
// => {  yeh it' the sam e$:}
class RobotomyRequestForm : public AForm {
private:
  const std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
  ~RobotomyRequestForm();
};

#endif
