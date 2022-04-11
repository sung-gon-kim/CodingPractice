#include <gtest/gtest.h>

long long swapBits(long long x, int i, int j) {
  if (((x >> i) & 1) != ((x >> j) & 1)) {
    unsigned long long bitmask = (1L << i) | (1L << j);
    x ^= bitmask;
  }
  return x;
}

TEST(BITSWAP, testSwapBits) {
  EXPECT_EQ(0, swapBits(0, 1, 2));  // 0000 -> 0000
  EXPECT_EQ(8, swapBits(1, 0, 3));  // 0001 -> 1000
  EXPECT_EQ(9, swapBits(9, 0, 3));  // 1001 -> 1001
}
