#pragma once

// #include <utility>

// #include "s21_containers.hpp"
#include "../s21_set/s21_rb_tree.cpp"
#include "s21_greater.hpp"
#include "s21_pair.hpp"

namespace s21 {
template <typename T1, typename T2>
class associative_container {
  using key_t = T1;
  using value_t = T2;
  using data_t = pair<key_t, value_t>;

 public:
  virtual ~associative_container() = default;

  virtual void insert(const key_t& key, const data_t& value) = 0;
  virtual void erase(const key_t& key) = 0;
  virtual bool contains(const key_t& key) const = 0;
  virtual data_t& at(const key_t& key) = 0;
  virtual const data_t& at(const key_t& key) const = 0;
  virtual void clear() = 0;
  virtual std::size_t size() const = 0;
  virtual bool empty() const = 0;
};
}  // namespace s21
