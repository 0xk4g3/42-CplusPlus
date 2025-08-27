#ifndef SHRUBBERYCREATIONFORM_HPP

#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
  const std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
  void execute(const Bureaucrat &bureaucrat) const;
  ~ShrubberyCreationForm();
};

#endif
