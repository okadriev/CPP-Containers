#pragma once

#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <typename T, std::size_t N>
class array {
 private:
  using data_type = T;
  using pointer = data_type*;
  using const_pointer = const data_type*;
  using reference = data_type&;
  using const_reference = const data_type&;
  using size_type = std::size_t;

  data_type data_[N] = {};

 public:
  array() = default;
  array(std::initializer_list<data_type> const& items) {
    for (size_type i = 0; i < N; ++i) data_[i] = items.begin()[i];
  }
  array(const array& other) noexcept {
    for (size_type i = 0; i < N; ++i) data_[i] = other.data_[i];
  }
  array(array&& other) noexcept {
    for (size_type i = 0; i < N; ++i) data_[i] = other.data_[i];
  }

  pointer data() noexcept { return N == 0 ? nullptr : &(data_[0]); }
  const_pointer data() const noexcept { return N == 0 ? nullptr : &(data_[0]); }

  reference at(size_type index) {
    if (data() == nullptr) throw std::length_error("Array is empty");
    if (index >= N) throw std::out_of_range("Index out of range");
    return *(data() + index);
  }
  const_reference at(size_type index) const {
    if (data() == nullptr) throw std::length_error("Array is empty");
    if (index >= N) throw std::out_of_range("Index out of range");
    return *(data() + index);
  }

  reference front() { return at(0); }
  const_reference front() const { return at(0); }
  reference back() { return at(N - 1); }
  const_reference back() const { return at(N - 1); }

  reference operator[](size_type index) { return at(index); }
  const_reference operator[](size_type index) const { return at(index); }

  constexpr size_type size() const noexcept { return N; }

  pointer begin() noexcept { return data(); }
  pointer end() noexcept { return &(data()[N]); }

  void fill(const T& value) {
    for (std::size_t i = 0; i < N; ++i) data_[i] = value;
  }
};

}  // namespace s21
