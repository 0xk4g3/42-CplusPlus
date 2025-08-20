#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery creation", 145, 137), _target("Default") {

  std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

beryCreationForm(const std::string &target)
    : AForm("shrubbery creation", 145, 137), , _target(target) {

  std::cout << "ShrubberyCreationForm parameterized constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {

  std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {

  if (this != &src) {

    Form::operator=(src);
  }
  return *this;
}
void ShrubberyCreationForm::execute(const Bureaucrat &src) const {

  if (!this->getIsSigned())
    throw AForm::TheTargetNotSigned();
  if (src.getGrade() > this->getGradeExecute())
    throw AForm::GradeTooLowException();
  std::ofstream shrubberyFile(_target + "_shrubbery.txt");
  if (shrubberyFile.is_open()) {

    shrubberyFile << "         /\\" << std::endl;
    shrubberyFile << "        /  \\" << std::endl;
    shrubberyFile << "       /____\\" << std::endl;
    shrubberyFile << "      /      \\" << std::endl;
    shrubberyFile << "     /        \\" << std::endl;
    shrubberyFile << "    /          \\" << std::endl;
    shrubberyFile << "   /____________\\" << std::endl;
    shrubberyFile << "  /              \\" << std::endl;
    shrubberyFile << " /________________\\" << std::endl;
    shrubberyFile << "        ||||" << std::endl;
    shrubberyFile << "        ||||" << std::endl;
    shrubberyFile << "        ||||" << std::endl;
  } else {
    throw std::exception();
  }
}
ShrubberyCreationForm::~ShrubberyCreationForm() {

  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
