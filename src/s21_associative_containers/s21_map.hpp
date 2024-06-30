#pragma once
#include "s21_associative_containers/s21_associative_containers.hpp"

namespace s21 {

template <typename T1, typename T2 /*, typename comparator = std::less<T1>*/>
class map : private associative_container<T1, T2> {
 private:
  using key_type = T1;
  using data_type = T2;
  using value_type = pair<key_type, data_type>;
  using tree_type = typename sorted_container<value_type>::rb_tree;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;

  tree_type *tree;
  size_type m_size;

 public:
  using iterator = typename sorted_container<value_type>::iterator;
  using const_iterator = const typename sorted_container<value_type>::iterator;

  map() : tree(new tree_type()), m_size(0) {};
  map(std::initializer_list<value_type> const &);
  map(const map &);
  map(map &&);
  ~map() { delete tree; };

  virtual pair<iterator, bool> insert(const value_type &value);
  virtual pair<iterator, bool> insert(value_type &&);
  virtual void insert(std::initializer_list<value_type>);

  virtual void erase(const key_type &);
  virtual void clear();

  virtual iterator find(const_reference &);
  virtual bool contains(const_reference &) const;
  virtual iterator begin() const;
  virtual iterator end() const;

  virtual size_t size() const;
  virtual bool empty() const;

  bool operator=(const s21::map<T1, T2> &);
};

}  // namespace s21
