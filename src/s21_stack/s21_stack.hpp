#pragma once

#include "../s21_vector/s21_vector.hpp"

namespace s21 {

template <typename T1, typename T2 = vector<T1>>
class stack : protected T2 {
 private:
  using value_type = T1;
  using container_type = T2;
  using reference = T1 &;
  using const_reference = const T1 &;
  using size_type = size_t;

 public:
  stack() { std::__throw_out_of_range("container is invalid"); }
  //   using T2::T2;
  //   using T2::operator=;

  //   void pop();
  //   void push(const T1 &value);
  //   const_reference top() const;
  //   bool empty() const;
  //   size_type size() const;
  //   container_type &_Get_container();
  //   const container_type &_Get_container() const;
  //   template <typename... Args>
  //   void insert_many_front(Args &&...args);
};

template <typename T1>
class stack<T1, vector<T1>> : protected vector<T1> {
 private:
  using value_type = T1;
  using container_type = vector<T1>;
  using reference = T1 &;
  using const_reference = const T1 &;
  using size_type = size_t;

 public:
  using vector<T1>::vector;
  using vector<T1>::operator=;

  void pop();
  void push(const T1 &value);
  const_reference top() const;
  bool empty() const;
  size_type size() const;
  container_type &_Get_container();
  const container_type &_Get_container() const;
  template <typename... Args>
  void insert_many_front(Args &&...args);
};

template <typename T1>
class stack<T1, list<T1>>:protected list<T1>
{
 private:
  using value_type = T1;
  using container_type = list<T1>;
  using reference = T1 &;
  using const_reference = const T1 &;
  using size_type = size_t;

 public:
  using list<T1>::list;
  using list<T1>::operator=;

  void pop();
  void push(const T1 &value);
  const_reference top() const;
  bool empty() const;
  size_type size() const;
  container_type &_Get_container();
  const container_type &_Get_container() const;
  template <typename... Args>
  void insert_many_front(Args &&...args);
};
}  // namespace s21

#include "s21_stack.tpp"
