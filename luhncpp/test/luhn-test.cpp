#include "luhn.hpp"
#include "gtest/gtest.h"

TEST(luhn, checkLuhnValidityForValidInput) {
  EXPECT_EQ(luhn::isValid("79927398713"), true);
  EXPECT_EQ(luhn::isValid("79927398711"), false);
}

TEST(luhn, checkLuhnValidityForInvalidInput) {
  ASSERT_THROW(luhn::isValid("79927398713abs"), std::invalid_argument);
  ASSERT_THROW(luhn::isValid("7992#11f7398711"), std::invalid_argument);
}

TEST(luhn, calculateLuhnRemainder) {
  EXPECT_EQ(luhn::calculateLuhnRemainder("79927398710"), 7);
  EXPECT_EQ(luhn::calculateLuhnRemainder("123"), 8);
  EXPECT_EQ(luhn::calculateLuhnRemainder("1230"), 0);
  EXPECT_EQ(luhn::calculateLuhnRemainder("1234567820"), 8);
}

TEST(luhn, generateLuhnCheckDigit) {
  EXPECT_EQ(luhn::generateCheckDigit("7992739871"), 3);
  EXPECT_EQ(luhn::generateCheckDigit("987654321"), 7);
  EXPECT_EQ(luhn::generateCheckDigit("123"), 0);
}

TEST(luhn, generateLuhnCheckDigitWithInvalidInput) {
  ASSERT_THROW(luhn::generateCheckDigit("123abc"), std::invalid_argument);
}

TEST(luhn, calculateLuhnRemainderWithValidation) {
  EXPECT_EQ(luhn::calculateLuhnRemainderWithValidation("79927398710"), 7);

  ASSERT_THROW(luhn::calculateLuhnRemainderWithValidation("123@asc45"),
               std::invalid_argument);
  ASSERT_THROW(luhn::calculateLuhnRemainderWithValidation("123 45"),
               std::invalid_argument);
}

TEST(luhn, consistsOfNumbers) {
  EXPECT_EQ(luhn::consistsOnlyOfDigits("123"), true);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("123asdf"), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("asdf"), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("122@3"), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("1223  "), false);
  EXPECT_EQ(luhn::consistsOnlyOfDigits("122 3"), false);
}