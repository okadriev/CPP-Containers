#include <initializer_list>
#include <iostream>

#include "s21_rb_tree.cpp"

#define PRINT(tree, value)                                           \
  std::cout << "Set " << ((tree.contains(value)) ? "" : "does not ") \
            << "contain " << value << std::endl

namespace s21 {

template <typename T>
class set {
 private:
  using value_type = T;
  using key_type = rb_tree<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  // using iterator = ;
  // using const_iterator = ;
  using size_type = size_t;

  key_type *tree;

 public:
  set() : tree(new key_type()){};
  set(std::initializer_list<value_type> const &items);  // init list constructor
  set(const set &s) : tree(s){};                        // copy constructor
  set(set &&s) : tree(s) { s.tree->root = nullptr; };   // move constructor
  ~set() { delete tree; };

  /*  { this.tree = other.tree; } */;
  set<value_type> &operator=(const set &other);
  set<value_type> &operator=(set &&other) noexcept;

  void insert(const_reference data) { tree->insert(data); };
  bool contains(const_reference data);
};

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set &other) {
  if (this != &other) {
    this->~set();

    this->tree = other.tree;
  }

  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set &&other) noexcept {
  if (this != &other) {
    this->~set();

    this->tree = other.tree;
    other.tree = nullptr;
  }

  return *this;
}

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set() {
  for (const auto &item : items) {
    insert(item);
  }

  // m_size = items.size();
};

template <typename value_type>
bool set<value_type>::contains(const_reference data) {
  return tree->search(data)->data == data;
};

}  // namespace s21

using namespace s21;

int main() {
  set<int> test{1, 2, 3, 4, 5};
  set<int> test2{1, 2, 3, 4};
  test.insert(10);
  test.insert(15);

  PRINT(test, 11);
  PRINT(test, 10);
  PRINT(test, 5);

  PRINT(test2, 11);
  PRINT(test2, 10);
  PRINT(test2, 5);
  test2 = test;

  PRINT(test2, 15);
  PRINT(test2, 11);
  PRINT(test2, 5);

  return 0;
}
