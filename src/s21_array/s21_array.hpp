#pragma once
#include <cstddef>
#include <utility>

namespace s21 {

template <typename T, std::size_t N>
class array {
 private:
  using value_type = T;
  using pointer = value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  value_type data_[N] = {};

 public:
  // Конструктор по умолчанию
  array() = default;

  // Конструктор для C++17 и выше
  template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == N>>
  array(Args&&... args) : data_{std::forward<Args>(args)...} {}

  reference at(size_type index) { return data_[index]; }
  const_reference at(size_type index) const { return data_[index]; }

  // Оператор индексации
  reference operator[](size_type index) { return at(index); }
  const_reference operator[](size_type index) const { return at(index); }

  // Получить размер массива
  constexpr size_type size() const noexcept { return N; }

  // Итераторы
  pointer begin() noexcept { return data_; }
  const pointer begin() const noexcept { return data_; }

  pointer end() noexcept { return data_ + N; }
  const pointer end() const noexcept { return data_ + N; }

  // Заполнение массива
  void fill(const T& value) {
    for (std::size_t i = 0; i < N; ++i) {
      data_[i] = value;
    }
  }
};

}  // namespace s21
