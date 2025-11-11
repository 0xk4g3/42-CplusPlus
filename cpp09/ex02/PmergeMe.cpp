#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <limits>

int PmergeMe::nbr_of_comps = 0;

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _vectorData = other._vectorData;
    _dequeData = other._dequeData;
  }
  return *this;
}

bool PmergeMe::isValidNumber(std::string &s) {
  if (s.empty())
    return false;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == '+' && i == 0)
      continue;
    if (s[i] < '0' || s[i] > '9')
      return false;
  }
  return true;
}

// The book  of  section (12)

long PmergeMe::jacobsthalNumber(long n) {

  return ((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::sort(int argc, char **argv) {
  // Parse input
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (!isValidNumber(arg)) {
      std::cerr << "Error: invalid input" << std::endl;
      return;
    }

    double num_check = std::atof(arg.c_str());
    if (num_check > 2147483647 || num_check < 0) {
      std::cerr << "Error: number out of range" << std::endl;
      return;
    }

    int num = std::atoi(arg.c_str());
    _vectorData.push_back(num);
    _dequeData.push_back(num);
  }

  if (_vectorData.empty()) {
    std::cerr << "Error: no input provided" << std::endl;
    return;
  }

  // Display "Before"
  std::cout << "Before: ";
  for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
    std::cout << _vectorData[i] << " ";
  if (_vectorData.size() > 5)
    std::cout << "[...]";
  std::cout << std::endl;

  // Sort vector
  nbr_of_comps = 0;
  struct timeval vec_start, vec_end;
  gettimeofday(&vec_start, NULL);
  mergeInsertionSort(_vectorData, 1);
  gettimeofday(&vec_end, NULL);
  double vec_time = (vec_end.tv_sec - vec_start.tv_sec) * 1000000.0 +
                    (vec_end.tv_usec - vec_start.tv_usec);

  // Sort deque
  nbr_of_comps = 0;
  struct timeval deq_start, deq_end;
  gettimeofday(&deq_start, NULL);
  mergeInsertionSort(_dequeData, 1);
  gettimeofday(&deq_end, NULL);
  double deq_time = (deq_end.tv_sec - deq_start.tv_sec) * 1000000.0 +
                    (deq_end.tv_usec - deq_start.tv_usec);

  // Display "After"
  std::cout << "After:  ";
  for (size_t i = 0; i < _vectorData.size() && i < 5; i++)
    std::cout << _vectorData[i] << " ";
  if (_vectorData.size() > 5)
    std::cout << "[...]";
  std::cout << std::endl;

  // Display timing
  std::cout << "Time to process a range of " << _vectorData.size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5) << vec_time << " us" << std::endl;

  std::cout << "Time to process a range of " << _dequeData.size()
            << " elements with std::deque  : " << std::fixed
            << std::setprecision(5) << deq_time << " us" << std::endl;

  std::cout << "Number of comparisons: " << nbr_of_comps << std::endl;
}
