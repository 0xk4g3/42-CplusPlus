#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    Base *obj = generate();

    std::cout << "Object " << i + 1 << ":" << std::endl;
    std::cout << "  Pointer version: ";
    identify(obj);

    std::cout << "  Reference version: ";
    identify(*obj);

    delete obj;
    std::cout << std::endl;
  }

  return 0;
}
