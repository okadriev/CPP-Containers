#pragma once

namespace s21 {
template <typename T>
struct Node {
  T data;
  Node<T> *left, *right, *parent;
  bool is_red;

  Node(T data = 0)
      : data(data),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_red(true) {}
};
}  // namespace s21