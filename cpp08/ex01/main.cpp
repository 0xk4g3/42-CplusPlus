
#include "Span.hpp"

int main() {

  try {

    Span sp = Span(5);
    unsigned int arr[] = {1, 2, 4, 5, 6};
    sp.addRange(arr, arr + 5);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "1000 number test" << std::endl;
    std::vector<int> vec;
    Span sp2 = Span(1000);
    for (int i = 0; i < 1000; ++i)
      vec.push_back(i);
    sp2.addRange(vec.begin(), vec.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

  } catch (std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
