#pragma once

#include <algorithm>

namespace s21 {
template <typename T>
struct Node {
  T data;
  Node<T> *left, *right, *parent;
  bool is_red;

  Node(T data)
      : data(data),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_red(true) {};

  ~Node() noexcept {
    delete data;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  };
};

template <typename T>
class rb_tree {
 private:
  Node<T> *root_;

  void rotateLeft(Node<T> *&);
  void rotateRight(Node<T> *&);
  void fixViolation(Node<T> *&);
  void fixDoubleBlack(Node<T> *&);
  void inorderHelper(Node<T> *) const;
  void preorderHelper(Node<T> *) const;
  void postorderHelper(Node<T> *) const;
  Node<T> *minValueNode(Node<T> *) const;
  Node<T> *maxValueNode(Node<T> *) const;
  Node<T> *copyTree(Node<T> *node);
  void deleteTree(Node<T> *);

 public:
  rb_tree() : root_(nullptr) {}
  ~rb_tree() { deleteTree(root_); }

  void insert(const T &);
  void remove(const T &);
  void inorder() const;
  void preorder() const;
  void postorder() const;
  Node<T> *search(const T &) const;

  rb_tree<T> &operator=(const rb_tree<T> &other);
  rb_tree<T> &operator=(rb_tree<T> &&other) noexcept;
};

}  // namespace s21

#include "s21_rb_tree.ipp"
