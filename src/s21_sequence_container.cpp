#include "s21_sequence_container.hpp"

namespace s21 {
template <typename T>
s21_sequence_container<T>::s21_sequence_container(size_type n, const T &val)
    : size_(n), capacity_(n), data_(n ? new T[n] : nullptr) {
  fill(data_, data_ + n, val);
}

template <typename T>
s21_sequence_container<T>::s21_sequence_container(
    const s21_sequence_container<T> &other)
    : size_(other.size_),
      capacity_(other.capacity_),
      data_(new T[other.capacity_]) {
  copy(other.data_, other.data_ + other.size_, data_);
}
}  // namespace s21
