#pragma once
#include <limits>

// #include "s21_rb_tree.hpp"
#include "../s21_sorted_containers.hpp"

namespace s21 {

// template <typename T>
// class set_iterator {
//  private:
//   using value_type = T;
//   using reference = value_type &;
//   using Node = typename sorted_container<T>::Node;

//   Node *node;

//   Node *next_node(Node *) const;

//  public:
//   set_iterator() : node(nullptr) {};
//   set_iterator(Node *other) : node(other) {};
//   ~set_iterator() {};

//   bool operator==(const set_iterator &s) const { return (node == s.node); };
//   bool operator!=(const set_iterator &s) const { return (node != s.node); };
//   reference operator*() const { return node->data; };
//   set_iterator &operator++();
// };

template <typename T>
class set : private sorted_container<T> {
 protected:
  using value_type = T;
  using key_type = typename sorted_container<value_type>::rb_tree;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename sorted_container<value_type>::iterator;
  using const_iterator = const typename sorted_container<value_type>::iterator;
  using size_type = std::size_t;

  key_type *tree;
  size_type m_size;

  void copy(const set &other) { tree->copy_tree(other.tree); };

 public:
  set() : tree(new key_type()), m_size(0) {};
  set(std::initializer_list<value_type> const &);
  set(const set &s) : tree(new key_type()), m_size(s.m_size) { copy(s); };
  set(set &&s) : tree(s), m_size(s.m_size) { s.tree = nullptr, s.m_size = 0; };
  ~set() { delete tree; };

  set<value_type> &operator=(const set &);
  set<value_type> &operator=(set &&) noexcept;

  void clear();
  pair<iterator, bool> insert(const_reference);
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
  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  };
};

}  // namespace s21

// #include "s21_set.tpp"