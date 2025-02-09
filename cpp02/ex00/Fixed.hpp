
#ifndef FIXED_HPP
#define  FIXED_HPP

#include <iostream>

class Fixed { 
        private:
           static  const int  _fractionalBits = 8;
            int  _fixedPointValue;
        public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const  raw);
};


#endif