#pragma once
#include <iostream>

namespace s21
{
  template <typename T1, typename T2 = s21_vector<T1>>
  class stack : protected T2
  {
  private:

  public:
    using T2::T2;
    void pop();
    void push(const T1 &value);
    const T1 &top() const;
    bool empty() const;
    size_t size() const;
    T2 &_Get_container();
    // template <typename... Args>
    // void emplace(Args &&...args);
  };

  // template <typename T1>
  // class stack<T1, vector<T1>>::protected vector<T1>
  // {
  // private:
  // public:
  //   using vector<T1>::vector;
  // };

  // template <typename T1>
  // class stack<T1, list<T1>>::protected list<T1>
  // {
  // private:
  // public:
  //   using list<T1>::list;
  // };
}
