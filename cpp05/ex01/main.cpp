#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
  std::cout << "=== Testing valid form creation ===" << std::endl;
  try {
    Form taxForm("Tax Form", 50, 25);
    std::cout << taxForm << std::endl;

    Form easyForm("Easy Form", 150, 150);
    std::cout << easyForm << std::endl;

    Form hardForm("Hard Form", 1, 1);
    std::cout << hardForm << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing invalid form grades: too high ===" << std::endl;
  try {
    Form invalidForm("Invalid Form", 0, 50);
    std::cout << invalidForm << std::endl;
  } catch (Form::GradeTooHighException &e) {
    std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing invalid form grades: too low ===" << std::endl;
  try {
    Form invalidForm("Invalid Form", 151, 50);
    std::cout << invalidForm << std::endl;
  } catch (Form::GradeTooLowException &e) {
    std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing invalid execute grades ===" << std::endl;
  try {
    Form invalidForm("Invalid Form", 50, 200);
    std::cout << invalidForm << std::endl;
  } catch (Form::GradeTooLowException &e) {
    std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing successful form signing ===" << std::endl;
  try {
    Bureaucrat highRank("CEO", 10);
    Form importantForm("Important Form", 20, 15);

    std::cout << "Before signing: " << importantForm << std::endl;
    highRank.signForm(importantForm);
    std::cout << "After signing: " << importantForm << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing failed form signing: grade too low ==="
            << std::endl;
  try {
    Bureaucrat lowRank("Intern", 100);
    Form secretForm("Secret Form", 50, 25);

    std::cout << "Before signing attempt: " << secretForm << std::endl;
    lowRank.signForm(secretForm);
    std::cout << "After signing attempt: " << secretForm << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing edge case: exact grade match ===" << std::endl;
  try {
    Bureaucrat exactGrade("Manager", 75);
    Form matchingForm("Matching Form", 75, 50);

    std::cout << "Before signing: " << matchingForm << std::endl;
    exactGrade.signForm(matchingForm);
    std::cout << "After signing: " << matchingForm << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing multiple signings of same form ===" << std::endl;
  try {
    Bureaucrat signer1("First Signer", 30);
    Bureaucrat signer2("Second Signer", 20);
    Form multiForm("Multi Form", 40, 30);

    std::cout << "Initial state: " << multiForm << std::endl;
    signer1.signForm(multiForm);
    std::cout << "After first signing: " << multiForm << std::endl;
    signer2.signForm(multiForm);
    std::cout << "After second signing: " << multiForm << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing form copy and assignment ===" << std::endl;
  try {
    Form original("Original Form", 60, 40);
    Bureaucrat signer("Signer", 50);

    signer.signForm(original);
    std::cout << "Original after signing: " << original << std::endl;

    Form copy(original);
    std::cout << "Copy: " << copy << std::endl;

    Form assigned("Temp", 100, 80);
    std::cout << "Before assignment: " << assigned << std::endl;
    assigned = original;
    std::cout << "After assignment: " << assigned << std::endl;

  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing with invalid bureaucrat grades ===" << std::endl;
  try {
    Bureaucrat invalidBureaucrat("Invalid", 0);
    Form testForm("Test Form", 50, 30);
    invalidBureaucrat.signForm(testForm);
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "Caught Bureaucrat exception: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing boundary values ===" << std::endl;
  try {
    Form boundary1("Boundary Form 1", 1, 150);
    Form boundary2("Boundary Form 2", 150, 1);

    Bureaucrat topBureaucrat("Top", 1);
    Bureaucrat bottomBureaucrat("Bottom", 150);

    std::cout << boundary1 << std::endl;
    std::cout << boundary2 << std::endl;

    topBureaucrat.signForm(boundary1);
    topBureaucrat.signForm(boundary2);

    bottomBureaucrat.signForm(boundary1);
    bottomBureaucrat.signForm(boundary2);

  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Program completed successfully ===" << std::endl;
  return 0;
}
