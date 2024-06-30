#pragma once
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
  multiset() : set<T>(){};
  multiset(std::initializer_list<T> const &);

  std::pair<iterator, bool> insert(const_reference);

  size_type count(const_reference num) const { return this->tree->count(num); };
  std::pair<iterator, iterator> equal_range(const_reference);
  iterator lower_bound(const_reference);
  iterator upper_bound(const_reference);
};

template <typename T>
multiset<T>::multiset(std::initializer_list<T> const &items) : set<T>() {
  for (const auto &item : items) insert(item);

  this->m_size = items.size();
}

template <typename value_type>
std::pair<typename s21::set_iterator<value_type>, bool>
multiset<value_type>::insert(const_reference data) {
  std::pair<iterator, bool> result;
  result.first = this->tree->insert(data);
  result.second = true;
  (this->m_size)++;

  return result;
};

template <typename T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const_reference data) {
  return this->tree->equal_range(data);
};

template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const_reference data) {
  return equal_range(data).first;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const_reference data) {
  return ++(equal_range(data).second);
}

}  // namespace s21

#include "s21_multiset.tpp"