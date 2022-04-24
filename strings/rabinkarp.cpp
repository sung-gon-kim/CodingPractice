#include <string>
#include <gtest/gtest.h>

int getSubStr(const std::string& t, const std::string& s) {
  if (s.size() > t.size()) {
    return -1;
  }
  const int BASE = 26;
  int hash_t = 0;
  int hash_s = 0;
  int power = 1;
  
  for (int i = 0; i < s.size(); i++) {
    power = i ? power * BASE : 1;
    hash_t = hash_t * BASE + t[i];
    hash_s = hash_s * BASE + s[i];
  }
  
  for (int i = s.size(); i < t.size(); i++) {
    if (hash_t == hash_s && !t.compare(i - s.size(), s.size(), s)) {
      return i - s.size();
    }
    hash_t -= t[i - s.size()] * power;
    hash_t = hash_t * BASE + t[i];
  }

  if (hash_t == hash_s && t.compare(t.size() - s.size(), s.size(), s) == 0) {
    return t.size() - s.size();
  }

  return -1;
}

TEST(RABIN_KARP, testGetSubStr) {
  EXPECT_EQ(-1, getSubStr("hello world!", "wow"));
  EXPECT_EQ(-1, getSubStr("greeting", "hello world!"));
  EXPECT_EQ(0, getSubStr("hello", "hello"));
  EXPECT_EQ(0, getSubStr("hello world!", "hello"));
  EXPECT_EQ(6, getSubStr("hello world!", "world"));
}
