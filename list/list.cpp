#include <memory>
#include <gtest/gtest.h>
#include "list/list.hpp"

class ListTest : public ::testing::Test {
protected:
  void SetUp() override {
    node = make_list_node(123);
    append(node, make_list_node(456));
  }

  std::shared_ptr<ListNode<int>> node;
};

TEST_F(ListTest, testMakeListNode) {
  EXPECT_EQ(123, node->data);
}

TEST_F(ListTest, testAppendNode) {
  EXPECT_EQ(456, node->next->data);
}

TEST_F(ListTest, testRemoveNextNode) {
  removeNext(node);
  EXPECT_EQ(nullptr, node->next);
  removeNext(node);
  EXPECT_EQ(nullptr, node->next);
}
