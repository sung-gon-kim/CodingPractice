#include <gtest/gtest.h>

int divide(int x, int y) {
  int result = 0;
  int power = 32;
  unsigned long long power_y = static_cast<unsigned long long>(y) << power;
  while (x >= y) {
    while (power_y > x) {
      power_y >>= 1;
      --power;
    }
    result += 1 << power;
    x -= power_y;
  }
  return result;
}


TEST(DIVIDE, testDivide) {
  EXPECT_EQ(1, divide(1, 1));
  EXPECT_EQ(2, divide(2, 1));
  EXPECT_EQ(1, divide(2, 2));
  EXPECT_EQ(1, divide(3, 2));
  EXPECT_EQ(2, divide(4, 2));
}
