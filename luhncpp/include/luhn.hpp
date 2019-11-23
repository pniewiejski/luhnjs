#pragma once
#include <algorithm>
#include <iostream>
#include <locale>

namespace luhn {
bool isValid(const std::string& rawInput);
int generateCheckDigit(const std::string& rawInput);
int calculateLuhnRemainder(const std::string& rawInput);
int calculateLuhnRemainderWithValidation(const std::string& rawInput);
bool consistsOnlyOfDigits(const std::string& rawInput);
int handleOddOffset(const int& digit);
}  // namespace luhn