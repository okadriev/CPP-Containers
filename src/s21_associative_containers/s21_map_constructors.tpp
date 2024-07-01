// #include "s21_map.hpp"

namespace s21 {
template <typename T1, typename T2>
map<T1, T2>::map(std::initializer_list<value_type> const &items) : map() {
  insert(items);
}
template <typename T1, typename T2>
map<T1, T2>::map(const map<T1, T2> &other) : map() {
  this->m_size_ = other.size();
  this->tree_->copy_tree(other.tree_);
}

template <typename T1, typename T2>
map<T1, T2>::map(map<T1, T2> &&other) : map() {
  delete this->tree_;
  this->tree_ = other.tree_;
  this->m_size_(other.m_size_);
  other.tree_ = nullptr;
  other.m_size_ = 0;
}
}  // namespace s21
