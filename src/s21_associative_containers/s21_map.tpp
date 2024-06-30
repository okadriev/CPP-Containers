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
pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    const value_type &value) {
  return tree->insert(value);
}

template <typename T1, typename T2>
pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    value_type &&value) {
  tree->insert(value);
}

template <typename T1, typename T2>
void map<T1, T2>::insert(std::initializer_list<value_type> items) {
  for (const auto &item : items) insert(item);
}

template <typename T1, typename T2>
bool map<T1, T2>::contains(const_reference &key) const {}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::find(const_reference &key) {}

template <typename T1, typename T2>
bool map<T1, T2>::operator=(const s21::map<T1, T2> &) {}

}  // namespace s21