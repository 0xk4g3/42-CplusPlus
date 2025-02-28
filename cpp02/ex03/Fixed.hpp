

#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>
#include <ostream>
class Fixed {
private:
  int _fixedPointValue;
  static const int _fractionalBits = 8;

public:
  // constructors  and destructor
  Fixed();
  Fixed(const float number);
  Fixed(const int number);
  Fixed(const Fixed &src);
  ~Fixed();
  // assignment operator
  Fixed &operator=(const Fixed &src);
  // Member functions
  float toFloat(void) const;
  int toInt(void) const;
  // comparison operators
  bool operator>(const Fixed &src) const;
  bool operator<(const Fixed &src) const;
  bool operator>=(const Fixed &src) const;
  bool operator<=(const Fixed &src) const;
  bool operator!=(const Fixed &src) const;
  bool operator==(const Fixed &src) const;

  // arithemtic operators
  Fixed operator+(const Fixed &src) const;
  Fixed operator-(const Fixed &src) const;
  Fixed operator/(const Fixed &src) const;
  Fixed operator*(const Fixed &src) const;

  // Increment / decrement
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  // static member functions
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  // manage the data
  int getRawBits(void) const;
  void setRawBits(int const raw);
  // abs
   Fixed abs(void)const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);
#endif
