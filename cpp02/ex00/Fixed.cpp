#include "./Fixed.hpp"
#include <filesystem>






Fixed::Fixed():_fixedPointValue(0){
   std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &src){ 
  std::cout << "Copy constructor called" << std::endl;
  this->_fixedPointValue = src.getRawBits(); 
}

Fixed &Fixed::operator=(const Fixed &src){ 
    std::cout << "Copy assignment operator called " << std::endl;
    if(this != &src){ 
      this->_fixedPointValue = src.getRawBits();
    }
  return *this;
}

int Fixed::getRawBits(void)const { 

  std::cout << "getRawBits member function called" << std::endl;
  return this->_fixedPointValue;
}


void Fixed::setRawBits(int const raw){ 
     std::cout << "setRawBits member funciton called" << std::endl;
     this->_fixedPointValue = raw;
}

Fixed::~Fixed(){
   std::cout << "Destructor called" << std::endl;
}