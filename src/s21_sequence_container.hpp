#ifndef S21_SEQUENCE_CONTAINER_H_
#define S21_SEQUENCE_CONTAINER_H_

#include <iostream>

namespace s21 {

template <class T>
class s21_sequence_container {
 private:
  T *data;
  //  reallocate // ?

 public:
  using iterator = T *;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using size_type = size_t;

  // constructors and destructors
  s21_sequence_container();
  s21_sequence_container(const s21_sequence_containers<T> &other);
  s21_sequence_container(size_type n, const T &val = T());
  ~s21_sequence_container();

  // overload operator
  s21_sequence_containers<T> &operator=(
      const s21_sequence_containers<T> &other);

  // other methods
  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();

  size_type size() const;
  void resize(size_type n, T val = T());
  bool empty() const;

  void insert(iterator position, const T &val);
  void insert(iterator position, size_type n, const T &val);
  //  void insert(iterator position, ..., ...);  // ?

  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);

  void push_back(const T &val);
  void pop_back();

  T &front();
  T &back();
};

};  // namespace s21

#endif