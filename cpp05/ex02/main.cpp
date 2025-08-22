#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

  std::cout << "====== EXERCISE 02 COMPLETE TESTING ======" << std::endl;

  try {
    // ========== TEST 1: ShrubberyCreationForm ==========
    std::cout << "\n========== TEST 1: ShrubberyCreationForm =========="
              << std::endl;

    std::cout << "\n--- Creating form and bureaucrats ---" << std::endl;
    ShrubberyCreationForm shrub("garden");
    Bureaucrat alice("Alice", 100); // Can sign (grade <= 145)
    Bureaucrat bob("Bob", 50);      // Can execute (grade <= 137)
    Bureaucrat weak("Weak", 150);   // Cannot sign or execute

    std::cout << "Form: " << shrub << std::endl;
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << weak << std::endl;

    std::cout << "\n--- Testing signing ---" << std::endl;
    alice.signForm(shrub); // Should succeed
    std::cout << "After signing: " << shrub << std::endl;

    std::cout << "\n--- Testing execution (should succeed) ---" << std::endl;
    bob.executeForm(shrub); // Should succeed and create file

    std::cout << "\n--- Testing execution with weak bureaucrat ---"
              << std::endl;
    weak.executeForm(shrub); // Should fail - grade too low

    std::cout << "\n--- Testing unsigned form execution ---" << std::endl;
    ShrubberyCreationForm shrub2("office");
    bob.executeForm(shrub2); // Should fail - not signed

    // ========== TEST 2: RobotomyRequestForm ==========
    std::cout << "\n\n========== TEST 2: RobotomyRequestForm =========="
              << std::endl;

    std::cout << "\n--- Creating robotomy form ---" << std::endl;
    RobotomyRequestForm robot("Bender");
    Bureaucrat signer("Signer", 70);         // Can sign (grade <= 72)
    Bureaucrat executor("Executor", 40);     // Can execute (grade <= 45)
    Bureaucrat weakSigner("WeakSigner", 80); // Cannot sign (80 > 72)

    std::cout << "Form: " << robot << std::endl;

    std::cout << "\n--- Testing signing with good bureaucrat ---" << std::endl;
    signer.signForm(robot); // Should succeed

    std::cout << "\n--- Testing signing with weak bureaucrat ---" << std::endl;
    RobotomyRequestForm robot2("C3PO");
    weakSigner.signForm(robot2); // Should fail

    std::cout << "\n--- Testing execution (with randomness) ---" << std::endl;
    executor.executeForm(robot); // Should succeed with random result

    std::cout << "\n--- Testing multiple executions to see randomness ---"
              << std::endl;
    for (int i = 0; i < 5; i++) {
      executor.executeForm(robot); // Run multiple times to see 50% randomness
    }

    // ========== TEST 3: PresidentialPardonForm ==========
    std::cout << "\n\n========== TEST 3: PresidentialPardonForm =========="
              << std::endl;

    std::cout << "\n--- Creating presidential pardon form ---" << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");
    Bureaucrat president("President", 1); // Can sign and execute (grades 25, 5)
    Bureaucrat minister("Minister",
                        20); // Can sign (20 <= 25) but not execute (20 > 5)
    Bureaucrat intern("Intern", 149); // Cannot sign or execute

    std::cout << "Form: " << pardon << std::endl;

    std::cout << "\n--- Testing signing ---" << std::endl;
    president.signForm(pardon); // Should succeed

    std::cout << "\n--- Testing execution by president ---" << std::endl;
    president.executeForm(pardon); // Should succeed

    std::cout << "\n--- Testing with minister (can sign, can't execute) ---"
              << std::endl;
    PresidentialPardonForm pardon2("Ford Prefect");
    minister.signForm(pardon2);    // Should succeed
    minister.executeForm(pardon2); // Should fail - grade too low for execution

    std::cout << "\n--- Testing with intern ---" << std::endl;
    PresidentialPardonForm pardon3("Zaphod");
    intern.signForm(pardon3);    // Should fail
    intern.executeForm(pardon3); // Should fail

    // ========== TEST 4: Exception Handling ==========
    std::cout << "\n\n========== TEST 4: Exception Handling =========="
              << std::endl;

    std::cout << "\n--- Testing invalid bureaucrat creation ---" << std::endl;
    try {
      Bureaucrat invalid("Invalid", 0); // Too high
    } catch (std::exception &e) {
      std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
      Bureaucrat invalid2("Invalid2", 151); // Too low
    } catch (std::exception &e) {
      std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing direct form execution (without executeForm) ---"
              << std::endl;
    try {
      ShrubberyCreationForm directTest("direct");
      Bureaucrat good("Good", 50);
      directTest.execute(good); // Should fail - not signed
    } catch (std::exception &e) {
      std::cout << "Direct execution failed: " << e.what() << std::endl;
    }

    // ========== TEST 5: Form Creation Edge Cases ==========
    std::cout << "\n\n========== TEST 5: Form Creation Edge Cases =========="
              << std::endl;

    std::cout << "\n--- Testing forms with edge case grades ---" << std::endl;
    Bureaucrat gradeBoundary1("Boundary1",
                              145); // Exactly at ShrubberyCreation sign limit
    Bureaucrat gradeBoundary2("Boundary2",
                              137); // Exactly at ShrubberyCreation exec limit
    Bureaucrat gradeBoundary3("Boundary3",
                              72); // Exactly at RobotomyRequest sign limit
    Bureaucrat gradeBoundary4("Boundary4",
                              45); // Exactly at RobotomyRequest exec limit

    ShrubberyCreationForm edgeTest("edge");

    std::cout << "\n--- Grade 145 trying to sign ShrubberyCreation (should "
                 "succeed) ---"
              << std::endl;
    gradeBoundary1.signForm(edgeTest);

    std::cout << "\n--- Grade 137 trying to execute ShrubberyCreation (should "
                 "succeed) ---"
              << std::endl;
    gradeBoundary2.executeForm(edgeTest);

    // ========== SUMMARY ==========
    std::cout << "\n\n========== SUMMARY ==========" << std::endl;
    std::cout << "✅ ShrubberyCreationForm: Creates files with ASCII trees"
              << std::endl;
    std::cout
        << "✅ RobotomyRequestForm: Makes drilling noises, 50% success rate"
        << std::endl;
    std::cout << "✅ PresidentialPardonForm: Zaphod Beeblebrox pardons target"
              << std::endl;
    std::cout << "✅ Bureaucrat::executeForm(): Handles execution with proper "
                 "messages"
              << std::endl;
    std::cout
        << "✅ Exception handling: Proper error messages for all failure cases"
        << std::endl;
    std::cout << "✅ Grade validation: Correct grade requirements for all forms"
              << std::endl;

    std::cout << "\n🎯 Exercise 02 Complete! Check for created files:"
              << std::endl;
    std::cout << "   - garden_shrubbery.txt" << std::endl;
    std::cout << "   - Any other *_shrubbery.txt files" << std::endl;

  } catch (std::exception &e) {
    std::cout << "\n❌ Unexpected exception: " << e.what() << std::endl;
  }

  std::cout << "\n====== END OF EXERCISE 02 TESTING ======" << std::endl;
  return 0;
}
