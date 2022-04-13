#include <gtest/gtest.h>

long long reverse(int x) {
  long long result = 0;
  while (x) {
    result = (result * 10) + (x % 10);
    x /= 10;
  }
  return result;
}

TEST(REVERSE, testReverse) {
  EXPECT_EQ(24, reverse(42));
  EXPECT_EQ(-314, reverse(-413));
}
