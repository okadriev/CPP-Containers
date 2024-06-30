#pragma once
#include <limits>

#include "s21_rb_tree.hpp"

namespace s21 {

template <typename T>
class set_iterator {
 private:
  using value_type = T;
  using reference = value_type &;

  Node<value_type> *node;

  Node<value_type> *next_node(Node<value_type> *) const;

 public:
  set_iterator() : node(nullptr){};
  set_iterator(Node<value_type> *other) : node(other){};
  ~set_iterator(){};

  bool operator==(const set_iterator &s) const { return (node == s.node); };
  bool operator!=(const set_iterator &s) const { return (node != s.node); };
  reference operator*() const { return node->data; };
  set_iterator &operator++();
};

template <typename T>
class set {
 protected:
  using value_type = T;
  using key_type = rb_tree<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = set_iterator<T>;
  using const_iterator = const set_iterator<T>;
  using size_type = size_t;

  key_type *tree;
  size_type m_size;

  void copy(const set &other) { tree->copy_tree(other.tree); };

 public:
  set() : tree(new key_type()), m_size(0){};
  set(std::initializer_list<value_type> const &);
  set(const set &s) : tree(new key_type()), m_size(s.m_size) { copy(s); };
  set(set &&s) : tree(s), m_size(s.m_size) { s.tree = nullptr, s.m_size = 0; };
  ~set() { delete tree; };

  set<value_type> &operator=(const set &);
  set<value_type> &operator=(set &&) noexcept;

  void clear();
  std::pair<iterator, bool> insert(const_reference);
  void erase(const_reference);
  void erase(iterator);
  void swap(set &);
  void merge(set &);

  void print() { tree->print_tree(); };
  iterator find(const_reference data) { return iterator(tree->search(data)); };
  bool contains(const_reference data) { return find(data) != end(); };
  iterator begin() const { return iterator(tree->min()); };
  iterator end() const { return iterator(nullptr); };

  bool empty() const { return tree->empty(); };
  size_type size() const { return m_size; };
  size_t max_size() const noexcept {
    return std::numeric_limits<size_t>::max() / sizeof(value_type);
  };
};

template <typename T>
set_iterator<T> &set_iterator<T>::operator++() {
  node = next_node(node);

  return *this;
}

template <typename T>
Node<T> *set_iterator<T>::next_node(Node<T> *ptr_node) const {
  if (ptr_node == nullptr) return nullptr;

  Node<T> *next = nullptr;

  if (ptr_node->right) {
    next = ptr_node->right;
    while (next->left) next = next->left;

  } else {
    next = ptr_node->parent;
    while (next && ptr_node == next->right) {
      ptr_node = next;
      next = next->parent;
    }
  }

  return next;
};

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set() {
  for (const auto &item : items) insert(item);
  m_size = items.size();
};

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set &other) {
  if (this != &other) {
    delete tree;

    tree = new key_type();
    m_size = other.m_size;
    tree->copy_tree(other.tree);
  }

  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set &&other) noexcept {
  if (this != &other) {
    delete tree;

    tree = other.tree;
    m_size = other.m_size;
    other.m_size = 0;
    other.tree = nullptr;
  }

  return *this;
}

template <typename value_type>
void set<value_type>::clear() {
  tree->delete_tree();
  m_size = 0;
}

template <typename value_type>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const_reference data) {
  bool result = false;
  iterator ptr = nullptr;

  if (!contains(data)) {
    ptr = tree->insert(data);
    ++m_size;

    result = true;
  }

  return std::make_pair(ptr, result);
}

template <typename value_type>
void set<value_type>::erase(const_reference data) {
  if (contains(data)) {
    tree->remove(data);
    --m_size;
  }
};

template <typename value_type>
void set<value_type>::erase(iterator ptr) {
  if (ptr != end() && contains(*ptr)) {
    tree->remove(*ptr);
    --m_size;
  }
};

template <typename value_type>
void set<value_type>::swap(set &other) {
  std::swap(tree, other.tree);
  std::swap(m_size, other.m_size);
}

template <typename value_type>
void set<value_type>::merge(set &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

}  // namespace s21

#include "s21_set.tpp"