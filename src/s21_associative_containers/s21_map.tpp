// #include "s21_map.hpp"

namespace s21 {

template <typename T1, typename T2>
void map<T1, T2>::erase(const iterator &) {}

template <typename T1, typename T2>
void map<T1, T2>::erase(const key_type &) {}

template <typename T1, typename T2>
map<T1, T2>::map(std::initializer_list<value_type> const &items) : map() {
  insert(items);
  m_size = items.size();
}

template <typename T1, typename T2>
map<T1, T2>::map(const map<T1, T2> &other)
    : tree(new tree_type()), m_size(other.m_size) {
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
  pair<typename map<T1, T2>::iterator, bool> result = {iterator(), false};
  if (!contains(value.first)) {
    tree->insert(value);
    result.second = true;
  }
  result.first = find(value.first);
  return result;
}

template <typename T1, typename T2>
pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    value_type &&value) {
  bool result = false;
  if (!contains(value.first)) {
    tree->insert(value);
    result = true;
  }
  return {find(value.first), result};
}

template <typename T1, typename T2>
void map<T1, T2>::insert(std::initializer_list<value_type> items) {
  for (const auto &item : items) insert(item);
}

template <typename T1, typename T2>
void map<T1, T2>::merge(class_type &) {}

template <typename T1, typename T2>
bool map<T1, T2>::contains(const key_type &key) {
  return find(key) != end();
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator s21::map<T1, T2>::find(const key_type &key) {
  value_type data(key, "0");
  return iterator(tree->search(data));
}

template <typename T1, typename T2>
bool map<T1, T2>::operator==(const s21::map<T1, T2> &) {
  return false;
}

template <typename T1, typename T2>
map<T1, T2> &map<T1, T2>::operator=(const map &other) {
  if (this != &other) {
    delete tree;

    tree = new tree_type();
    m_size = other.m_size;
    tree->copy_tree(other.tree);
  }

  return *this;
}

template <typename T1, typename T2>
map<T1, T2> &map<T1, T2>::operator=(map &&other) noexcept {
  if (this != &other) {
    delete tree;

    tree = other.tree;
    m_size = other.m_size;
    other.m_size = 0;
    other.tree = nullptr;
  }

  return *this;
}

}  // namespace s21
