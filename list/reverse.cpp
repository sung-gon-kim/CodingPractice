#include <memory>
#include <stack>
#include <string>
#include <gtest/gtest.h>
#include "fixture.hpp"
#include "list/list.hpp"

IntegerList reverseList(IntegerList node, int start, int end) {
  auto dummy_head = std::make_shared<ListNode<int>>();
  dummy_head->data = 0;
  dummy_head->next = node;
  auto sublist_head = dummy_head;
  int skipped = 1;
  while (skipped++ < start) {
    sublist_head = sublist_head->next;
  }
  auto sublist_iter = sublist_head->next;
  while (start++ < end) {
    auto temp = sublist_iter->next;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
  }
  return dummy_head->next;
}

TEST(Reverse, testReverseList) {
  auto node = newList(1, 2, 3, 4, 5);
  EXPECT_LIST_EQ("1 4 3 2 5", reverseList(node, 2, 4));
}

std::string reversed(IntegerList node) {
  std::string s;
  std::stack<int> stack;
  while (node) {
    stack.push(node->data);
    node = node->next;
  }
  if (!stack.empty()) {
    s += std::to_string(stack.top());
    stack.pop();
  }
  while (!stack.empty()) {
    s += " " + std::to_string(stack.top());
    stack.pop();
  }
  return s;
}

TEST(Reverse, testReversed) {
  auto node = newList(1, 2, 3, 4, 5);
  EXPECT_EQ("5 4 3 2 1", reversed(node));
}
