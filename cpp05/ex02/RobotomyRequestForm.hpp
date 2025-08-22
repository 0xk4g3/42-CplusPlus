#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm {
private:
  const std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
  // TODO:
  void execute(const Bureaucrat &executor) const;
  ~RobotomyRequestForm();
};

#endif
