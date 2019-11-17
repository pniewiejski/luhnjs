#include "luhn.hpp"
#include <iostream>

int main() {
  std::cout << "Hello world" << std::endl;

  std::cout << luhn::isValid("79927398713") << std::endl;
  std::cout << luhn::generateCheckDigit("7992739871") << std::endl;
  return 0;
}