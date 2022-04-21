#include <algorithm>
#include <cstddef>
#include <string>
#include <gtest/gtest.h>

std::string getReversedWords(const std::string& s) {
  std::string reversed = { s.rbegin(), s.rend() };
  std::size_t first = 0;
  std::size_t last = SIZE_MAX;
  while ((last = reversed.find(" ", first)) != std::string::npos) {
    std::reverse(reversed.begin() + first, reversed.begin() + last);
    first = last + 1;
  }
  std::reverse(reversed.begin() + first, reversed.end());
  return reversed;
}

TEST(REVERSED_WORDS, testGetReversedWords) {
  EXPECT_EQ("Bob likes Alice", getReversedWords("Alice likes Bob"));
}
