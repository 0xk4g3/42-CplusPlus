#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {

private:
  typedef AForm *(*FormCreator)(const std::string &target);
  static AForm *createShrubberyForm(const std::string &target);

  static AForm *createRobotomyForm(const std::string &target);
  static AForm *createPardonForm(const std::string &target);

  struct FormInfo {
    const char *name;
    FormCreator creator;
  };
  static const FormInfo availableForm[3];

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
