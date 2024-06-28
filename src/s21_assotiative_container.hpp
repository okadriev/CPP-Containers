#pragma once

// #include <utility>

// #include "s21_containers.hpp"
#include "../s21_set/s21_rb_tree.cpp"
#include "s21_containers.hpp"
#include "s21_greater.hpp"
#include "s21_pair.hpp"

namespace s21 {
template <typename Key, typename Value>
class associative_container : container<rb_tree<pair<Key, Value*>>> {
  using Tree = rb_tree<pair<Key, Value*>>;
  using iterator = typename Tree::iterator;

 public:
  virtual ~associative_container() = default;

  virtual void insert(const Key& key, const Value& value) = 0;
  virtual void erase(const Key& key) = 0;
  virtual bool contains(const Key& key) const = 0;
  virtual Value& at(const Key& key) = 0;
  virtual const Value& at(const Key& key) const = 0;
  virtual void clear() = 0;
};
}  // namespace s21
