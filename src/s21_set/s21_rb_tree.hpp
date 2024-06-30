#pragma once

namespace s21 {

#define MY_BRO_HAS_RED_SON                   \
  ((my_bro->left && my_bro->left->is_red) || \
   (my_bro->right && my_bro->right->is_red))

#define RED_GOES_UP         \
  grand_parent->is_red = 1; \
  parent->is_red = 0;       \
  uncle->is_red = 0;

template <typename T>
struct Node {
  T data;
  Node<T> *left, *right, *parent;
  bool is_red;  // поменять на int black?

  Node(T data = 0)
      : data(data),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_red(true) {}
};

template <typename T>
class rb_tree {
 private:
  Node<T> *root;

  Node<T> *copy_node(Node<T> *);
  void remove_node(Node<T> *);
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
  ~rb_tree() { delete_tree();  }

  void delete_tree() { delete_tree(root), root = nullptr; }
  void copy_tree(const rb_tree<T> *);
  Node<T> *insert(const T &);
  void remove(const T &);

  Node<T> *min() const;
  Node<T> *search(const T &) const;
  bool empty() const { return (this == nullptr) || (root == nullptr); };
  size_t count(const T &) const;
  std::pair<Node<T> *, Node<T> *> equal_range(const T &);
  void print_tree() const { print(root, 0); };  // Дебаг
};

}  // namespace s21

#include "s21_rb_tree.tpp"