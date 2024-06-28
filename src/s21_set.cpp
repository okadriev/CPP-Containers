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
  size_type m_size;

 public:
  set() : tree(new key_type()), m_size(0) {};
  set(std::initializer_list<value_type> const &items);
  set(const set &s) : tree(new key_type()), m_size(s.m_size) {
    tree->copy_tree(s.tree);
  }
  set(set &&s) : tree(s), m_size(s.m_size) { s.tree = nullptr, s.m_size = 0; };
  ~set() { delete tree; };

  set<value_type> &operator=(const set &other);
  set<value_type> &operator=(set &&other) noexcept;

  void print() { tree->print_tree(); }  // удалить??
  void insert(const_reference data);
  void erase(const_reference data);
  bool contains(const_reference data);
  size_type size() const { return m_size; }
};

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set &other) {
  if (this != &other) {
    delete tree;
    tree = new key_type();
    m_size = other.m_size;
    tree->copy_tree(other.tree);
  }

  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set &&other) noexcept {
  if (this != &other) {
    delete tree;

    tree->root = other.tree->root;
    other.tree->root = nullptr;
  }

  return *this;
}

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set() {
  for (const auto &item : items) {
    insert(item);
  }

  m_size = items.size();
};

template <typename value_type>
bool set<value_type>::contains(const_reference data) {
  // Node<value_type> *node = tree->search(data);
  // std::cout << (node ? node->data : -1) << " ";

  return tree->search(data) != nullptr;
};

template <typename value_type>
void set<value_type>::insert(const_reference data) {
  if (!contains(data)) {
    tree->insert(data);
    ++m_size;
  }
}

template <typename value_type>
void set<value_type>::erase(const_reference data) {
  if (contains(data)) {
    tree->remove(data);
    --m_size;
  }
};

}  // namespace s21

using namespace s21;

// int main() {
//   set<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
//   18}; set<int> test2{1, 2, 3, 4, 11}; set<int> test3(test);
//   // PRINT(test, 11);
//   // test.insert(11);

//   // test.print();
//   test.erase(15);
//   test.erase(14);
//   test.erase(13);
//   test.erase(12);
//   test.erase(4);
//   test.erase(1);
//   test.erase(18);
//   test.erase(17);
//   test.erase(2);
//   test.erase(7);
//   test.erase(16);
//   test.print();

//   std::cout << "test " << std::endl;
//   test.print();
//   test2 = test;
//   test2.insert(15);
//   std::cout << "test2 " << std::endl;
//   test2.print();
//   std::cout << "test1 " << std::endl;
//   test.print();

//   return 0;
// }
