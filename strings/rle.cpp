#include <string>
#include <gtest/gtest.h>

std::string encode(const std::string& s) {
  std::string result;
  int count = 1;
  for (int i = 1; i <= s.size(); i++) {
    if (i == s.size() || s[i] != s[i - 1]) {
      result += std::to_string(count) + s[i - 1];
      count = 1;
    } else {
      count++;
    }
  }
  return result;
}

std::string decode(const std::string& s) {
  int count = 0;
  std::string result;
  for (auto c: s) {
    if (std::isdigit(c)) {
      count = count * 10 + c - '0';
    } else {
      result.append(count, c);
      count = 0;
    }
  }
  return result;
}

TEST(RUN_LENGTH, testEncode) {
  EXPECT_EQ("4a1b3c2a", encode("aaaabcccaa"));
}

TEST(RUN_LENGHT, testDecode) {
  EXPECT_EQ("aaaabcccaa", decode("4a1b3c2a"));
}
