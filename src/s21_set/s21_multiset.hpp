#pragma once
#include "s21_set.hpp"

namespace s21 {

template <typename T>
class multiset : public set<T> {
 private:
  using value_type = T;
  using const_reference = const T &;
  using size_t = std::size_t;

 public:
  using iterator = Iterator<T>;

  multiset() : set<T>(true) {};
  multiset(std::initializer_list<T> const &items) : set<T>(items, true) {};

  size_t count(const_reference num) const { return this->tree_->count(num); };
  pair<iterator, iterator> equal_range(const_reference);
  iterator lower_bound(const_reference);
  iterator upper_bound(const_reference);
};

}  // namespace s21

#include "s21_multiset.tpp"
