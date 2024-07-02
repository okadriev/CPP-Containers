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

template <typename T>
class sorted_container {
 protected:
  using value_type = T;
  using iterator = Iterator<value_type>;
  using tree_t = rb_tree<value_type>;
  using iter_pair_return = pair<iterator, bool>;

  tree_t *tree_;
  std::size_t m_size_;

  void merge(iterator, iterator);
  void swap(tree_t &, std::size_t &) noexcept;
  bool contains(const value_type &key);
  void erase(value_type const &);

 public:
  sorted_container() : tree_(new tree_t()), m_size_(0) {}
  sorted_container(std::initializer_list<value_type> const &);
  ~sorted_container() { delete tree_; }

  pair<iterator, bool> insert(value_type &&value);
  pair<iterator, bool> insert(const value_type &value);
  void insert(std::initializer_list<T> items);

  iterator find(const value_type &key);

  void clear();

  iterator begin() const { return iterator(this->tree_->min()); }
  iterator end() const { return iterator(nullptr); }
  std::size_t size() const { return this->m_size_; }
  std::size_t max_size() const;
  bool empty() const { return this->tree_->empty(); }
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

template <typename value_type>
sorted_container<value_type>::sorted_container(
    std::initializer_list<value_type> const &items)
    : sorted_container() {
  insert(items);
}

template <typename T>
void sorted_container<T>::insert(std::initializer_list<T> items) {
  for (const auto &item : items) insert(item);
}

template <typename T>
typename sorted_container<T>::iter_pair_return sorted_container<T>::insert(
    value_type &&value) {
  bool result = false;
  if (!contains(value)) {
    tree_->insert(value);
    result = true;
    m_size_++;
  }
  return {find(value), result};
}

template <typename T>
pair<Iterator<T>, bool> sorted_container<T>::insert(const value_type &value) {
  value_type rvalue(value);
  return insert(std::move(rvalue));
}

template <typename T>
typename sorted_container<T>::iterator sorted_container<T>::find(
    const value_type &key) {
  return iterator(this->tree_->search(key));
}

template <typename T>
bool sorted_container<T>::contains(const value_type &key) {
  return find(key) != end();
}

template <typename T>
void sorted_container<T>::erase(const value_type &key) {
  this->tree_->remove(key);
  this->m_size_--;
}

template <typename T>
void sorted_container<T>::clear() {
  while (this->begin() != this->end()) {
    erase((*this->begin()));
  }
}

template <typename T>
void sorted_container<T>::merge(iterator it, iterator end) {
  for (; it != end; ++it) {
    this->insert(*it);
  }
}

template <typename T>
std::size_t sorted_container<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <class T>
void sorted_container<T>::swap(tree_t &o_tree, std::size_t &o_m_size) noexcept {
  std::swap(this->tree_, o_tree);
  std::swap(this->m_size_, o_m_size);
}

}  // namespace s21

#include "s21_rb_tree.tpp"
