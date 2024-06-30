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

  pair& operator=(const pair& other) {
    if (this != &other) {
      first = other.first;
      second = other.second;
    }
    return *this;
  }

  bool operator==(const pair& other) const noexcept {
    return first == other.first;
  }

  bool operator!=(const pair& other) const noexcept {
    return first != other.first;
  }

  bool operator<(const pair& other) const noexcept {
    return first < other.first;
  }

  bool operator>(const pair& other) const noexcept {
    return first > other.first;
  }
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1&& first, T2&& second) {
  return pair<T1, T2>(first, second);
}

}  // namespace s21
