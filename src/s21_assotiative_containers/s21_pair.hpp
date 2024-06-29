#pragma once

namespace s21 {
template <typename T1, typename T2>
struct key_pair {
  T1 key;
  T2 data;

  key_pair() : key(), data() {}
  key_pair(const T1& key, const T2& second) : key(key), data(second) {}
  key_pair(const key_pair& other) : key(other.key), data(other.data) {}

  key_pair swap(key_pair& other) noexcept {
    key_pair tmp = other;
    other = *this;
    *this = tmp;
    return *this;
  }

  key_pair& operator=(const key_pair& other) {
    if (this != &other) {
      key = other.key;
      data = other.data;
    }
    return *this;
  }

  bool operator==(const key_pair& other) const noexcept {
    return key == other.key;
  }

  bool operator!=(const key_pair& other) const noexcept {
    return key != other.key;
  }

  bool operator<(const key_pair& other) const noexcept {
    return key < other.key;
  }

  bool operator>(const key_pair& other) const noexcept {
    return key > other.key;
  }
};
}  // namespace s21
