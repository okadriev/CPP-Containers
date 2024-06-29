#pragma once
#include "s21_assotiative_container.hpp"

namespace s21 {
template <typename T1, typename T2>
class map : public associative_container<T1, T2> {
  using key_type = T1;
  using value_type = T2;
  using pair_type = key_pair<key_type, value_type>;
  using tree_type = rb_tree<pair_type>;
  using size_t = std::size_t;

 private:
  tree_type tree_;
  Node<tree_type>* root_ = nullptr;

 public:
  map() {};

  virtual void insert(const key_type& key, const value_type& value) {

  };
};
}  // namespace s21
