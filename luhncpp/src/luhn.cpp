#include "luhn.hpp"

bool luhn::consistsOnlyOfDigits(const std::string rawInput) {
  static std::locale locale;
  auto isDigit = [](const char character) {
    return std::isdigit(character, locale);
  };

  return std::all_of(rawInput.begin(), rawInput.end(), isDigit);
}

int luhn::handleOddOffset(const int digit) {
  const int doubledValue = digit * 2;

  return doubledValue < 10 ? doubledValue : (doubledValue - 9);
}

int luhn::calculateLuhnRemainder(const std::string rawInput) {
  int sum = 0;
  bool isOddOffset = false;
  for (size_t i = rawInput.length(); i-- != 0;) {
    const int digit = rawInput[i] - '0';
    sum += isOddOffset ? handleOddOffset(digit) : digit;
    isOddOffset ^= true;
  }

  return sum % 10;
}

bool luhn::isValid(const std::string rawInput) {
  if (rawInput.length() < 2 || !consistsOnlyOfDigits(rawInput)) {
    return false;
  }

  const int luhnRemainder = calculateLuhnRemainder(rawInput);

  return luhnRemainder == 0;
}

int luhn::generateCheckDigit(const std::string rawInput) {
  if (rawInput.length() < 1 || !consistsOnlyOfDigits(rawInput)) {
    throw std::invalid_argument(
        "Error in luhncpp: rawInput must contain only digits");
  }
  const int luhnRemainder = calculateLuhnRemainder(rawInput + "0");
  return (10 - luhnRemainder) % 10;
}
