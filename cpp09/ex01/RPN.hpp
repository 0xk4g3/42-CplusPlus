#ifndef RPN_HPP
#define RPN_HPP
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
class RPN {

private:
  static const long SCALE = 1000000;
  std::stack<long> _stack;
  bool isOperator(const std::string &token);
  bool isNumber(const std::string &token);
  long performOperation(long a, long b, char op);

public:
  RPN();
  ~RPN();

  RPN &operator=(const RPN &src);
  RPN(const RPN &src);

  // start the logic
  void evalute(const std::string &expression);
};

#endif
