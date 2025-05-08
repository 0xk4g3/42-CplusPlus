#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    // Test from the subject
    std::cout << "=== Test from the subject ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Testing Wrong Polymorphism ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();  
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    // Test 1: Direct WrongCat object (not through pointer)
    WrongCat directWrongCat;
    directWrongCat.makeSound();  // This will correctly call WrongCat::makeSound()
    
    // Test 2: Demonstrating the problem with non-virtual destructors
    std::cout << "\n=== Testing destructors ===" << std::endl;
    Animal* animal = new Dog();
    delete animal;  
    
    std::cout << std::endl;
    
    WrongAnimal* wrongAnimal = new WrongCat();
    delete wrongAnimal; 
    
    return 0;
}
