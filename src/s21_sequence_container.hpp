#ifndef S21_SEQUENCE_CONTAINER_H_
#define S21_SEQUENCE_CONTAINER_H_

#include <algorithm>
#include <iostream>

using std::reverse_iterator, std::fill, std::copy;

namespace s21 {

template <class T>
class s21_sequence_container {
 protected:
  size_t size_;
  size_t capacity_;
  T *data_;

  //  reallocate // ?

 public:
  using iterator = T *;
  //  using const_iterator = const T*;
  using reverse_iterator = std::reverse_iterator<iterator>;
  //  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  using size_type = size_t;

  // constructors and destructors
  s21_sequence_container();  // default constructor
  s21_sequence_container(size_type n,
                         const T &val = T());  // parametrized constructor
  s21_sequence_container(const s21_sequence_container<T> &other);
  noexcept  // copy constructor
      s21_sequence_container(
          s21_sequence_container<T> &&other) noexcept;  // move constructor
  ~s21_sequence_container() noexcept;                   // destructor

  // overload operator
  s21_sequence_container<T> &operator=(
      const s21_sequence_container<T> &other) noexcept;  // copy object
  s21_sequence_container<T> &operator=(
      s21_sequence_container<T> &&other) noexcept;  // move object

  // other methods
  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();

  size_type size() const;
  void resize(size_type n, T val = T());
  bool empty() const;

  void insert(iterator pos, const T &val);
  void insert(iterator pos, size_type n, const T &val);
  //  void insert(iterator pos, ..., ...);  // ?

  iterator erase(iterator pos);
  iterator erase(iterator first, iterator last);

  void push_back(const T &val);
  void pop_back();

  T &front();
  T &back();
};

};  // namespace s21

#endif