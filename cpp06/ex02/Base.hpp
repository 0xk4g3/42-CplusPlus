#ifndef BASE_HPP
#define BASE_HPP
#include <cstdlib>
#include <iostream>
class Base {

private:
  Base &operator=(const Base &src);
  Base(const Base &src);

public:
  Base();
  virtual ~Base();
};
// classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
