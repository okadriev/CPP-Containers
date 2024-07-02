#pragma once
#include <limits>

#include "../s21_sorted_containers/s21_sorted_containers.hpp"

namespace s21 {

template <typename T>
class set : public sorted_container<T> {
 protected:
  using value_type = T;
  using key_type = rb_tree<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using container = sorted_container<value_type>;

  // void copy(const set &other) { this->tree_->copy_tree(other.tree); };

 public:
  using iterator = typename container::iterator;
  using const_iterator = const typename container::iterator;

  set() {};
  set(std::initializer_list<value_type> const &items) : container(items) {};
  set(const set &);
  set(set &&);
  ~set() {};

  set<value_type> &operator=(const set &);
  set<value_type> &operator=(set &&) noexcept;

  void swap(set &);
  void merge(set &);

  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  };
};

template <typename value_type>
set<value_type>::set(const set<value_type> &other) : set() {
  this->m_size_ = other.size();
  this->tree_->copy_tree(other.tree_);
}

template <typename value_type>
set<value_type>::set(set<value_type> &&other) : container() {
  delete this->tree_;
  this->tree_ = other.tree_;
  this->m_size_(other.m_size_);
  other.tree_ = nullptr;
  other.m_size_ = 0;
}

}  // namespace s21

#include "s21_set.tpp"