
#include "ScalarConverter.hpp"


void ScalarConverter::convert(const std::string &input) {
  if (isSpecialValue(input))
    handleSpecialValue(input);
  else if (isCharLiteral(input))
    handelCharInput(input);
  else if (isInteger(input))
    handelDoubleInput(input);
  else if (isFloat(input))
    handelFloatInput(input);
  else if (isDouble(input))
    handelDoubleInput(input);
  else
    std::cout << "Invalid input" << std::endl;
}
