

#include <iostream>

typedef int (*operation)(int, int);
typedef struct Form {

  std::string name;
  operation test;
} Aform;

int plus(int a, int b) { return (a + b); }
int multi(int a, int b) { return (a * b); }
int main() {
  Form opt[2] = {{"multi", &multi}, {"plus", &plus}};

  while (true) {

    std::string input;
    std::cin >> input;
    int a;
    std::cin >> a;
    int b;
    std::cout << "enter the B : ";
    std::cin >> b;

    if (input == opt[0].name) {

      std::cout << opt[0].test(a, b) << std::endl;
    }
  }
  return 0;
}
