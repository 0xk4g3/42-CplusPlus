#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <vector>
class PmergeMe;

template <typename Iterator> bool compare(Iterator lv, Iterator rv);
template <typename Iterator> Iterator next(Iterator it, int steps) {
  std::advance(it, steps);
  return it;
}
class PmergeMe {

private:
  std::vector<int> _vectorData;
  std::deque<int> _dequeData;

  bool isValidNumber(std::string &s);
  long jacobsthalNumber(long n);

  // Handel the both of the container -> deque and vector

  template <typename Container>
  void mergeInsertionSort(Container &continer, int pair_level) {

    typedef typename Container::iterator Iterator;

    int pair_units_nbr = continer.size() / pair_level;

    if (pair_units_nbr < 2)
      return;

    bool is_odd = pair_units_nbr % 2 == 1;

    Iterator start = continer.begin();
    Iterator last = next(continer.begin(), pair_level * pair_units_nbr);
    Iterator end = next(last, -(is_odd * pair_level));

    int jump = 2 * pair_level;

    for (Iterator it = start; it != end; std::advance(it, jump)) {

      Iterator this_pair = next(it, pair_level - 1);
      Iterator next_pair = next(it, pair_level * 2 - 1);

      if (compare(next_pair, this_pair)) {

        swapPair(this_pair, pair_level);
      }
    }
    mergeInsertionSort(continer, pair_level * 2);
    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    main.insert(main.end(), next(continer.begin(), pair_level - 1));
    main.insert(main.end(), next(continer.begin(), pair_level * 2 - 1));

    for (int i = 4; i <= pair_units_nbr; i += 2) {

      pend.insert(pend.end(), next(continer.begin(), pair_level * (i - 1) - 1));
      main.insert(main.end(), next(continer.begin(), pair_level * i - 1));
    }
    if (is_odd) {
      pend.insert(pend.end(), next(end, pair_level - 1));
    }
    int prev_jacobsthal = jacobsthalNumber(1);
    int inserted_numbers = 0;

    for (int k = 2;; k++) {

      int curr_jacobsthal = jacobsthalNumber(k);
      int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
      int offset = 0;

      if (jacobsthal_diff > static_cast<int>(pend.size()))
        break;

      int nbr_of_times = jacobsthal_diff;
      typename std::vector<Iterator>::iterator pend_it =
          next(pend.begin(), jacobsthal_diff - 1);
      typename std::vector<Iterator>::iterator bound_it =
          next(main.begin(), curr_jacobsthal + inserted_numbers);

      while (nbr_of_times) {
        typename std::vector<Iterator>::iterator idx = std::upper_bound(
            main.begin(), bound_it, *pend_it, compare<Iterator>);
        typename std::vector<Iterator>::iterator inserted =
            main.insert(idx, *pend_it);

        nbr_of_times--;
        pend_it = pend.erase(pend_it);
        std::advance(pend_it, -1);
        offset +=
            (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
        bound_it =
            next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
      }
      prev_jacobsthal = curr_jacobsthal;
      inserted_numbers += jacobsthal_diff;
      offset = 0;
    }
    for (ssize_t i = pend.size() - 1; i >= 0; i--) {
      typename std::vector<Iterator>::iterator curr_pend =
          next(pend.begin(), i);
      typename std::vector<Iterator>::iterator curr_bound =
          next(main.begin(), main.size() - pend.size() + i + is_odd);
      typename std::vector<Iterator>::iterator idx = std::upper_bound(
          main.begin(), curr_bound, *curr_pend, compare<Iterator>);
      main.insert(idx, *curr_pend);
    }
    std::vector<int> copy;
    copy.reserve(continer.size());

    for (typename std::vector<Iterator>::iterator it = main.begin();
         it != main.end(); it++) {
      for (int i = 0; i < pair_level; i++) {
        Iterator pair_start = *it;
        std::advance(pair_start, -pair_level + i + 1);
        copy.insert(copy.end(), *pair_start);
      }
    }

    // Replace values in original container
    Iterator container_it = continer.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end()) {
      *container_it = *copy_it;
      container_it++;
      copy_it++;
    }
  }

  // this for swap the pairs
  template <typename Iterator> void swapPair(Iterator it, int pair_level) {

    Iterator start = next(it, -pair_level + 1);
    Iterator end = next(start, pair_level);

    while (start != end) {

      std::iter_swap(start, next(start, pair_level));
      start++;
    }
  }

public:
  static int nbr_of_comps;
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void sort(int argc, char **argv);
};

template <typename Iterator> bool compare(Iterator lv, Iterator rv) {
  PmergeMe::nbr_of_comps++;
  return *lv < *rv;
}

#endif
