#include <algorithm>
#include <iostream>
#include <locale>

namespace luhn {
bool consistsOnlyOfDigits(const std::string rawInput);
int handleOddOffset(const int digit);
int calculateLuhnRemainder(const std::string rawInput);
bool isValid(const std::string rawInput);
int generateCheckDigit(const std::string rawInput);
}  // namespace luhn