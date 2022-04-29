#ifndef INCLUDE_LIST_LIST_HPP_
#define INCLUDE_LIST_LIST_HPP_

#include <memory>

template <typename T>
struct ListNode {
  T data;
  std::shared_ptr<ListNode<T>> next;
};


template <typename T>
std::shared_ptr<ListNode<T>> search(std::shared_ptr<ListNode<T>> list, T data) {
  while (list && list->data != data) {
    list = list->next;
  }
  return list;
}

template <typename T>
std::shared_ptr<ListNode<T>> make_list_node(T data) {
  std::shared_ptr<ListNode<T>> node = std::make_shared<ListNode<T>>();
  node->data = data;
  return node;
}

template <typename T>
void append(std::shared_ptr<ListNode<T>> node, std::shared_ptr<ListNode<T>> newNode) {
  newNode->next = node->next;
  node->next = newNode;
}

template <typename T>
void removeNext(std::shared_ptr<ListNode<T>> node) {
  if (node->next) {
    node->next = node->next->next;
  }
}

template <typename T>
std::size_t length(std::shared_ptr<ListNode<T>> node) {
  std::size_t size = 0;
  std::shared_ptr<ListNode<T>> current = node;
  while (current) {
    size++;
    current = current->next;
  }
  return size;
}

#endif  // INCLUDE_LIST_LIST_HPP_
