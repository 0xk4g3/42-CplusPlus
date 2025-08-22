#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5) {
  std::cout << "Constroctur Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("presidential pardon", 25, 5), _target(target) {

  std::cout << "constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src), _target(src._target) {

  std::cout << "cpy constructor " << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {

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
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {

  if (!this->getIsSigned())
    throw AForm::TheTargetNotSigned();
  if (executor.getGrade() > this->getGradeExecute())
    throw AForm::GradeTooLowException();
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() {

  std::cout << "deconstructor  called " << std::endl;
}
