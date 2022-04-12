#include <gtest/gtest.h>

long long add(long long x, long long y) {
  while (y) {
    long long carry = x & y;
    x = x ^ y;
    y = carry << 1;
  }
  return x;
}

long long multiply(long long x, long long y) {
  long long sum = 0;
  while (x) {
    if (x & 1) {
      sum = add(sum, y);
    }
    x >>= 1;
    y <<= 1;
  }
  return sum;
}

TEST(MULTIPLY, testMultiply) {
  EXPECT_EQ(0, multiply(0, 0));
  EXPECT_EQ(1, multiply(1, 1));
  EXPECT_EQ(35, multiply(7, 5));
  EXPECT_EQ(81, multiply(9, 9));
  EXPECT_EQ(0, multiply(5, 0));
}
