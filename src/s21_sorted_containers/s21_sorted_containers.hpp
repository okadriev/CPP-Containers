#pragma once
#include <type_traits>

#include "../s21_pair/s21_pair.hpp"
#include "../s21_vector/s21_vector.hpp"
#include "s21_rb_tree.hpp"

namespace s21 {

template <typename T>
class sorted_container {
 protected:
  using value_type = T;
  using iterator = Iterator<value_type>;
  using tree_t = rb_tree<value_type>;
  using size_t = std::size_t;
  using limits = std::numeric_limits<size_t>;

  tree_t *tree_;
  size_t m_size_;
  bool multi_;

  bool insert_value(const value_type &);

 public:
  // sorted_container() : tree_(new tree_t()), m_size_(0), multi_(false) {}
  sorted_container(bool m) : tree_(new tree_t()), m_size_(0), multi_(m) {}
  sorted_container(std::initializer_list<value_type> const &, bool);
  sorted_container(const sorted_container &other)
      : tree_(new tree_t()), m_size_(other.m_size_), multi_(other.multi_) {
    tree_->copy_tree(other.tree_);
  }
  sorted_container(sorted_container &&other) noexcept {
    multi_ = other.multi_;
    tree_ = other.tree_;
    m_size_ = other.m_size_;
    other.m_size_ = 0;
    other.tree_ = nullptr;
  }

  ~sorted_container() { delete tree_; }

  pair<iterator, bool> insert(value_type &&);
  pair<iterator, bool> insert(const value_type &);
  void insert(std::initializer_list<T>);
  void merge(sorted_container &);
  bool contains(const value_type &);
  void erase(value_type const &);
  iterator find(const value_type &);

  void clear();
  void swap(sorted_container &) noexcept;
  iterator begin() const { return iterator(this->tree_->min()); }
  iterator end() const { return iterator(nullptr); }
  size_t size() const { return this->m_size_; }
  size_t max_size() const { return limits::max() / sizeof(value_type); };
  bool empty() const { return this->tree_->empty(); }

  template <typename... Args>
  vector<pair<iterator, bool>> insert_many(Args &&...args);
};

}  // namespace s21

#include "s21_sorted_containers.tpp"
