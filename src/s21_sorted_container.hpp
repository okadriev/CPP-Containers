#include "s21_containers.hpp"
#include "s21_set/s21_rb_tree.cpp"

namespace s21 {

template <typename T>
class sorted_container : public container<T> {
 public:
  virtual void insert(const T &value) = 0;
  class iterator {
   private:
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Node<value_type> *node_;

    Node<value_type> *next_node(Node<value_type> *node) const;

   public:
    iterator() : node_(nullptr) {};
    iterator(Node<value_type> *node) : node_(node) {};
    ~iterator() {};

    bool operator==(const iterator &s) const { return (node_ == s.node_); };
    bool operator!=(const iterator &s) const { return (node_ != s.node_); };
    reference operator*() const { return node_->data; };
    iterator &operator++() {
      node_ = next_node(node_);
      return *this;
    };
  };
};

template <typename T>
Node<T> *sorted_container<T>::iterator::next_node(Node<T> *node) const {
  if (node == nullptr) return nullptr;

  Node<T> *next = nullptr;

  if (node->right) {
    next = node->right;
    while (next->left) next = next->left;

  } else {
    next = node->parent;
    while (next && node == next->right) {
      node = next;
      next = next->parent;
    }
  }

  return next;
};

}  // namespace s21