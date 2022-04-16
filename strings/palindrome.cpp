#include <string>
#include <gtest/gtest.h>

bool isPalindrome(const std::string& s) {
  for (std::size_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}


TEST(PALINDROME, testIsPalindrome) {
  EXPECT_TRUE(isPalindrome("level"));
  EXPECT_FALSE(isPalindrome("hello"));
}
