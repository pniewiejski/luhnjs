#include "luhn.hpp"
#include "gtest/gtest.h"

TEST(luhn, checkLuhnValidityForValidInput) {
  EXPECT_EQ(luhn::isValid("79927398713"), true);
  EXPECT_EQ(luhn::isValid("79927398711"), false);
}

TEST(luhn, checkLuhnValidityForInvalidInput) {
  EXPECT_EQ(luhn::isValid("79927398713abs"), false);
  EXPECT_EQ(luhn::isValid("7992#11f7398711"), false);
}

TEST(luhn, calculateLuhnRemainder) {
  EXPECT_EQ(luhn::calculateLuhnRemainder("79927398710"), 7);
  EXPECT_EQ(luhn::calculateLuhnRemainder("123"), 8);
}

TEST(luhn, generateLuhnCheckDigit) {
  EXPECT_EQ(luhn::generateCheckDigit("7992739871"), 3);
  EXPECT_EQ(luhn::generateCheckDigit("987654321"), 7);
}

TEST(luhn, luhn_generateLuhnCheckDigitWithInvalidInput) {
  ASSERT_THROW(luhn::generateCheckDigit("123abc"), std::string);
}

TEST(luhn, consistsOfNumbers) {
  EXPECT_EQ(luhn::consistsOnlyOfDigits("123"), true);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("123asdf"), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("asdf"), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("122@3"), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("1223  "), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("122 3"), false);
}