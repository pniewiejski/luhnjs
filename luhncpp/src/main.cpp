#include <iostream>
#include "luhn.hpp"

int main() {
  std::cout << "There are no easter eggs up here.\n Go away." << std::endl;

  std::cout << luhn::isValid("79927398713") << std::endl;
  std::cout << luhn::generateCheckDigit("7992739871") << std::endl;
  return 0;
}