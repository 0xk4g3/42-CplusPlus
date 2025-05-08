#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // Test from the subject
    std::cout << "=== Basic test from subject ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;  // Should not create a leak
    delete i;
    
    // Test array of Animals
    std::cout << "\n=== Array of Animals test ===" << std::endl;
    const Animal* animals[4];
    
    // Fill half with Dogs, half with Cats
    for (int idx = 0; idx < 4; idx++) {
        if (idx < 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }
    
    // Test that makeSound works correctly
    std::cout << "\n=== Testing polymorphism ===" << std::endl;
    for (int idx = 0; idx < 4; idx++) {
        animals[idx]->makeSound();
    }
    
    // Delete all animals
    std::cout << "\n=== Deleting animals ===" << std::endl;
    for (int idx = 0; idx < 4; idx++) {
        delete animals[idx];
    }
    
    // Test deep copy
    std::cout << "\n=== Testing deep copy ===" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;  // Copy constructor
        Dog tmp2;
        tmp2 = basic;     // Assignment operator
    }
    std::cout << "Temp objects destroyed, basic still exists" << std::endl;
    
    return 0;
}
