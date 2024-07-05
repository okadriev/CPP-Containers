#pragma once
#include <algorithm>

namespace s21 {
template <typename T1, typename T2>
struct pair {
  T1 first;
  T2 second;

  pair() : first(), second() {}
  pair(const T1& first, const T2& second) : first(first), second(second) {}
  pair(T1&& first, T2&& second)
      : first(std::move(first)), second(std::move(second)) {}
  pair(const pair& other) : first(other.first), second(other.second) {}

  pair& operator=(const pair&) noexcept;

  pair& operator=(pair&&) noexcept;

  bool operator==(T1 const) const noexcept;
  bool operator!=(T1 const) const noexcept;

  bool operator<(T1 const) const noexcept;
  bool operator<=(T1 const) const noexcept;
  bool operator>(T1 const) const noexcept;
  bool operator>=(T1 const) const noexcept;

  bool operator==(const pair&) const noexcept;
  bool operator!=(const pair&) const noexcept;

  bool operator<(const pair&) const noexcept;
  bool operator<=(const pair&) const noexcept;
  bool operator>(const pair&) const noexcept;
  bool operator>=(const pair&) const noexcept;
};

}  // namespace s21

#include "s21_pair_operators.tpp"
