#include "./Harl.hpp"



int main() {
  Harl harl;
    
    std::cout << "\n=== Testing Individual Levels ===\n" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\n=== Testing Invalid Cases ===\n" << std::endl;
    harl.complain("");             
    harl.complain("INVALID");       
    harl.complain("debug");         
    
    std::cout << "\n=== Testing Copy Constructor and Assignment ===\n" << std::endl;
    Harl harl2(harl);     
    Harl harl3;               
    harl3 = harl;           
    
    std::cout << "\nTesting harl2 (Copy Constructor):" << std::endl;
    harl2.complain("DEBUG");
    harl2.complain("ERROR");
    
    std::cout << "\nTesting harl3 (Assignment Operator):" << std::endl;
    harl3.complain("INFO");
    harl3.complain("WARNING");
    
    return 0;
}