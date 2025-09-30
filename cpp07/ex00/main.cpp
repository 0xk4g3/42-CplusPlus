#include "whatever.hpp"
#include <iostream>
#include <string>

int main() {
  // Test 1: Strings
  std::cout << "=== Test 1: Strings ===" << std::endl;
  std::string s1 = "hello";
  std::string s2 = "world";

  std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
  swap(s1, s2);
  std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
  std::cout << "min: " << ::min(s1, s2) << std::endl;
  std::cout << "max: " << ::max(s1, s2) << std::endl;

  // Test 2: Floats
  std::cout << "\n=== Test 2: Floats ===" << std::endl;
  float f1 = 3.14f;
  float f2 = 2.71f;

  std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
  std::cout << "min: " << ::min(f1, f2) << std::endl;
  std::cout << "max: " << ::max(f1, f2) << std::endl;
  swap(f1, f2);
  std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;

  // Test 3: Characters
  std::cout << "\n=== Test 3: Characters ===" << std::endl;
  char c1 = 'a';
  char c2 = 'z';

  std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
  std::cout << "min: " << ::min(c1, c2) << std::endl;
  std::cout << "max: " << ::max(c1, c2) << std::endl;

  // Test 4: Equal values
  std::cout << "\n=== Test 4: Equal values ===" << std::endl;
  int x = 42;
  int y = 42;

  std::cout << "x = " << x << ", y = " << y << std::endl;
  std::cout << "min: " << min(x, y) << std::endl;
  std::cout << "max: " << max(x, y) << std::endl;

  return 0;
}
