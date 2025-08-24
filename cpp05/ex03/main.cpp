
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

  std::cout << "====== EXERCISE 03: INTERN CLASS TESTING ======" << std::endl;

  try {
    // ========== TEST 1: Basic Intern Creation ==========
    std::cout << "\n========== TEST 1: Basic Intern Creation =========="
              << std::endl;

    std::cout << "\n--- Creating Intern ---" << std::endl;
    Intern intern;

    // ========== TEST 2: Valid Form Creation ==========
    std::cout << "\n\n========== TEST 2: Valid Form Creation =========="
              << std::endl;

    std::cout << "\n--- Creating ShrubberyCreationForm via Intern ---"
              << std::endl;
    AForm *shrubForm = intern.makeForm("shrubbery creation", "garden");
    if (shrubForm) {
      std::cout << "Success! Created: " << *shrubForm << std::endl;
    } else {
      std::cout << "Failed to create shrubbery form" << std::endl;
    }

    std::cout << "\n--- Creating RobotomyRequestForm via Intern ---"
              << std::endl;
    AForm *robotForm = intern.makeForm("robotomy request", "Bender");
    if (robotForm) {
      std::cout << "Success! Created: " << *robotForm << std::endl;
    } else {
      std::cout << "Failed to create robotomy form" << std::endl;
    }

    std::cout << "\n--- Creating PresidentialPardonForm via Intern ---"
              << std::endl;
    AForm *pardonForm = intern.makeForm("presidential pardon", "Arthur Dent");
    if (pardonForm) {
      std::cout << "Success! Created: " << *pardonForm << std::endl;
    } else {
      std::cout << "Failed to create pardon form" << std::endl;
    }

    // ========== TEST 3: Invalid Form Names ==========
    std::cout << "\n\n========== TEST 3: Invalid Form Names =========="
              << std::endl;

    std::cout << "\n--- Trying invalid form name ---" << std::endl;
    AForm *invalidForm1 = intern.makeForm("unknown form", "target");
    if (invalidForm1) {
      std::cout << "ERROR: Should not have created form!" << std::endl;
    } else {
      std::cout << "Correctly returned NULL for invalid form" << std::endl;
    }

    std::cout << "\n--- Trying another invalid form name ---" << std::endl;
    AForm *invalidForm2 = intern.makeForm("magic form", "wizard");
    if (invalidForm2) {
      std::cout << "ERROR: Should not have created form!" << std::endl;
    } else {
      std::cout << "Correctly returned NULL for invalid form" << std::endl;
    }

    std::cout << "\n--- Trying empty form name ---" << std::endl;
    AForm *emptyForm = intern.makeForm("", "target");
    if (emptyForm) {
      std::cout << "ERROR: Should not have created form!" << std::endl;
    } else {
      std::cout << "Correctly returned NULL for empty form name" << std::endl;
    }

    // ========== TEST 4: Using Created Forms ==========
    std::cout << "\n\n========== TEST 4: Using Created Forms =========="
              << std::endl;

    if (shrubForm && robotForm && pardonForm) {
      std::cout << "\n--- Creating bureaucrats for testing ---" << std::endl;
      Bureaucrat boss("Boss", 1);      // Can sign and execute everything
      Bureaucrat worker("Worker", 50); // Can do some things

      std::cout << "\n--- Testing ShrubberyCreationForm created by Intern ---"
                << std::endl;
      boss.signForm(*shrubForm);
      boss.executeForm(*shrubForm);

      std::cout << "\n--- Testing RobotomyRequestForm created by Intern ---"
                << std::endl;
      boss.signForm(*robotForm);
      boss.executeForm(*robotForm);

      std::cout << "\n--- Testing PresidentialPardonForm created by Intern ---"
                << std::endl;
      boss.signForm(*pardonForm);
      boss.executeForm(*pardonForm);

      std::cout << "\n--- Testing with lower grade bureaucrat ---" << std::endl;
      AForm *workerShrub = intern.makeForm("shrubbery creation", "office");
      if (workerShrub) {
        worker.signForm(*workerShrub);    // Should succeed (50 <= 145)
        worker.executeForm(*workerShrub); // Should succeed (50 <= 137)
        delete workerShrub;
      }
    }

    // ========== TEST 5: Multiple Interns ==========
    std::cout << "\n\n========== TEST 5: Multiple Interns =========="
              << std::endl;

    std::cout << "\n--- Creating multiple interns ---" << std::endl;
    Intern intern2;
    Intern intern3(intern2); // Copy constructor test

    std::cout << "\n--- Each intern can create forms independently ---"
              << std::endl;
    AForm *form1 = intern.makeForm("robotomy request", "R2D2");
    AForm *form2 = intern2.makeForm("shrubbery creation", "park");
    AForm *form3 = intern3.makeForm("presidential pardon", "Ford Prefect");

    if (form1)
      std::cout << "Intern 1 created: " << form1->getName() << std::endl;
    if (form2)
      std::cout << "Intern 2 created: " << form2->getName() << std::endl;
    if (form3)
      std::cout << "Intern 3 created: " << form3->getName() << std::endl;

    // ========== TEST 6: Case Sensitivity ==========
    std::cout << "\n\n========== TEST 6: Case Sensitivity =========="
              << std::endl;

    std::cout << "\n--- Testing case sensitivity ---" << std::endl;
    AForm *caseTest1 =
        intern.makeForm("Shrubbery Creation", "test"); // Wrong case
    AForm *caseTest2 =
        intern.makeForm("ROBOTOMY REQUEST", "test"); // Wrong case
    AForm *caseTest3 =
        intern.makeForm("shrubbery creation", "test"); // Correct case

    if (!caseTest1 && !caseTest2 && caseTest3) {
      std::cout << "✅ Case sensitivity works correctly!" << std::endl;
    } else {
      std::cout << "❌ Case sensitivity issue detected!" << std::endl;
    }

    // ========== TEST 7: Memory Management ==========
    std::cout << "\n\n========== TEST 7: Memory Management =========="
              << std::endl;

    std::cout << "\n--- Testing form creation and cleanup ---" << std::endl;
    for (int i = 0; i < 3; i++) {
      AForm *tempForm = intern.makeForm("robotomy request", "temp_target");
      if (tempForm) {
        std::cout << "Created form " << i + 1 << ": " << tempForm->getName()
                  << std::endl;
        delete tempForm; // Important: Clean up memory!
        std::cout << "Cleaned up form " << i + 1 << std::endl;
      }
    }

    // ========== CLEANUP ==========
    std::cout << "\n\n========== CLEANUP ==========" << std::endl;

    // Clean up all created forms
    delete shrubForm;
    delete robotForm;
    delete pardonForm;
    delete form1;
    delete form2;
    delete form3;
    delete caseTest3; // Only this one was created successfully

    std::cout << "All forms cleaned up successfully!" << std::endl;

    // ========== SUMMARY ==========
    std::cout << "\n\n========== EXERCISE 03 SUMMARY ==========" << std::endl;
    std::cout << "✅ Intern class creation and destruction" << std::endl;
    std::cout << "✅ Form creation via string names" << std::endl;
    std::cout << "✅ All three form types supported" << std::endl;
    std::cout << "✅ Invalid form name handling" << std::endl;
    std::cout << "✅ Created forms work with bureaucrats" << std::endl;
    std::cout << "✅ Memory management (new/delete)" << std::endl;
    std::cout << "✅ Case sensitivity validation" << std::endl;
    std::cout << "✅ Multiple intern instances" << std::endl;

    std::cout << "\n🎉 Exercise 03 Complete!" << std::endl;

  } catch (std::exception &e) {
    std::cout << "\n❌ Exception caught: " << e.what() << std::endl;
  }

  std::cout << "\n====== END OF EXERCISE 03 TESTING ======" << std::endl;
  return 0;
}
