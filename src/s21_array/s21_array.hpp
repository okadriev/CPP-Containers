#pragma once

#include <utility>

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
  // Конструктор по умолчанию
  array() = default;
  // Конструктор через initializer_list
  array(std::initializer_list<data_type> const&);
  // Конструктор копирования
  array(const array&);
  // Конструктор перемещения
  array(array&&) noexcept;

  pointer data() noexcept { return N == 0 ? nullptr : &(data_[0]); }
  const_pointer data() const noexcept { return N == 0 ? nullptr : &(data_[0]); }

  reference front() { return data()[0]; }
  const_reference front() const { return data()[0]; }
  reference back() { return data()[N - 1]; }
  const_reference back() const { return data()[N - 1]; }

  reference at(size_type index) { return *(data() + index); }
  const_reference at(size_type index) const { return *(data() + index); }

  // Оператор индексации
  reference operator[](size_type index) { return at(index); }
  const_reference operator[](size_type index) const { return at(index); }

  // Получить размер массива
  constexpr size_type size() const noexcept { return N; }

  // Итераторы
  pointer begin() noexcept { return data(); }
  pointer end() noexcept { return &(data()[N]); }

  // Заполнение массива
  void fill(const T& value) {
    for (std::size_t i = 0; i < N; ++i) data_[i] = value;
  }
};

}  // namespace s21

#include "s21_array_constructors.tpp"
