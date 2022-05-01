#ifndef TEST_FIXTURE_HPP_
#define TEST_FIXTURE_HPP_

#include <memory>
#include <string>
#include <gtest/gtest.h>
#include "list/list.hpp"


using IntegerList = std::shared_ptr<ListNode<int>>;


static void EXPECT_LIST_EQ(const std::string& expected, IntegerList node) {
  std::string actual = "";
  if (node) {
    actual += std::to_string(node->data);
  }
  node = node->next;
  while (node) {
    actual += " " + std::to_string(node->data);
    node = node->next;
  }
  EXPECT_EQ(expected, actual);
}

#endif // TEST_FIXTURE_HPP_
