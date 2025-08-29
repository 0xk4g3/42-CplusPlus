

#include "Bureaucrat.hpp"

int main() {

  std::cout << "=== Testing valid bureaucrats ===" << std::endl;
  try {
    Bureaucrat ceo("CEO", 1);
    std::cout << ceo << std::endl;

    Bureaucrat manager("Manager", 75);
    std::cout << manager << std::endl;

    Bureaucrat intern("Intern", 150);
    std::cout << intern << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing invalid grade: too high (0) ===" << std::endl;
  try {
    Bureaucrat superman("Superman", 0);
    std::cout << superman << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing invalid grade: too low (200) ===" << std::endl;
  try {
    Bureaucrat nobody("Nobody", 200);
    std::cout << nobody << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Caught other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing grade increment (promotion) ===" << std::endl;
  try {
    Bureaucrat worker("Worker", 5);
    std::cout << "Before: " << worker << std::endl;

    for (int i = 0; i < 3; i++) {
      worker.incrementGrade();
      std::cout << "After increment: " << worker << std::endl;
    }

    worker.incrementGrade();
    worker.incrementGrade();

  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception during increment: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing grade decrement (demotion) ===" << std::endl;
  try {
    Bureaucrat assistant("Assistant", 148);
    std::cout << "Before: " << assistant << std::endl;

    for (int i = 0; i < 2; i++) {
      assistant.decrementGrade();
      std::cout << "After decrement: " << assistant << std::endl;
    }

    assistant.decrementGrade();
    assistant.decrementGrade();

  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception during decrement: " << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Other exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing copy and assignment ===" << std::endl;
  try {
    Bureaucrat original("Original", 42);
    std::cout << "Original: " << original << std::endl;

    Bureaucrat copy(original);
    std::cout << "Copy: " << copy << std::endl;

    Bureaucrat assigned("TempName", 100);
    std::cout << "Before assignment: " << assigned << std::endl;
    assigned = original;
    std::cout << "After assignment: " << assigned << std::endl;

  } catch (std::exception &e) {
    std::cout << "Exception in copy/assignment: " << e.what() << std::endl;
  }

  std::cout << "\n=== Testing edge cases ===" << std::endl;
  try {
    // Test minimum and maximum valid grades
    Bureaucrat topGrade("TopGrade", 1);
    Bureaucrat bottomGrade("BottomGrade", 150);

    std::cout << topGrade << std::endl;
    std::cout << bottomGrade << std::endl;

    try {
      topGrade.incrementGrade();
    } catch (Bureaucrat::GradeTooHighException &e) {
      std::cout << "Can't promote top grade: " << e.what() << std::endl;
    }

    try {
      bottomGrade.decrementGrade();
    } catch (Bureaucrat::GradeTooLowException &e) {
      std::cout << "Can't demote bottom grade: " << e.what() << std::endl;
    }

  } catch (std::exception &e) {
    std::cout << "Exception in edge cases: " << e.what() << std::endl;
  }

  std::cout << "\n=== Program completed successfully ===" << std::endl;
  return 0;
}
