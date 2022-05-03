#include <memory>
#include <string>
#include <gtest/gtest.h>
#include "fixture.hpp"
#include "list/list.hpp"

void appendNode(IntegerList *node, IntegerList *tail) {
  (*tail)->next = *node;
  *tail = *node;
  *node = (*node)->next;
}

IntegerList mergeTwoSortedLists(IntegerList first, IntegerList second) {
  auto dummy_head = std::make_shared<ListNode<int>>();
  auto tail = dummy_head;
  while (first && second) {
    appendNode(first->data <= second->data ? &first : &second, &tail);
  }
  tail->next = first ? first : second;
  return dummy_head->next;
}

TEST(Merge, testMergeTwoSortedLists) {
  auto first = newList(1, 2, 3);
  auto second = newList(4, 5, 6);
  EXPECT_LIST_EQ("1 2 3 4 5 6", mergeTwoSortedLists(first, second));
}
