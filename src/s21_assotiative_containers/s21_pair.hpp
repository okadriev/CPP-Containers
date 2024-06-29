#pragma once

namespace s21 {
template <typename T1, typename T2>
struct pair {
  T1 key;
  T2 data;

  pair() : key(), data() {}
  pair(const T1& key, const T2& second) : key(key), data(second) {}
  pair(const pair& other) : key(other.key), data(other.data) {}

  pair& operator=(const pair& other) {
    if (this != &other) {
      key = other.key;
      data = other.data;
    }
    return *this;
  }

  bool operator==(const pair& other) const noexcept { return key == other.key; }

  bool operator!=(const pair& other) const noexcept { return key != other.key; }

  bool operator<(const pair& other) const noexcept { return key < other.key; }

  bool operator>(const pair& other) const noexcept { return key > other.key; }
};
}  // namespace s21
