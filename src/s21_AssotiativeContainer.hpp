#pragma once

// #include "s21_containers.hpp"
#include "s21_pair.hpp"
#include "s21_rb_tree.cpp"

namespace s21 {
template <typename T1, typename T2>
class AssociativeContainer {
  using key_type = T1;
  using value_type = T2;

 private:
  rb_tree<pair<key_type, value_type>> tree_;

 public:
  AssociativeContainer() = default;
  AssociativeContainer(std::initializer_list<value_type> const &items) {
    for (pair<key_type, value_type> &&item : items) {
      tree_.insert(pair<key_type, value_type>(item.first, item.second));
    }
  }
  AssociativeContainer(const AssociativeContainer &other) {
    tree_.copy_tree(other.tree_);
  }
  AssociativeContainer(AssociativeContainer &&other) {};
};
}  // namespace s21
