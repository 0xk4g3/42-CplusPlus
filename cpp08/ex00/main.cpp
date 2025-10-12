
#include "easyfind.hpp"

int main() {

  std::vector<int> vec;

  vec.push_back(10);
  vec.push_back(10);
  vec.push_back(1);
  vec.push_back(10);
  vec.push_back(10);
  vec.push_back(10);
  vec.push_back(1);

  int value = 1;
  try {

    std::vector<int>::iterator it = easyfind(vec, value);
    std::cout << *it << std::endl;
  } catch (std::runtime_error &e) {

    std::cout << e.what() << std::endl;
  }

  return 0;
}
