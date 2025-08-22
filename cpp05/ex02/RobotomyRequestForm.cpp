#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Roboto", 72, 45) {
  std::cout << "Constroctur Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Roboto", 72, 45), _target(target) {

  std::cout << "constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target) {

  std::cout << "cpy constructor " << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {

  if (this != &src) {
    AForm::operator=(src);
  }
  return (*this);
}
/* --------------------------
  TODO: :
    1) we need to check the exceptions the correct message they need to throw
  FIXME:  also check the   other cases must be
-----------------------*/
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {

  if (!this->getIsSigned())
    throw AForm::TheTargetNotSigned();
  if (executor.getGrade() > this->getGradeExecute())
    throw AForm::GradeTooLowException();
  std::cout << "* BZZZZT * DRILL DRILL DRILL *" << std::endl;
  std::srand(std::time(0));
  int result = std::rand() % 2;
  if (result == 1) {
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "Robotomy failed on " << _target << std::endl;
  }
}
RobotomyRequestForm::~RobotomyRequestForm() {

  std::cout << "deconstructor  called " << std::endl;
}
