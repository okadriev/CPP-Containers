#pragma once

namespace s21 {
template <typename T1, typename T2>
struct pair {
 private:
  T1 first_;
  T2 second_;

 public:
  pair() : first_(), second_() {}
  pair(const T1& first, const T2& second) : first_(first), second_(second) {}
  pair(const pair& other) : first_(other.first_), second_(other.second_) {}
};
}  // namespace s21
