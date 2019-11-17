#include "gtest/gtest.h"
#include "luhn.hpp"

TEST(luhn, checkValidity) {
    EXPECT_EQ(luhn::isValid("79927398713"), true);
}