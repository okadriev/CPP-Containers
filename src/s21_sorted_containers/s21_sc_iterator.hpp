#pragma once
#include <type_traits>

#include "s21_tree_node.hpp"

namespace s21 {
template <typename T>
class Iterator {
 private:
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using node_t = Node<T>;

  node_t *node_;

  node_t *next_node(node_t *node) const;

 public:
  Iterator() : node_(nullptr){};
  Iterator(node_t *node) : node_(node){};
  ~Iterator(){};

  bool operator==(const Iterator &s) const { return (node_ == s.node_); };
  bool operator!=(const Iterator &s) const { return (node_ != s.node_); };
  reference operator*() const { return node_->data; };
  Iterator &operator++() {
    node_ = next_node(node_);
    return *this;
  };
};

template <typename T>
inline Node<T> *Iterator<T>::next_node(node_t *node) const {
  node_t *next = nullptr;

  if (node->right) {
    next = node->right;
    while (next->left) next = next->left;

  } else {
    next = node->parent;
    while (next && node == next->right) {
      node = next;
      next = next->parent;
    }
  }

  return next;
};

}  // namespace s21
