#pragma once
#include "s21_set.hpp"  // временное решение из-за vscode

namespace s21 {

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set() {
  for (const auto &item : items) insert(item);
  m_size = items.size();
};

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set &other) {
  if (this != &other) {
    delete tree;

    tree = new key_type();
    m_size = other.m_size;
    tree->copy_tree(other.tree);
  }

  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set &&other) noexcept {
  if (this != &other) {
    delete tree;

    tree = other.tree;
    m_size = other.m_size;
    other.m_size = 0;
    other.tree = nullptr;
  }

  return *this;
}

template <typename value_type>
void set<value_type>::clear() {
  tree->delete_tree();
  m_size = 0;
}

template <typename value_type>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const_reference data) {
  bool result = false;
  iterator ptr = nullptr;

  if (!contains(data)) {
    ptr = tree->insert(data);
    ++m_size;

    result = true;
  }

  return std::make_pair(ptr, result);
}

template <typename value_type>
void set<value_type>::erase(const_reference data) {
  if (contains(data)) {
    tree->remove(data);
    --m_size;
  }
};

template <typename value_type>
void set<value_type>::erase(iterator ptr) {
  if (ptr != end() && contains(*ptr)) {
    tree->remove(*ptr);
    --m_size;
  }
};

template <typename value_type>
void set<value_type>::swap(set &other) {
  std::swap(tree, other.tree);
  std::swap(m_size, other.m_size);
}

template <typename value_type>
void set<value_type>::merge(set &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

}  // namespace s21