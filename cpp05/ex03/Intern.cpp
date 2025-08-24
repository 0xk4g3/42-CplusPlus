#include "Intern.hpp"

const Intern::FormInfo Intern::availableForm[3] = {
    {"shrubbery creation", &Intern::createShrubberyForm},
    {"robotomy request", &Intern::createRobotomyForm},
    {"presidential pardon", &Intern::createPardonForm}

};

Intern::Intern() { std::cout << "Intern hired" << std::endl; }

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "Intern copy hired" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  (void)other; 
  return *this;
}

Intern::~Intern() { std::cout << "Intern fired" << std::endl; }

AForm *Intern::createShrubberyForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}
AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {

  for (int i = 0; i < 3; i++) {

    if (formName == availableForm[i].name) {

      std::cout << "Inter Creates" << formName << std::endl;
      return availableForm[i].creator(target);
    }
  }
  std::cout << "Error: Unknow form type" << std::endl;
  return NULL;
}
