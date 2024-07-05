#pragma once
#include <type_traits>

#include "../s21_pair/s21_pair.hpp"
#include "s21_sc_iterator.hpp"

namespace s21 {
template <typename T>
class rb_tree {
 private:
  using node_t = Node<T>;
  using iterator = Iterator<T>;
  using size_t = std::size_t;

  node_t *root;

  node_t *copy_node(node_t *);
  void remove_node(node_t *);
  void delete_tree(node_t *);
  void rotate_left(node_t *&);
  void rotate_right(node_t *&);

  void fix_2_red(node_t *&);
  void fix_2_black(node_t *&);
  size_t count_elements(node_t *node, const T &data) const;
  pair<node_t *, node_t *> element_range(node_t *node, const T &data);

  node_t *red_goes_up(node_t *grand_parent, node_t *parent, node_t *uncle) {
    grand_parent->is_red = 1;
    parent->is_red = 0;
    uncle->is_red = 0;
    return grand_parent;
  }

 public:
  rb_tree() : root(nullptr) {}
  rb_tree(const rb_tree *other) { copy_tree(other); }
  ~rb_tree() { delete_tree(); }

  void delete_tree() {
    delete_tree(root);
    root = nullptr;
  }

  void copy_tree(const rb_tree *);
  node_t *insert(const T &);
  void remove(const T &);
  void remove(node_t *);
  node_t *min() const;
  node_t *search(const T &) const;
  bool empty() const { return (this == nullptr) || root == nullptr; };
  node_t *get_root() const { return root; }

  size_t count(const T &) const;
  pair<node_t *, node_t *> equal_range(const T &);
  iterator make_iterator(node_t *node) { return iterator(node); }
};
}  // namespace s21

#include "s21_rb_tree.tpp"
