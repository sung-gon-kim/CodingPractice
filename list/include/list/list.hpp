#ifndef INCLUDE_LIST_LIST_HPP_
#define INCLUDE_LIST_LIST_HPP_

#include <iostream>
#include <memory>

template <typename T>
struct ListNode {
  T data;
  std::shared_ptr<ListNode<T>> next;
};


template <typename T>
std::shared_ptr<ListNode<T>> search(const std::shared_ptr<ListNode<T>>& node, T data) {
  while (node && node->data != data) {
    node = node->next;
  }
  return node;
}

template <typename T>
std::shared_ptr<ListNode<T>> append(std::shared_ptr<ListNode<T>> node, std::shared_ptr<ListNode<T>> newNode) {
  newNode->next = node->next;
  node->next = newNode;
  return node;
}

template <typename T>
std::shared_ptr<ListNode<T>> newList(T data) {
  auto node = std::make_shared<ListNode<T>>();
  node->data = data;
  return node;
}

template <typename T, typename... Types>
std::shared_ptr<ListNode<T>> newList(T data, Types... args) {
  auto node = newList(data);
  node->next = newList(args...);
  return node;
}

template <typename T>
void removeNext(std::shared_ptr<ListNode<T>> node) {
  if (node->next) {
    node->next = node->next->next;
  }
}

template <typename T>
std::size_t length(const std::shared_ptr<ListNode<T>>& node) {
  std::size_t size = 0;
  std::shared_ptr<ListNode<T>> current = node;
  while (current) {
    size++;
    current = current->next;
  }
  return size;
}

#endif  // INCLUDE_LIST_LIST_HPP_
