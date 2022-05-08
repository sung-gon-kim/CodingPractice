#include <map>
#include <stack>
#include <string>
#include <gtest/gtest.h>

bool isValid(const std::string& s) {
  std::stack<char> chars;
  const std::map<char, char> lookup = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'},
  };
  for (std::size_t i = 0; i < s.size(); i++) {
    if (lookup.count(s[i])) {
      chars.emplace(s[i]);
    } else {
      if (chars.empty() || lookup.at(chars.top()) != s[i]) {
	return false;
      }
      chars.pop();
    }
  }
  return chars.empty();
}

TEST(Bracket, testisValid) {
  EXPECT_TRUE(isValid("([]){()}"));
  EXPECT_FALSE(isValid("[()[]{()()"));
}
