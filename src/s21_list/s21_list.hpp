#pragma once

#include "../s21_sequence_container.hpp"

namespace s21 {

template <class T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  list();
  explicit list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l) noexcept;
  ~list();

  list &operator=(list &&other) noexcept;

  const_reference front() const;
  const_reference back() const;

  const_iterator begin() const;
  const_iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear() noexcept;
  void erase(iterator pos);
  void push_back(const_reference value);
  void push_front(const_reference value);
  void pop_front();
  void pop_back();

  void reverse();
  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void unique();
  // void sort();   
  
  iterator insert(iterator pos, const_reference value);
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

  class ListIterator;

 private:
  struct Node {
    value_type value;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(value_type val = value_type(), Node *next_ = nullptr,
         Node *prev_ = nullptr)
        : value(val), next(next_), prev(prev_) {}
  };

  struct List {
    size_type size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
  };

  List list_;
};

template <typename T>
class list<T>::ListIterator {
  friend class list<T>;

 public:
  ListIterator(list<T>::iterator.Node *node_ = nullptr,
               list<T>::iterator.Node *last_node_ = nullptr)
      : node(node_), last_node(last_node_){};
  ListIterator::ListIterator(list<T>::Node *node_) : node(node_) {}
  ~ListIterator() {
    if (node != nullptr) {
      delete[] node;
    }
    if (last_node != nullptr) {
      delete[] last_node;
    }
  };

  iterator &operator++();
  iterator operator++(int);
  iterator &operator--();
  iterator operator--(int);
  bool operator==(const iterator &other) const;
  bool operator!=(const iterator &other) const;
  bool operator<(const iterator &other) const;
  bool operator<=(const iterator &other) const;
  bool operator>(const iterator &other) const;
  bool operator>=(const iterator &other) const;

 protected:
  struct Iterator {
    list<T>::Node *node;
    list<T>::Node *last_node;
  };

  Iterator iterator;

}  // namespace s21

#include "s21_list.tpp"