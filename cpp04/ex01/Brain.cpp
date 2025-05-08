#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty idea";
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& src) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = src.ideas[i];
        }
    }
    return *this;
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = src.ideas[i];
    }
}
