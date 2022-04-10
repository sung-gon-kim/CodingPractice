#include <gtest/gtest.h>

short int calculate_parity1(unsigned long long x) {
  short int result = 0;
  while (x) {
    result ^= (x & 1);
    x >>= 1;
  }
  return result;
}

short int calculate_parity2(unsigned long long x) {
  short int result = 0;
  while (x) {
    result ^= 1;
    x &= (x - 1);
  }
  return result;
}

short int calculate_parity3(unsigned long long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}

TEST(PARITIES, testCalculateParity1) {
  EXPECT_EQ(0, calculate_parity1(0));  // 0000000000000000
  EXPECT_EQ(1, calculate_parity1(1));  // 0000000000000001
  EXPECT_EQ(0, calculate_parity1(12345));  // 0011000000111001
}

TEST(PARITIES, testCalculateParity2) {
  EXPECT_EQ(0, calculate_parity2(0));  // 0000000000000000
  EXPECT_EQ(1, calculate_parity2(1));  // 0000000000000001
  EXPECT_EQ(0, calculate_parity2(12345));  // 0011000000111001
}

TEST(PARITIES, testCalculateParity3) {
  EXPECT_EQ(0, calculate_parity3(0));  // 0000000000000000
  EXPECT_EQ(1, calculate_parity3(1));  // 0000000000000001
  EXPECT_EQ(0, calculate_parity3(12345));  // 0011000000111001
}
