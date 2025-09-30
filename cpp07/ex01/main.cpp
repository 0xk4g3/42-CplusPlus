
#include "iter.hpp"

void const_mutate_callback(const int &x) {
  std::cout << "The value of the array : " << x << std::endl;
}

void mutate_callback(int &x) { x *= 10; }
int main() {

  int non_const_array[] = {1, 2, 3};
  const uint size = 3;
  ::iter(non_const_array, size, mutate_callback);

  std::cout << "<==========  Non Const case ============>" << std::endl;

  for (int i = 0; i < 3; i++) {

    std::cout << "The Element : " << i << " Become -> " << non_const_array[i]
              << std::endl;
  }

  std::cout << "<========== Const case ============>" << std::endl;

  const int const_arry[] = {4, 5, 6};
  const uint size2 = 3;
  ::iter(const_arry, size2, const_mutate_callback);
}
