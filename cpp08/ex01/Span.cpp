#include "Span.hpp"

Span::Span(unsigned int N) : _MaxSize(N) { _Numbers.reserve(_MaxSize); }

Span::~Span() {}
Span::Span(const Span &src) : _MaxSize(src._MaxSize), _Numbers(src._Numbers) {}

Span &Span::operator=(const Span &src) {
  if (this != &src) {
    _MaxSize = src._MaxSize;
    _Numbers = src._Numbers;
  }
  return *this;
}

void Span::addNumber(unsigned int Number) {

  if (_Numbers.size() >= _MaxSize) {
    throw std::runtime_error("Span is full");
  }
  _Numbers.push_back(Number);
}
unsigned int Span::shortestSpan() {

  if (_Numbers.empty() || _Numbers.size() < 2)
    throw std::runtime_error("The Container empty or The size = 1");

  std::vector<unsigned int> stored = _Numbers;

  std::sort(stored.begin(), stored.end());

  unsigned int MinSpan = stored[1] - stored[0];
  for (unsigned int i = 2; i < stored.size(); i++) {
    unsigned int gap = stored[i] - stored[i - 1];
    if (MinSpan > gap)
      MinSpan = gap;
  }

  return MinSpan;
}

unsigned int Span::longestSpan() {

  if (_Numbers.size() < 2)
    throw std::runtime_error("The Container empty or The size = 1");
  unsigned int maxVal = *std::max_element(_Numbers.begin(), _Numbers.end());
  unsigned int minVal = *std::min_element(_Numbers.begin(), _Numbers.end());

  return maxVal - minVal;
}
