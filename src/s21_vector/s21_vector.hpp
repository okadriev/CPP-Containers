#ifndef S21_VECTOR_H_
#define S21_VECTOR_H_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <class T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector();                      // default constructor
  explicit vector(size_type n);  // parametrized constructor
  vector(std::initializer_list<value_type> const &items);  // initializer list
  vector(const vector &v);                                 // copy constructor
  vector(vector &&v) noexcept;                             // move constructor
  ~vector();                                               // destructor

  // operator overload method
  vector &operator=(vector &&v) noexcept;

  // access methods
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator data() noexcept;

  // iterator methods
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  // capacity methods
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  // modifier methods
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);
  //  iterator insert_many(const_iterator pos, Args &&...args);
  //  void insert_many_back(Args &&...args);

 private:
  size_type size_;
  size_type capacity_;
  iterator data_;

  void reallocate(size_type size);
};
}  // namespace s21

#include "s21_vector.tpp"

#endif