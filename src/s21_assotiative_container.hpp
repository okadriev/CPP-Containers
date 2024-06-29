#pragma once

// #include <utility>

#include "../s21_set/s21_rb_tree.cpp"
#include "s21_containers.hpp"
#include "s21_pair.hpp"

namespace s21 {

template <typename ValueType>
class OwnIterator : public std::iterator<std::input_iterator_tag, ValueType> {
  friend class OwnContainer;

 private:
  OwnIterator(ValueType *p);

 public:
  OwnIterator(const OwnIterator &it);

  bool operator!=(OwnIterator const &other) const;
  bool operator==(OwnIterator const &other) const;  // need for BOOST_FOREACH
  typename OwnIterator::reference operator*() const;
  OwnIterator &operator++();

 private:
  ValueType *p;
};

template <typename T1, typename T2>
class associative_container : container<key_pair<T1, T2>> {
  using key_type = T1;
  using value_type = T2;
  using pair_type = key_pair<key_type, value_type>;
  using tree = rb_tree<pair_type>;

 public:
  typedef associative_iterator<tree> const_iterator;
  typedef associative_iterator<tree> iterator;

  virtual ~associative_container() = default;

  virtual const pair_type *const_iterator() const = 0;

  virtual void insert(const key_type &key, const value_type &value) = 0;
  virtual void erase(const key_type &key) = 0;
  virtual bool contains(const key_type &key) const = 0;
  virtual void clear() = 0;
};

}  // namespace s21
