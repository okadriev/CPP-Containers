#pragma once
#include "s21_rb_tree.hpp"
#include "s21_set.hpp"

namespace s21 {

template <typename T>
class multiset : public set<T> {
 private:
  using value_type = T;
  using const_reference = const T &;
  using iterator = set_iterator<value_type>;
  using size_type = size_t;

 public:
  multiset(std::initializer_list<T> const &);

  std::pair<iterator, bool> insert(const_reference);

  size_type count(const_reference num) const { return this->tree->count(num); };
  std::pair<iterator, iterator> equal_range(const_reference);
  iterator lower_bound(const_reference);
  iterator upper_bound(const_reference);
};

}  // namespace s21