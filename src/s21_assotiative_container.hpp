#pragma once

#include <utility>

#include "s21_containers.hpp"
#include "s21_rb_tree.cpp"

namespace s21 {
template <typename T1, typename T2>
class associative_container {
  using key_type = T1;
  using value_type = T2;

 private:
  rb_tree<std::pair<key_type, value_type>> tree_;

 public:
  associative_container() = default;
  associative_container(std::pair<T1, T2> const &items) = default;
};
}  // namespace s21
