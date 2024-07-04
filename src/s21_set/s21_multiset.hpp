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
  using iterator = typename sorted_container<value_type>::iterator;

  multiset() : set<T>() { this->multi_container(); }
  multiset(std::initializer_list<T> const &items) : set<T>() {
    this->multi_container();
    for (const auto &item : items) this->insert(item);
  }

  // pair<iterator, bool> insert(const_reference);
  // void merge(multiset &);

  size_t count(const_reference num) const { return this->tree_->count(num); };
  pair<iterator, iterator> equal_range(const_reference);
  iterator lower_bound(const_reference);
  iterator upper_bound(const_reference);
};

}  // namespace s21

#include "s21_multiset.tpp"