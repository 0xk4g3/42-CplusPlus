#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // This will now cause a compilation error:
    // const Animal* animal = new Animal();  // ERROR! Can't instantiate abstract class
    
    // But these still work fine:
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    
    std::cout << cat->getType() << " says: ";
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    // Test that abstract class prevents instantiation
    std::cout << "\n=== Testing abstract class ===" << std::endl;
    std::cout << "Trying to create Animal directly would cause compilation error" << std::endl;
    // Animal test;  // Uncomment to see compilation error
    
    // Array test still works
    std::cout << "\n=== Array test with abstract base ===" << std::endl;
    const Animal* animals[4];
    
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }
    
    return 0;
}
