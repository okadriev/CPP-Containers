#pragma once

namespace s21 {
template <typename T1, typename T2>
struct pair {
  T1 first_;
  T2 second_;

  pair() : first_(), second_() {}
  pair(const T1& first, const T2& second) : first_(first), second_(second) {}
  pair(const pair& other) : first_(other.first()), second_(other.second()) {}

  pair swap(pair& other) noexcept {
    pair tmp = other;
    other = *this;
    *this = tmp;
    return *this;
  }

  pair& operator=(const pair& other) {
    if (this != &other) {
      first_ = other.first_;
      second_ = other.second_;
    }
    return *this;
  }

  bool operator==(const pair& other) const noexcept {
    return first_ == other.first_ && second_ == other.second_;
  }
};
}  // namespace s21
