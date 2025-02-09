

#include "./Fixed.hpp"
#include <ostream>
#include <iostream>
#include <cmath>





 // constructors  and destructor

Fixed::Fixed():_fixedPointValue(0){
    std::cout << "The constructor called"  << std::endl;
}



Fixed::Fixed(const Fixed &src ){
     std::cout << "Copy constructor called" << std::endl;
     this->_fixedPointValue = src._fixedPointValue;
}

Fixed::~Fixed(){
     std::cout << "The deconstructor called" << std::endl;
}


Fixed::Fixed(const float number){
     
      std::cout << "Float constructor called" << std::endl;
      this->_fixedPointValue  = roundf(number * (1 << _fractionalBits));
}


Fixed::Fixed(const int number){
     std::cout << "Integer constructor called" << std::endl;
     this->_fixedPointValue = number <<  _fractionalBits;

}

// copy assigment 

Fixed &Fixed::operator=(const Fixed &src)
{ 
    std::cout <<  "Copy assignment operator called" << std::endl;

     if(this != &src){
         this->_fixedPointValue = src._fixedPointValue;
     }
     return *this;
}

// Member functions

float Fixed::toFloat(void)const {
     return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void)const {
    return this->_fixedPointValue >> _fractionalBits;
}


// comparison operators;

bool Fixed::operator>(const Fixed &src ) const  {
      return this->getRawBits() > 
}

// getRawbits 
int Fixed::getRawBits(void)const { 

  std::cout << "getRawBits member function called" << std::endl;
  return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){ 
     std::cout << "setRawBits member funciton called" << std::endl;
     this->_fixedPointValue = raw;
}

// overload for the printing

std::ostream &operator << (std::ostream &out , const Fixed &Fixed){
     out << Fixed.toFloat();
      return out;
}