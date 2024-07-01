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
class Iterator {
 private:
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using node_t = Node<T>;

  node_t *node_;

  node_t *next_node(node_t *node) const;

 public:
  Iterator() : node_(nullptr) {};
  Iterator(node_t *node) : node_(node) {};
  ~Iterator() {};

  bool operator==(const Iterator &s) const { return (node_ == s.node_); };
  bool operator!=(const Iterator &s) const { return (node_ != s.node_); };
  reference operator*() const { return node_->data; };
  Iterator &operator++() {
    node_ = next_node(node_);
    return *this;
  };
};

template <typename T>
class rb_tree {
 private:
  using node_t = Node<T>;
  using iterator = Iterator<T>;

  node_t *root;

  node_t *copy_node(node_t *);
  void remove_node(node_t *);
  void delete_tree(node_t *);
  void rotate_left(node_t *&);
  void rotate_right(node_t *&);

  void fix_2_red(node_t *&);
  void fix_2_black(node_t *&);
  std::size_t count_elements(node_t *node, const T &data) const;
  pair<node_t *, node_t *> element_range(node_t *node, const T &data);

 public:
  rb_tree() : root(nullptr) {}
  rb_tree(const rb_tree *other) { copy_tree(other); }
  ~rb_tree() { delete_tree(); }

  void delete_tree() { delete_tree(root), root = nullptr; }

  void copy_tree(const rb_tree *);
  node_t *insert(const T &);
  void remove(const T &);
  node_t *min() const;
  node_t *search(const T &) const;
  bool empty() const { return (this == nullptr) || root == nullptr; };

  std::size_t count(const T &) const;
  pair<node_t *, node_t *> equal_range(const T &);
  iterator make_iterator(node_t *node) { return iterator(node); }
};

template <typename T, class C>
class sorted_container {
 protected:
  using value_type = T;
  using container = C;
  using iterator = Iterator<value_type>;
  using tree_t = rb_tree<value_type>;

  tree_t *tree_;
  std::size_t m_size_;

 public:
  sorted_container() : tree_(new tree_t()), m_size_(0) {}
  sorted_container(std::initializer_list<value_type> const &);
  sorted_container(const container &);
  sorted_container(container &&);

  ~sorted_container() { delete tree_; }

  tree_t *tree() { return tree_; }
};

template <typename T>
inline Node<T> *Iterator<T>::next_node(node_t *node) const {
  if (node == nullptr) return nullptr;

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

template <typename value_type, class container>
sorted_container<value_type, container>::sorted_container(
    std::initializer_list<value_type> const &items)
    : sorted_container() {
  insert(items);
}
template <typename value_type>
sorted_container<value_type>::sorted_container(
    const sorted_container<value_type> &other)
    : sorted_container() {
  this->m_size_ = other.size();
  this->tree_->copy_tree(other.tree_);
}

template <typename value_type>
sorted_container<value_type>::sorted_container(
    sorted_container<value_type> &&other)
    : sorted_container() {
  delete this->tree_;
  this->tree_ = other.tree_;
  this->m_size_(other.m_size_);
  other.tree_ = nullptr;
  other.m_size_ = 0;
}

}  // namespace s21

#include "s21_rb_tree.tpp"
