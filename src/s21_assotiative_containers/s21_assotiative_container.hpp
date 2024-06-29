#pragma once

// #include <utility>

#include "../s21_containers.hpp"
#include "../s21_set/s21_rb_tree.cpp"
#include "s21_pair.hpp"

namespace s21 {

template <typename T1, typename T2>
class associative_container : container<key_pair<T1, T2>> {
  using key_type = T1;
  using value_type = T2;
  using pair_type = key_pair<key_type, value_type>;
  using tree_type = rb_tree<pair_type>;
  using size_t = std::size_t;
  using node_type = Node<pair_type>;

 public:
  virtual ~associative_container() = default;

  class iterator {
   private:
    using pointer = T2 *;
    using reference = T2 &;

    node_type *node_;
    node_type *next_node(node_type *node) const;

   public:
    iterator() : node_(nullptr) {};
    iterator(node_type *node) : node_(node) {};
    ~iterator() {};

    bool operator==(const iterator &s) const { return (node_ == s.node_); };
    bool operator!=(const iterator &s) const { return (node_ != s.node_); };
    reference operator*() const { return node_->data; };
    iterator &operator++() {
      node_ = next_node(node_);
      return *this;
    };
  };

  virtual const pair_type *const_iterator() const = 0;

  virtual void insert(const key_type &key, const value_type &value) = 0;
  virtual void erase(const key_type &key) = 0;
  virtual value_type &find(const key_type &key) = 0;
  virtual bool contains(const key_type &key) const = 0;
  virtual void clear() = 0;
};

}  // namespace s21
