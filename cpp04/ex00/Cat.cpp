

#include "Cat.hpp"



Cat::Cat(){
	 type = "Cat";
	 std::cout <<  "Dog constructor called" << std::endl;

}

Cat::~Cat(){ 
	std::cout  << "Dog destructor called" << std::endl;
}

void Cat::makeSound() const{
	
	std::cout << "Meow!"<< std::endl;
}
