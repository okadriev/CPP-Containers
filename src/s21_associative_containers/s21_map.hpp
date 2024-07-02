#pragma once

#include <limits>
#include <utility>

#include "../s21_sorted_containers/s21_sorted_containers.hpp"

namespace s21 {

template <typename T1, typename T2 /*, typename comparator = std::less<T1>*/>
class map : public sorted_container<pair<T1, T2>> {
 private:
  using key_type = T1;
  using data_type = T2;
  using value_type = pair<key_type, data_type>;
  using tree_type = rb_tree<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using container = sorted_container<pair<T1, T2>>;

 public:
  using iterator = typename container::iterator;
  using const_iterator = const typename container::iterator;

  map() {};
  map(std::initializer_list<value_type> const &items) : container(items) {};
  map(const map &);
  map(map &&);
  ~map() {};

  void erase(key_type const &);

  void clear();

  iterator find(const key_type &key);

  bool contains(const key_type &key) {
    return this->container::contains({key, data_type()});
  };

  std::size_t max_size() const;

  void merge(map &);
  void swap(map &) noexcept;

  bool operator==(const map &);
  map &operator=(const map &);
  map &operator=(map &&) noexcept;
  data_type &operator[](const key_type &);
};

}  // namespace s21

#include "s21_map_constructors.tpp"
#include "s21_map_methods.tpp"
#include "s21_map_operators.tpp"
