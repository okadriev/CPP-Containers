#pragma once
#include <limits>

#include "../s21_sorted_containers/s21_sorted_containers.hpp"

namespace s21 {

template <typename T>
class set : public sorted_container<T> {
 protected:
  using value_type = T;
  using key_type = rb_tree<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using container = sorted_container<value_type>;

 public:
  using iterator = Iterator<T>;
  using const_iterator = const Iterator<T>;

  set() : container(false) {};
  set(bool multi) : container(multi) {};
  set(std::initializer_list<value_type> const &items)
      : container(items, false) {};

  set(const set &other) : container(other) {};
  set(set &&other) : container(other) {};

  set(std::initializer_list<value_type> const &items, bool multi)
      : container(items, multi) {};

  ~set() {};

  set<value_type> &operator=(const set &);
  set<value_type> &operator=(set &&) noexcept;
};

}  // namespace s21

#include "s21_set.tpp"
