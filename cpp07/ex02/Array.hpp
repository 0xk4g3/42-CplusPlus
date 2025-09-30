#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

#include <iostream>

template <typename T> class Array {

private:
  T *m_data;
  uint _n;

public:
  Array() : m_data(0), _n(0) {}
  Array(uint n) : m_data(0), _n(n) {

    if (n > 0) {

      m_data = new T[n];
      for (uint i = 0; i < _n; ++i) {
        m_data[i] = T();
      }
    }
  }
  ~Array() { delete[] m_data; }
  Array(const Array &src) : m_data(0), _n(0) {

    if (src._n > 0) {
      m_data = new T[src._n];
      this->_n = src._n;
      for (uint i = 0; i < src._n; i++) {
        m_data[i] = src.m_data[i];
      }
    }
  }
  Array &operator=(const Array &src) {

    if (this != &src) {

      _n = src._n;
      if (_n > 0) {

        m_data = new T[_n];
        for (uint i = 0; i < _n; i++) {

          m_data[i] = src.m_data[i];
        }
      } else
        m_data = NULL;
    }
    return *this;
  }
  T &operator[](uint index) {
    if (index >= _n) {
      throw std::exception();
    }
    return m_data[index];
  }
  const T &operator[](unsigned int index) const {
    if (index >= _n) {
      throw std::exception();
    }
    return m_data[index];
  }
  uint size() const { return _n; }
};

#endif
