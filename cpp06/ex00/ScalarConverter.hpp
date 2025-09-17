#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_DOUBLE (-std::numeric_limits<double>::max())
#define MAX_DOUBLE std::numeric_limits<double>::max()
class ScalarConverter {

private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &src);
  ScalarConverter(const ScalarConverter &src);

public:
  static void convert(const std::string &input);
  // Type checking functions
  static bool isCharLiteral(const std::string &input);
  static bool isSpecialValue(const std::string &input);
  static bool isFloat(const std::string &input);
  static bool isDouble(const std::string &input);
  static bool isInteger(const std::string &input);
  static void handleSpecialValue(const std::string &input);
  static void handelCharInput(const std::string &input);
  static void handelIntInput(const std::string &input);
  static void handelFloatInput(const std::string &input);
  static void handelDoubleInput(const std::string &input);
};

#endif
