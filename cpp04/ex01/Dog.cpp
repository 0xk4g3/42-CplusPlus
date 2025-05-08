#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();  // Create Brain
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() { 
    delete brain;  // Delete Brain
    std::cout << "Dog destructor called" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);  // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;  // Delete old brain
        brain = new Brain(*other.brain);  // Deep copy
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
