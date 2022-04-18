#include <numeric>
#include <string>
#include <gtest/gtest.h>

int getColumnToNumber(const std::string& s) {
  return std::accumulate(s.begin(), s.end(), 0, [](int result, char c) {
      return result * 26 + c - 'A' + 1;
    });
}

TEST(COLUMN_TO_NUMBER, testColToNum) {
  EXPECT_EQ(4, getColumnToNumber("D"));
  EXPECT_EQ(27, getColumnToNumber("AA"));
  EXPECT_EQ(702, getColumnToNumber("ZZ"));
}
