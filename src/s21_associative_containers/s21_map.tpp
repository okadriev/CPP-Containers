#include "s21_map.hpp"

namespace s21 {

template <typename T1, typename T2>
map<T1, T2>::map(std::initializer_list<value_type> const &items) {
  for (const auto &item : items) insert(item);
  m_size = items.size();
}

template <typename T1, typename T2>
map<T1, T2>::map(const map<T1, T2> &other)
    : tree(new value_type()), m_size(other.m_size) {
  tree->copy_tree(other.tree);
}

template <typename T1, typename T2>
map<T1, T2>::map(map<T1, T2> &&other) : tree(other), m_size(other.m_size) {
  other.tree = nullptr;
  other.m_size = 0;
}

template <typename T1, typename T2>
bool map<T1, T2>::contains(const_reference &) {
    return false;
}

}  // namespace s21