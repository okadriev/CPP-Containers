#ifndef S21_VECTOR_H_
#define S21_VECTOR_H_

#include <iostream>
#include <limits>

using std::copy;
using std::initializer_list;
using std::invalid_argument;
using std::numeric_limits;
using std::out_of_range;

namespace s21 {

template <class T>
class s21_vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  s21_vector();                      // default constructor
  explicit s21_vector(size_type n);  // parametrized constructor
  s21_vector(initializer_list<value_type> const &items);  // initializer list
  s21_vector(const s21_vector &v);                        // copy constructor
  s21_vector(s21_vector &&v) noexcept;                    // move constructor
  ~s21_vector();                                          // destructor

  // operator overload method
  s21_vector &operator=(s21_vector &&v) noexcept;

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
  void swap(s21_vector &other);

 private:
  size_type size_;
  size_type capacity_;
  iterator data_;

  void reallocate(size_type size);
};

};  // namespace s21

#endif