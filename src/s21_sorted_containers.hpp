#include "s21_containers.hpp"

namespace s21 {

template <typename T>
class sorted_container : public container<T> {
 private:
  template <typename T = T>
  class rb_tree {
   private:
    Node<T> *root;

    Node<T> *copy_node(Node<T> *node);
    void remove_node(Node<T> *target);
    void delete_tree(Node<T> *);

    void rotate_left(Node<T> *&);
    void rotate_right(Node<T> *&);
    void fix_2_red(Node<T> *&);
    void fix_2_black(Node<T> *&);

    size_t count_elements(Node<T> *node, const T &data) const;
    std::pair<Node<T> *, Node<T> *> element_range(Node<T> *node, const T &data);
    void print(Node<T> *node, int level) const;  // Дебаг

   public:
    rb_tree() : root(nullptr) {}
    rb_tree(const rb_tree<T> *other) { copy_tree(other); }
    ~rb_tree() { delete_tree(root); }

    void copy_tree(const rb_tree<T> *other);
    Node<T> *insert(const T &data);
    void remove(const T &data);

    Node<T> *min() const;
    Node<T> *search(const T &) const;
    bool empty() const { return (this == nullptr) || (root == nullptr); };
    size_t count(const T &data) const;
    std::pair<Node<T> *, Node<T> *> equal_range(const T &data);
    void print_tree() const { print(root, 0); };  // Дебаг
  };

 public:
  template <typename T>
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

  virtual void insert(const T &value) = 0;
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

#include "s21_rb_tree.ipp"
