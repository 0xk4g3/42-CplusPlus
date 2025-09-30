#ifndef INTER_HPP
#define INTER_HPP

#include <iostream>

template <typename T, typename Callback>
void iter(const T *arr, const uint length, Callback callBack) {

  for (uint i = 0; i < length; i++) {
    callBack(arr[i]);
  }
}

template <typename T, typename Callback>

void iter(T *arr, uint length, Callback callBack) {

  for (std::size_t i = 0; i < length; i++) {
    callBack(arr[i]);
  }
}


#endif
