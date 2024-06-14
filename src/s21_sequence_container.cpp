#include "s21_sequence_container.hpp"

using namespace s21;

template <typename T>
void s21_sequence_container<T>::s21_sequence_container()
    : size_(0U), capacity_(0U), data(nullptr) {}

template <typename T>
void s21_sequence_container<T>::s21_sequence_container(size_type n,
                                                       const T &val = T())
    : size_(n), capacity_(n), data_(n ? new T[n] : nullptr) {
  fill(data_, data_ + n, val);
}

template <typename T>
void s21_sequence_container<T>::s21_sequence_container(
    const s21_sequence_containers<T> &other)
    : size_(other.size_),
      capacity_(other.capacity_),
      data_(new T[other.capacity_]) {
  copy(other.data_, other.data_ + other.size_, data_);
}