#include <memory>
#include <string>
#include <gtest/gtest.h>
#include "fixture.hpp"
#include "list/list.hpp"

class ListTest : public ::testing::Test {
protected:
  void SetUp() override {
    node = newList(123, 456);
  }

  IntegerList node;
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

TEST_F(ListTest, testLength) {
  IntegerList empty;
  EXPECT_EQ(0, length(empty));
  EXPECT_EQ(2, length(node));
}

TEST_F(ListTest, testMakeList) {
  node = newList(3, 2, 1);
  EXPECT_EQ(3, length(node));
  EXPECT_EQ(3, node->data);
  EXPECT_EQ(2, node->next->data);
  EXPECT_EQ(1, node->next->next->data);
  EXPECT_LIST_EQ("3 2 1", node);
}
