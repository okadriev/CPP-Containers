// #include "s21_set.hpp"
namespace s21 {

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set &other) {
  if (this != &other) {
    delete this->tree_;

    this->tree_ = new key_type();
    this->m_size_ = other.m_size_;
    this->tree_->copy_tree(other.tree_);
  }

  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set &&other) noexcept {
  if (this != &other) {
    delete this->tree_;

    this->tree_ = other.tree_;
    this->m_size_ = other.m_size_;
    other.m_size_ = 0;
    other.tree_ = nullptr;
  }

  return *this;
}

}  // namespace s21