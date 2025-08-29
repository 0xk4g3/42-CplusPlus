
#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm()
    : _name("Default"), _signed(false), _grade_sign(10), _grade_execute(25) {

  std::cout << "Constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int grade_sign,
             const int grade_execute)
    : _name(name), _signed(false), _grade_sign(grade_sign),
      _grade_execute(grade_execute) {

  if (grade_sign < 1)
    throw GradeTooHighException();
  else if (grade_sign > 150)
    throw GradeTooLowException();
  if (grade_execute < 1)
    throw GradeTooHighException();
  else if (grade_execute > 150)
    throw GradeTooLowException();

  std::cout << "AForm " << _name << " created" << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed),
      _grade_sign(other._grade_sign), _grade_execute(other._grade_execute) {

  std::cout << "copy constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {

  if (this != &other)
    _signed = other._signed;

  return (*this);
}

std::string AForm::getName() const { return (_name); }
bool AForm::getIsSigned() const { return (_signed); }
int AForm::getGradeSign() const { return (_grade_sign); }
int AForm::getGradeExecute() const { return (_grade_execute); }

const char *AForm::GradeTooHighException::what() const throw() {
  return "Bureaucrat grade too high to sign this form";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade too low to sign this form";
}
void AForm::beSigned(const Bureaucrat &Bureaucrat) {

  if (Bureaucrat.getGrade() > _grade_sign)
    throw GradeTooLowException();
  _signed = true;
}

const char *AForm::TheTargetNotSigned::what() const throw() {

  return "Form is not signed";
}

AForm::~AForm() { std::cout << "Decontructor" << std::endl; }

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  out << "AForm " << form.getName()
      << ", signed: " << (form.getIsSigned() ? "yes" : "no")
      << ", grade to sign: " << form.getGradeSign()
      << ", grade to execute: " << form.getGradeExecute();
  return out;
}
