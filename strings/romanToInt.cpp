#include <map>
#include <string>
#include <gtest/gtest.h>

std::map<char, int> T = {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000},
};

int getRomanToInteger(const std::string& s) {
  int sum = T[s.back()];
  for (int i = s.length() - 2; i >= 0; i--) {
    if (T[s[i]] < T[s[i + 1]]) {
      sum -= T[s[i]];
    } else {
      sum += T[s[i]];
    }
  }
  return sum;
}


TEST(ROMAN_TO_INTEGER, testGetRomanToInteger) {
  EXPECT_EQ(1, getRomanToInteger("I"));
  EXPECT_EQ(5, getRomanToInteger("V"));
  EXPECT_EQ(10, getRomanToInteger("X"));
  EXPECT_EQ(50, getRomanToInteger("L"));
  EXPECT_EQ(100, getRomanToInteger("C"));
  EXPECT_EQ(500, getRomanToInteger("D"));
  EXPECT_EQ(1000, getRomanToInteger("M"));
  
  EXPECT_EQ(59, getRomanToInteger("LIX"));
  EXPECT_EQ(59, getRomanToInteger("LVIIII"));
}
