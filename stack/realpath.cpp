#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>

std::string realpath(const std::string& path) {
  if (path.empty()) {
    throw std::invalid_argument("Empty string");
  }
  std::vector<std::string> paths;
  if (path.front() == '/') {
    paths.emplace_back("/");
  }
  std::stringstream ss(path);
  std::string token;
  while (std::getline(ss, token, '/')) {
    if (token == "..") {
      if (paths.empty() || paths.back() == "..") {
	paths.emplace_back(token);
      } else {
	if (paths.back() == "/") {
	  throw std::invalid_argument("Path error");
	}
	paths.pop_back();
      }
    } else if (token != "." && token != "") {
      paths.emplace_back(token);
    }
  }
  std::string result;
  if (!paths.empty()) {
    result = paths.front();
    for (int i = 1; i < paths.size(); i++) {
      if (i == 1 && result == "/") {
	result += paths[i];
      } else {
	result += "/" + paths[i];
      }
    }
  }
  return result;
}

TEST(Realpath, testRealPath) {
  EXPECT_EQ("/usr/bin/gcc", realpath("/usr/bin/gcc"));
  EXPECT_EQ("/usr/bin/gcc", realpath("/usr/lib/../bin/gcc"));
  EXPECT_EQ("script/test.sh", realpath("scripts//./../script/test.sh/./."));
}
