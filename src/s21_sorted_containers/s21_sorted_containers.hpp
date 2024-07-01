#pragma once

#include "../s21_pair.hpp"

namespace s21 {

template <typename T>
struct Node {
  T data;
  Node<T> *left, *right, *parent;
  bool is_red;  // поменять на int black?

  Node(T data = 0)
      : data(data),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_red(true) {}
};

template <typename T>
class iterator {
 private:
  using value_type = T;
  using pointer = T *;
  using reference = T &;

  Node<T> *node_;

  Node<T> *next_node(Node<T> *node) const;

 public:
  iterator() : node_(nullptr) {};
  iterator(Node<T> *node) : node_(node) {};
  ~iterator() {};

  bool operator==(const iterator &s) const { return (node_ == s.node_); };
  bool operator!=(const iterator &s) const { return (node_ != s.node_); };
  reference operator*() const { return node_->data; };
  iterator &operator++() {
    node_ = next_node(node_);
    return *this;
  };
};

template <typename T>
class rb_tree {
 private:
  Node<T> *root;

  Node<T> *copy_node(Node<T> *);
  void remove_node(Node<T> *);
  void delete_tree(Node<T> *);
  void rotate_left(Node<T> *&);
  void rotate_right(Node<T> *&);

  void fix_2_red(Node<T> *&);
  void fix_2_black(Node<T> *&);
  std::size_t count_elements(Node<T> *node, const T &data) const;
  pair<Node<T> *, Node<T> *> element_range(Node<T> *node, const T &data);

 public:
  rb_tree() : root(nullptr) {}
  rb_tree(const rb_tree *other) { copy_tree(other); }
  ~rb_tree() { delete_tree(); }

  void delete_tree() { delete_tree(root), root = nullptr; }

  void copy_tree(const rb_tree *);
  Node<T> *insert(const T &);
  void remove(const T &);
  Node<T> *min() const;
  Node<T> *search(const T &) const;
  bool empty() const { return (this == nullptr) || root == nullptr; };

  std::size_t count(const T &) const;
  pair<Node<T> *, Node<T> *> equal_range(const T &);
  iterator make_iterator(Node<T> *node) { return iterator(node); }
};

template <typename T>
class sorted_container {
 public:
  using iterator = typename rb_tree<T>::iterator;
  rb_tree<T> tree_;
  std::size_t m_size_;
};

template <typename T>
inline Node<T> *iterator<T>::next_node(Node<T> *node) const {
  if (node == nullptr) return nullptr;

  Node *next = nullptr;

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

#include "s21_rb_tree.tpp"
