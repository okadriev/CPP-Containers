#include <iostream>

template <typename T>
struct Node {
  T data;
  Node<T> *left, *right, *parent;
  bool is_red;

  Node(T val)
      : data(val),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        is_red(true) {}
};

template <typename T>
class set {
 private:
  Node<T> *root;

  // Методы для вставки, удаления, балансировки и прочих операций

 public:
  set() : root(nullptr) {}

  ~set() {
    // Реализация удаления всех узлов дерева
  }

  // Методы для добавления, удаления, поиска элементов и прочих операций
};

int main() {
  // Пример использования
  set<int> test;

  test.add(10);
  test.add(5);
  test.add(15);

  if (test.contains(5))
    std::cout << "Set contains 5\n";
  else
    std::cout << "Set does not contain 5\n";

  return 0;
}