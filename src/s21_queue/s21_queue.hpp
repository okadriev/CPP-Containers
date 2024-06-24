#pragma once

#include "../s21_vector/s21_vector.hpp"

namespace s21 {
template <typename T1, typename T2 = vector<T1>>
class queue : protected T2 {
 private:
 public:
  using T2::T2;

  queue<T1, T2> &operator=(T2 &&other);

  void pop();
  void push(const T1 &value);
  const T1 &front() const;
  const T1 &back() const;
  bool empty() const;
  size_t size() const;
  T2 &_Get_container();
  const T2 &_Get_container() const;
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