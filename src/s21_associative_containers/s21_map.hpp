#pragma once
#include "s21_associative_containers/s21_associative_containers.hpp"

namespace s21 {

template <typename T1, typename T2>
class map : public associative_container<pair<T1, T2>> {
 private:
  using key_type = T1;
  using data_type = T2;
  using value_type = pair<key_type, data_type>;
  using tree_type = typename sorted_container<value_type>::rb_tree;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;

  tree_type *tree;
  size_type m_size;

 public:
  using iterator = typename sorted_container<value_type>::iterator;
  using const_iterator = const typename sorted_container<value_type>::iterator;

  map() : tree(new tree_type()), m_size(0) {};
  map(std::initializer_list<value_type> const &);
  map(const map &s) : tree(new key_type()), m_size(s.m_size) {
    tree->copy_tree(other.tree);
  };
  map(map &&s) : tree(s), m_size(s.m_size) { s.tree = nullptr, s.m_size = 0; };
  ~map() { delete tree; };

  void insert(const key_type &, const value_type &);
  void erase(const key_type &);
  bool contains(const key_type &) const;
  void clear();

  iterator find(const_reference &);
  bool contains(const_reference &);
  iterator begin() const;
  iterator end() const;

  size_t size() const;
  bool empty() const;
};

}  // namespace s21
