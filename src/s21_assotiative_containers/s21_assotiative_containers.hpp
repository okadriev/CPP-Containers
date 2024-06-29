#pragma once

#include <limits>
#include <utility>

#include "../s21_sorted_containers.hpp"
#include "s21_pair.hpp"

namespace s21 {

template <typename T1, typename T2>
class associative_container : sorted_container<key_pair<T1, T2>> {
  using key_type = T1;
  using value_type = T2;
  using iterator =
      typename sorted_container<key_pair<key_type, value_type>>::iterator;
  using reference = key_pair<key_type, value_type> &;
  using const_reference = const key_pair<key_type, value_type> &;

  virtual ~associative_container() = default;

 public:
  virtual void insert(const key_type &key, const value_type &value) = 0;
  virtual void erase(const key_type &key) = 0;
  virtual bool contains(const key_type &key) const = 0;
  virtual void clear() = 0;

  virtual iterator find(const_reference &pair) = 0;
  virtual bool contains(const_reference &pair) = 0;
  virtual iterator begin() const = 0;
  virtual iterator end() const = 0;
};

}  // namespace s21

// #include "s21_assotiative_container.tpp"
