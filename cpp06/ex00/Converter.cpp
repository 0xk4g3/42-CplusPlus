#include "ScalarConverter.hpp"

void ScalarConverter::handelCharInput(const std::string &input) {
  char c = 0;
  if (input.length() == 1)
    c = input[0];
  else
    c = input[1];

  std::cout << "Char : " << "'" << c << "'" << std::endl;
  std::cout << "int : " << static_cast<int>(c) << std::endl;
  std::cout << "Float : " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
}
void ScalarConverter::handelIntInput(const std::string &input) {
  long l = std::atol(input.c_str());

  std::cout << "Char: ";
  if (l < 0 || l > 127)
    std::cout << "impossible" << std::endl;
  else {

    if (isprint(l))
      std::cout << "Char : " << "'" << static_cast<char>(l) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  std::cout << "int: ";
  if (l > INT_MAX || l < INT_MIN)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(l) << std::endl;
  std::cout << "Float : " << static_cast<float>(l) << ".0f" << std::endl;
  std::cout << "double : " << static_cast<double>(l) << ".0" << std::endl;
}

void ScalarConverter::handelFloatInput(const std::string &input) {

  std::string numberPart = input.substr(0, input.length() - 1);
  float f = std::atof(numberPart.c_str());
  bool tolerance = std::fabs(f - static_cast<int>(f)) < 1e-6;
  std::cout << "Char: ";
  if (f < 0 || f > 127)
    std::cout << "impossible" << std::endl;
  else {

    if (isprint(static_cast<int>(f)))
      std::cout << "Char : " << "'" << static_cast<char>(f) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  std::cout << "int: ";
  if (static_cast<long>(f) > INT_MAX || static_cast<long>(f) < INT_MIN)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(f) << std::endl;
  std::cout << "float : ";
  if (f > MAX_FLOAT || f < MIN_FLOAT)
    std::cout << "impossible" << std::endl;
  else {
    if (tolerance) {
      std::cout << static_cast<int>(f) << ".0f" << std::endl;
    } else {
      std::cout << f << "f" << std::endl;
    }
  }
  std::cout << "Double :";

  if (static_cast<double>(f) > MAX_DOUBLE ||
      static_cast<double>(f) < MIN_DOUBLE)
    std::cout << "impossible" << std::endl;
  else {
    if (tolerance) {
      std::cout << static_cast<int>(f) << ".0" << std::endl;
    } else {
      std::cout << f << std::endl;
    }
  }
}

void ScalarConverter::handelDoubleInput(const std::string &input) {
  double d = std::atof(input.c_str());
  bool tolerance = std::fabs(d - static_cast<int>(d)) < 1e-6;
  std::cout << "Char: ";
  if (d < 0 || d > 127)
    std::cout << "impossible" << std::endl;
  else {

    if (isprint(static_cast<int>(d)))
      std::cout << "Char : " << "'" << static_cast<char>(d) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  std::cout << "int: ";
  if (static_cast<long>(d) > INT_MAX || static_cast<long>(d) < INT_MIN)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(d) << std::endl;
  std::cout << "float : ";
  if (static_cast<float>(d) > MAX_FLOAT || static_cast<float>(d) < MIN_FLOAT)
    std::cout << "impossible" << std::endl;
  else {
    if (tolerance) {
      std::cout << static_cast<int>(d) << ".0f" << std::endl;
    } else {
      std::cout << d << "f" << std::endl;
    }
  }

  std::cout << "Double :";

  if (d > MAX_DOUBLE || d < MIN_DOUBLE)
    std::cout << "impossible" << std::endl;
  else {
    if (tolerance) {
      std::cout << static_cast<int>(d) << ".0" << std::endl;
    } else {
      std::cout << d << std::endl;
    }
  }
}
