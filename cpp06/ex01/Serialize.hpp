#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

struct Data {

  int number;
  std::string name;
  char letter;
};
class Serializer {

private:
  Serializer();
  ~Serializer();
  Serializer &operator=(const Serializer &src);
  Serializer(const Serializer &src);

public:
  static uintptr_t serializer(Data *ptr);
  static Data *deserializer(uintptr_t raw);
};
#endif
