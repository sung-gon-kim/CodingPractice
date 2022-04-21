#include <string>
#include <gtest/gtest.h>

std::string getNextNumber(const std::string& s) {
  std::string result;
  for (int i = 0; i < s.size(); i++) {
    int count = 1;
    while (i + 1 < s.size() && s[i] == s[i + 1]) {
      i++;
      count++;
    }
    result += std::to_string(count) + s[i];
  }
  return result;
}

std::string getLookAndSay(int n) {
  std::string s = "1";
  for (int i = 1; i < n; i++) {
    s = getNextNumber(s);
  }
  return s;
}


TEST(LOOK_AND_SAY, testGetLookAndSay) {
  EXPECT_EQ("1", getLookAndSay(1));
  EXPECT_EQ("1211", getLookAndSay(4));
  EXPECT_EQ("1113213211", getLookAndSay(8));
}
