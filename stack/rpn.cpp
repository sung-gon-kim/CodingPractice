#include <functional>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <gtest/gtest.h>

int evaluate(const std::string& expression) {
  std::stack<int> temp;
  std::stringstream ss(expression);
  std::string token;
  const char delimiter = ',';
  const std::map<std::string, std::function<int(int, int)>> operators = {
    {"+", [](int x, int y) { return x + y; }},
    {"-", [](int x, int y) { return x - y; }},
    {"*", [](int x, int y) { return x * y; }},
    {"/", [](int x, int y) { return x / y; }},
  };
  while (std::getline(ss, token, delimiter)) {
    if (operators.count(token)) {
      const int y = temp.top();
      temp.pop();
      const int x = temp.top();
      temp.pop();
      temp.emplace(operators.at(token)(x, y));
    } else {
      temp.emplace(std::stoi(token));
    }
  }
  return temp.top();
}

TEST(RPN, testEvaluate) {
  EXPECT_EQ(3, evaluate("1,2,+"));
  EXPECT_EQ(15, evaluate("3,4,+,2,*,1,+"));
}
