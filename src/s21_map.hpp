#pragma once
#include "s21_assotiative_containers/s21_assotiative_containers.hpp"

namespace s21 {

template <typename T1, typename T2>
class map : public associative_container<T1, T2> {
 private:
  using key_type = T1;
  using value_type = T2;
  using tree_type = rb_tree<key_pair<key_type, value_type>>;
  using reference = key_pair<key_type, value_type> &;
  using const_reference = const key_pair<key_type, value_type> &;
  using iterator = typename associative_container<T1, T2>::iterator;
  using const_iterator = const typename associative_container<T1, T2>::iterator;
  using size_type = typename associative_container<T1, T2>::size_type;

  key_type *tree;
  size_type m_size;

 public:
  map() : tree(new key_type()), m_size(0) {};
  map(std::initializer_list<value_type> const &items);
  map(const map &s) : tree(new key_type()), m_size(s.m_size) {
    tree->copy_tree(s.tree);
  };
  map(map &&s) : tree(s), m_size(s.m_size) { s.tree = nullptr, s.m_size = 0; };
  ~map() { delete tree; };

  map<key_type, value_type> &operator=(const map &other);
  map<key_type, value_type> &operator=(map &&other) noexcept;

  void clear();
  std::pair<iterator, bool> insert(const_reference data);
  void erase(const_reference data);
  void erase(iterator pos);
  void swap(map &other);
  void merge(map &other);

  void print() { tree->print_tree(); };
  iterator find(const_reference data) { return iterator(tree->search(data)); };
  bool contains(const_reference data) { return find(data) != end(); };
  iterator begin() const { return iterator(tree->min()); };
  iterator end() const { return iterator(nullptr); };

  bool empty() const { return tree->empty(); };
  size_type size() const { return m_size; };
  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  };
};

template <typename T1, typename T2>
class map_bak : public associative_container<T1, T2> {
 private:
  using key_type = T1;
  using value_type = T2;
  using tree_type = rb_tree<key_pair<key_type, value_type>>;
  using reference = key_pair<key_type, value_type> &;
  using const_reference = const key_pair<key_type, value_type> &;
  using iterator =
      typename associative_container<key_type, value_type>::iterator;
  using const_iterator =
      const typename associative_container<key_type, value_type>::iterator;
  using size_t = std::size_t;
  using node_type = Node<key_pair<key_type, value_type>>;

 private:
  tree_type tree_;
  Node<tree_type> *root_ = nullptr;

 public:
};
}  // namespace s21
