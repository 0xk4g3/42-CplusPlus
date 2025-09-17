#include "ScalarConverter.hpp"

bool ScalarConverter::isCharLiteral(const std::string &input) {

  if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
    return true;
  return false;
}
bool ScalarConverter::isSpecialValue(const std::string &input) {

  return (input == "nan" || input == "nanf" || input == "+inf" ||
          input == "-inf" || input == "+inff" || input == "-inff");
}
bool ScalarConverter::isInteger(const std::string &input) {

  if (input.empty())
    return false;
  size_t start = 0;
  if (input[0] == '-' || input[0] == '+')
    start = 1;
  for (size_t i = start; i < input.length(); i++) {
    if (!isdigit(input[i]))
      return false;
  }
  return start < input.length();
}

// NOTE: checking for the float F1

bool ScalarConverter::isFloat(const std::string &input) {

  if (input.length() < 3)
    return false;
  if (input[input.length() - 1] != 'f')
    return false;
  if (input.find('.') == std::string::npos)
    return false;
  std::string numberPart = input.substr(0, input.length() - 1);
  size_t start = 0;
  if (numberPart[0] == '-' || numberPart[0] == '+')
    start = 1;

  bool foundDecimal = false;
  for (size_t i = start; i < numberPart.length(); i++) {
    if (numberPart[i] == '.') {
      if (foundDecimal)
        return false;
      foundDecimal = true;
    } else if (!isdigit(numberPart[i])) {

      return false;
    }
  }

  return foundDecimal;
}

bool ScalarConverter::isDouble(const std::string &input) {

  if (input.length() < 3)
    return false;
  if (input[input.length() - 1] == 'f')
    return false;
  size_t start = 0;
  if (input[0] == '-' || input[0] == '+')
    start = 1;

  bool foundDecimal = false;
  for (size_t i = start; i < input.length(); i++) {
    if (input[i] == '.') {
      if (foundDecimal)
        return false;
      foundDecimal = true;
    } else if (!isdigit(input[i])) {

      return false;
    }
  }

  return foundDecimal;
}
void ScalarConverter::handleSpecialValue(const std::string &input) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  if (input == "nan" || input == "nanf") {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (input == "+inf" || input == "+inff") {
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (input == "-inf" || input == "-inff") {

    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  }
}
