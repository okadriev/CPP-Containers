#pragma once

#include "../s21_vector/s21_vector.hpp"

namespace s21 {

template <typename T1, typename T2 = vector<T1>>
class stack : protected T2 {
 private:
 public:
	using	value_type = T1;
	using	container_type = T2;
  using reference = T1 &;
  using const_reference = const T1 &;
	using		size_type = size_t;

  using T2::T2;

  stack<T1, T2> &operator=(T2 &&other);

  void pop();
  void push(const T1 &value);
  const_reference top() const;
  bool empty() const;
  size_type size() const;
  container_type &_Get_container();
  const container_type &_Get_container() const;
};

// template <typename T1>
// class stack<T1, vector<T1>> : protected vector<T1> {
//  private:
//  public:
//   using vector<T1>::vector;
// };

// template <typename T1>
// class stack<T1, list<T1>>::protected list<T1>
// {
// private:
// public:
//   using list<T1>::list;
// };
}  // namespace s21

#include "s21_stack.tpp"
