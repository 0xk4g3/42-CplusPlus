#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
class Span {

private:
  unsigned int _MaxSize;

  std::vector<unsigned int> _Numbers;

public:
  Span(unsigned int N);
  ~Span();
  Span(const Span &src);
  Span &operator=(const Span &src);
  void addNumber(unsigned int Number);
  unsigned int shortestSpan();
  unsigned int longestSpan();

  // range iterators
  template <typename Iterator> void addRange(Iterator begin, Iterator end) {

    unsigned int dis = std::distance(begin, end);

    if (_Numbers.size() + dis > _MaxSize)
      throw std::runtime_error("Not enough space in Span");

    _Numbers.insert(_Numbers.end(), begin, end);
  }
};

#endif
