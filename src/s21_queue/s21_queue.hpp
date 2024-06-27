#pragma once

#include "../s21_vector/s21_vector.hpp"

namespace s21 {
template <typename T1, typename T2 = vector<T1>>
class queue : protected T2 {
 private:
  using value_type = T1;
  using container_type = T2;
  using reference = T1 &;
  using const_reference = const T1 &;
  using size_type = size_t;

 public:
  using T2::T2;
  using T2::operator=;
  // using T2::pop_back;
  // usung T2::push_back;

  void pop();
  void push(const T1 &value);
  const_reference front() const;
  const_reference back() const;
  bool empty() const;
  size_type size() const;
  container_type &_Get_container();
  const container_type &_Get_container() const;
  void swap(queue &other);
  template <typename... Args>
  void insert_many_back(Args &&...args);
};

// template <typename T1>
// class queue<T1, vector<T1>>::protected vector<T1>
// {
// private:
// public:
//   using vector<T1>::vector;
// };

// template <typename T1>
// class queue<T1, list<T1>>::protected list<T1>
// {
// private:
// public:
//   using list<T1>::list;
// };
}  // namespace s21

#include "s21_queue.tpp"