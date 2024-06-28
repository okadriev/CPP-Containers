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
  T1& first() noexcept { return first_; }
  const T1& first() const noexcept { return first_; }
  T2& second() noexcept { return second_; }
  const T2& second() const noexcept { return second_; }

  bool operator==(const pair& other) const noexcept {
    return first_ == other.first_ && second_ == other.second_;
  }
};
}  // namespace s21
