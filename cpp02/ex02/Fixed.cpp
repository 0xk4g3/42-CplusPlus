

#include "./Fixed.hpp"
#include <ostream>
#include <iostream>
#include <cmath>





 // constructors  and destructor

Fixed::Fixed():_fixedPointValue(0){
  
}



Fixed::Fixed(const Fixed &src ){
   
     this->_fixedPointValue = src._fixedPointValue;
}

Fixed::~Fixed(){

}


Fixed::Fixed(const float number){
     
    
      this->_fixedPointValue  = roundf(number * (1 << _fractionalBits));
}


Fixed::Fixed(const int number){
 
     this->_fixedPointValue = number <<  _fractionalBits;

}

// copy assigment 

Fixed &Fixed::operator=(const Fixed &src)
{ 


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

bool Fixed::operator>(const Fixed &src) const{
          return this->getRawBits() > src._fixedPointValue;

}
bool Fixed::operator<(const Fixed &src) const{
          return this->getRawBits()  < src._fixedPointValue;
}
bool Fixed::operator>=(const Fixed &src) const{
          return this->getRawBits()  >= src._fixedPointValue;


}
bool Fixed::operator<=(const Fixed &src) const{
          return this->getRawBits()  <= src._fixedPointValue;

}

bool Fixed::operator!=(const Fixed &src)const{
          return this->getRawBits() != src._fixedPointValue; 

}
bool Fixed::operator==(const Fixed &src)const{
          return this->getRawBits()  == src._fixedPointValue;

}

// arithemtic operators 

Fixed Fixed::operator+(const Fixed &src) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue + src._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &src) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue - src._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &src) const {
    Fixed result;

    result._fixedPointValue = (this->_fixedPointValue * src._fixedPointValue) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &src) const {
    Fixed result;

   result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / src._fixedPointValue;
    return result;
}

Fixed& Fixed::operator++(){
     this->_fixedPointValue += 1;

     return *this;
}

Fixed Fixed::operator++(int){
     Fixed temp(*this);
     operator++();
     return temp;

}

Fixed& Fixed::operator--(){
    std::cout << this->_fixedPointValue << std::endl;
     this->_fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int){
     Fixed temp2(*this);
     operator--();
     return temp2;
}

// getRawbits 
int Fixed::getRawBits(void)const { 

  
  return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){ 

     this->_fixedPointValue = raw;
}

// comparing min - max 


 Fixed& Fixed::min(Fixed &a , Fixed &b){

        return  a._fixedPointValue < b._fixedPointValue ?  a : b;
}

const Fixed& Fixed::min(const Fixed &a , const Fixed &b){
        
    return  a._fixedPointValue < b._fixedPointValue ?  a : b;
}


Fixed& Fixed::max(Fixed &a , Fixed &b){
     
      return a._fixedPointValue  >  b._fixedPointValue ? a : b;
}

const   Fixed&  Fixed::max(const  Fixed &a ,const Fixed &b){
     
      return a._fixedPointValue  >  b._fixedPointValue ? a : b;
}
// overload for the printing

std::ostream &operator << (std::ostream &out , const Fixed &Fixed){
     out << Fixed.toFloat();
      return out;
}