#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) { *this = src; }

RPN &RPN::operator=(const RPN &src) {

  if (this != &src) {

    this->_stack = src._stack;
  }
  return *this;
}

// start implment the logic

bool RPN::isOperator(const std::string &token) {

  if (token.length() != 1)
    return false;
  char c = token[0];
  return (c == '+' || c == '-' || c == '/' || c == '*');
}
bool RPN::isNumber(const std::string &token) {

  if (token.empty())
    return false;
  for (size_t i = 0; i < token.length(); i++) {
    // If any character is NOT a digit, return false
    if (!std::isdigit(token[i]))
      return false;
  }
  return true;
}
long RPN::performOperation(long a, long b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return (a * b) / SCALE;

  case '/':
    if (b == 0)
      throw std::runtime_error("Error: division by zero");
    return (a * SCALE) / b;
  default:
    throw std::runtime_error("Error: invalid operator");
  }
}
void RPN::evalute(const std::string &expression) {

  std::istringstream iss(expression);
  std::string token;

  while (iss >> token) {

    if (isNumber(token)) {

      long num = atol(token.c_str());
      if (num >= 10 || num < 0)
        throw std::runtime_error("Error: numbers must be less than 10");

      _stack.push(num * SCALE);
    } else if (isOperator(token)) {

      if (_stack.size() < 2)
        throw std::runtime_error("Error: insufficient operands");
      // NOTE:  the same perfermonce of the RPN  Check the wikipedia  section :
      // Explanation
      long b = _stack.top();
      _stack.pop();
      long a = _stack.top();
      _stack.pop();
      // end of the explanation
      long result = performOperation(a, b, token[0]);

      if (result > INT_MAX * SCALE || result < INT_MIN * SCALE)
        throw std::runtime_error("Error: integer overflow");
      _stack.push(result);
    } else {
      throw std::runtime_error("Error : invalid token");
    }
  }
  if (_stack.size() != 1)
    throw std::runtime_error("Error: invalid expression");

  long result = _stack.top();

  long integerPart = result / SCALE;
  long fractionalPart = result % SCALE;

  if (fractionalPart < 0)
    fractionalPart = -fractionalPart;

  std::cout << integerPart;
  if (fractionalPart != 0) {
    std::cout << ".";
    while (fractionalPart % 10 == 0 && fractionalPart > 0)
      fractionalPart /= 10;
    std::cout << fractionalPart;
  }
  std::cout << std::endl;
}
