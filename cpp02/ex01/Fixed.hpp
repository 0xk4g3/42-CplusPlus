


#ifndef  FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <ostream>
#include <cmath>
class Fixed { 
      private:
        int _fixedPointValue;            
        static const int _fractionalBits = 8; 
      public:
      Fixed();
      Fixed(const float number);
      Fixed( const int number);
      Fixed(const Fixed &src);
      Fixed &operator=(const Fixed &src);
      ~Fixed();
      float toFloat(void) const;
      int toInt(void) const;
};

std::ostream &operator <<(std::ostream &out , const Fixed &Fixed);
#endif