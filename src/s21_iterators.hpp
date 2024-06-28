#pragma once

namespace s21 {
template <typename T>
struct greater {
  bool operator()(const T& st, const T& nd) const { return st > nd; }
};

template <typename T>
struct iterator {
  using value_type = T;
  using reference = T&;
  using pointer = T*;

  virtual ~iterator() = default;

  virtual iterator begin() = 0;
  virtual iterator end() = 0;
};

}  // namespace s21