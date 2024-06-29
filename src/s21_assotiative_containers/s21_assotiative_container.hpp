#pragma once

// #include <utility>

#include "../s21_sorted_container.hpp"
#include "s21_pair.hpp"

namespace s21 {

template <typename T1, typename T2>
class associative_container : sorted_container<key_pair<T1, T2>> {
  using key_type = T1;
  using value_type = T2;
  using pair_type = key_pair<key_type, value_type>;
  using tree_type = rb_tree<pair_type>;
  using size_t = std::size_t;
  using node_type = Node<pair_type>;
  using iterator = typename sorted_container<pair_type>::iterator;
  using reference = value_type &;
  using const_reference = const value_type &;

  virtual ~associative_container() = default;

 public:
  virtual void insert(const key_type &key, const value_type &value) = 0;
  virtual void erase(const key_type &key) = 0;
  virtual value_type &find(const key_type &key) = 0;
  virtual bool contains(const key_type &key) const = 0;
  virtual void clear() = 0;

  virtual iterator find(const_reference data) = 0;
  bool contains(const_reference data) { return find(data) != end(); };
  iterator begin() const { return iterator(tree->min()); };
  iterator end() const { return iterator(nullptr); };

  bool empty() const { return tree->empty(); };
  virtual size_t size() const = 0;

 private:
  tree_type tree_;
  size_t m_size = 0;
};

}  // namespace s21

// #include "s21_assotiative_container.tpp"
