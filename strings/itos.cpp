#include <string>
#include <gtest/gtest.h>

std::string itos(int x) {
  bool isNegative = (x < 0) ? true : false;
  std::string s;
  do {
    s += '0' + abs(x % 10);
    x /= 10;
  } while (x);
  s += isNegative ? "-" : "";
  return { std::rbegin(s), std::rend(s) };
}


TEST(INTTOSTRING, testitos) {
  EXPECT_EQ("123", itos(123));
  EXPECT_EQ("-123", itos(-123));
}
