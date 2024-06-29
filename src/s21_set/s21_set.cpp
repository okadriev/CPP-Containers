#include <limits>

#include "s21_rb_tree.cpp"  //сделать нормально

namespace s21 {

template <typename T>
class set_iterator {
 private:
  using value_type = T;
  using pointer = T *;
  using reference = T &;

  Node<value_type> *node_;

  Node<value_type> *next_node(Node<value_type> *node) const;

 public:
  set_iterator() : node_(nullptr) {};
  set_iterator(Node<value_type> *node) : node_(node) {};
  ~set_iterator() {};

  bool operator==(const set_iterator &s) const { return (node_ == s.node_); };
  bool operator!=(const set_iterator &s) const { return (node_ != s.node_); };
  reference operator*() const { return node_->data; };
  set_iterator &operator++() {
    node_ = next_node(node_);

    return *this;
  };
};

template <typename T>
Node<T> *set_iterator<T>::next_node(Node<T> *node) const {
  if (node == nullptr) return nullptr;

  Node<T> *next = nullptr;

  if (node->right) {
    next = node->right;
    while (next->left) next = next->left;

  } else {
    next = node->parent;
    while (next && node == next->right) {
      node = next;
      next = next->parent;
    }
  }

  return next;
};

template <typename T>
class set {
 private:
  using value_type = T;
  using key_type = rb_tree<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = set_iterator<T>;
  using const_iterator = const set_iterator<T>;
  using size_type = std::size_t;

  key_type *tree;
  size_type m_size;

 public:
  set() : tree(new key_type()), m_size(0) {};
  set(std::initializer_list<value_type> const &items);
  set(const set &s) : tree(new key_type()), m_size(s.m_size) {
    tree->copy_tree(s.tree);
  };
  set(set &&s) : tree(s), m_size(s.m_size) { s.tree = nullptr, s.m_size = 0; };
  ~set() { delete tree; };

  set<value_type> &operator=(const set &other);
  set<value_type> &operator=(set &&other) noexcept;

  void clear();
  std::pair<iterator, bool> insert(const_reference data);
  void erase(const_reference data);
  void erase(iterator pos);
  void swap(set &other);
  void merge(set &other);

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

template <typename value_type>
set<value_type>::set(std::initializer_list<value_type> const &items) : set() {
  for (const auto &item : items) insert(item);
  m_size = items.size();
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
void set<value_type>::clear() {
  delete tree;
  new key_type();
  m_size = 0;
}

template <typename value_type>
std::pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const_reference data) {
  bool result = false;
  iterator ptr = nullptr;

  if (!contains(data)) {
    ptr = tree->insert(data);
    ++m_size;

    result = true;
  }

  return std::make_pair(ptr, result);
}

template <typename value_type>
void set<value_type>::erase(const_reference data) {
  if (contains(data)) {
    tree->remove(data);
    --m_size;
  }
};

template <typename value_type>
void set<value_type>::erase(iterator pos) {
  if (pos != end() && contains(*pos)) {
    tree->remove(*pos);
    --m_size;
  }
};

template <typename value_type>
void set<value_type>::swap(set &other) {
  std::swap(tree, other.tree);
  std::swap(m_size, other.m_size);
}

template <typename value_type>
void set<value_type>::merge(set &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

}  // namespace s21

/* using namespace s21;

int main() {
  set<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
  // std::cout << "before clear \n";
  for (int n : test) std::cout << n << " ";
  // std::cout << "\nafter clear \n";
  // test.clear();
  // for (int n : test) std::cout << n << " ";
  std::cout << std::endl;
  set<int> test2{1, 2, 3, 4, 11};
  set<int> test3(test);

  // std::set<int> numbers{2, 1, 3, 4, 5};
  // std::cout << "max size = " << numbers.max_size() << std::endl;
  // std::cout << "max size = " << test.max_size() << std::endl;
  // for (int elem : numbers) std::cout << elem << " ";
  // std::cout << "before clear \n";
  // numbers.clear();
  // std::cout << "\nafter clear \n";
  // for (int elem : numbers) std::cout << elem << " ";

  // std::cout << std::endl;
  // test.print();
  test.erase(15);
  test.erase(14);
  test.erase(13);
  test.erase(12);
  test.erase(4);
  test.erase(1);
  test.erase(18);
  test.erase(17);
  test.erase(2);
  test.erase(7);
  test.erase(16);
  test.print();

  // std::cout << "test " << std::endl;
  // test.print();
  test2 = test;
  test2.erase(test2.begin());
  std::pair<set_iterator<int>, bool> pair = test2.insert(15);
  std::cout << "result = " << *(pair.first) << std::endl;

  std::cout << "test1 " << std::endl;
  test.print();
  std::cout << "test2 " << std::endl;
  test2.print();

  test.swap(test2);
  std::cout << "test1 " << std::endl;
  test.print();
  std::cout << "test2 " << std::endl;
  test2.print();

  test.merge(test2);
  std::cout << "test1 " << std::endl;
  test.print();

  return 0;
} */