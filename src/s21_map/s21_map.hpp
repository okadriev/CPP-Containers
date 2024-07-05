#pragma once

#include <limits>
#include <utility>

#include "../s21_sorted_containers/s21_sorted_containers.hpp"

namespace s21 {

template <typename T1, typename T2 /*, typename comparator = std::less<T1>*/>
class map : public sorted_container<pair<T1, T2>> {
 private:
  using key_type = T1;
  using data_type = T2;
  using value_type = pair<key_type, data_type>;
  using tree_type = rb_tree<value_type>;
  using node_t = Node<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using container = sorted_container<pair<T1, T2>>;
  // using iter_pair_return = pair<typename container::iterator, bool>;

 public:
  using iterator = Iterator<value_type>;
  using const_iterator = const Iterator<value_type>;

  map() : container(false) {};
  map(std::initializer_list<value_type> const &items)
      : container(items, false) {};
  map(const map &other) : container(other) {}
  map(map &&other) : container(other) {}
  ~map() {};

  void erase(const key_type &key) {
    this->tree_->remove(*(this->find(key)));
    this->m_size_--;
  }

  iterator find(const key_type &key) {
    node_t *temp = this->tree_->get_root();

    while (temp != nullptr && temp->data != key) {
      temp = ((temp->data > key) ? temp->left : temp->right);
    }

    return iterator(temp);
  }

  bool contains(const key_type &key) { return find(key) != this->end(); }

  void merge(map &s) { this->container::merge(s); };

  bool operator==(const map &);
  map &operator=(const map &);
  map &operator=(map &&) noexcept;
  data_type &operator[](const key_type &);
};

}  // namespace s21

#include "s21_map_operators.tpp"
