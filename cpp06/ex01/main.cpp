#include "Serialize.hpp"

int main() {

  Data originalData;
  Data *originalPtr = &originalData;
  std::cout << "The Original Data Ptr Adress :" << originalPtr << std::endl;

  uintptr_t Uptr = Serializer::serializer(originalPtr);
  std::cout << "Unsigned Int ptr  Serializer Function :  " << Uptr << std::endl;
  Data *UptrValue = Serializer::deserializer(Uptr);
  std::cout << "Adress of Uptr After Developer : " << UptrValue << std::endl;
  bool Match = originalPtr == UptrValue ? true : false;
  std::cout << (Match ? "Success! Pointers match."
                      : "Failed! Pointers don't match.")
            << std::endl;

  /**---------Learning Why we need uintptr--------------------
  void *ptr = (void *)0x00007fff5fbff6ac;
    uint32_t bad = (uint32_t)ptr; // bad = 0x5fbff6ac (truncated!)
    void *broken = (void *)bad;   // Points to wrong address!

    uintptr_t good = (uintptr_t)ptr; // good = 0x00007fff5fbff6ac (complete)
    void *correct = (void *)good;
    return 0;
     **/
}
