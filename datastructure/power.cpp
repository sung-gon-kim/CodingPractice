#include <gtest/gtest.h>

double pow(double x, int y) {
  double result = 1.0;
  long long power = y;
  if (y < 0) {
    power = -power;
    x = 1.0 / x;
  }
  while (power) {
    if (power & 1) {
      result *= x;
    }
    x *= x;
    power >>= 1;
  }
  return result;
}


TEST(POWER, testPow) {
  EXPECT_EQ(1, pow(1, 1));
  EXPECT_EQ(4, pow(2, 2));
  EXPECT_EQ(27, pow(3, 3));
}
