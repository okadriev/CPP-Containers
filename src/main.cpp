#include <iostream>

#include "s21_queue/s21_queue.hpp"
#include "s21_stack/s21_stack.hpp"

using namespace s21;

int main() {
  stack<int> v;
  queue<int> q;

  //  q.push(6);
  std::cout << "queue ";
  for (size_t i = 0; i < 6; i++) {
    q.push(i);
    std::cout << q.back() << " ";
  }
  std::cout << std::endl;

  //  v.push(6);
  std::cout << "stack ";
  for (size_t i = 0; i < 6; i++) {
    v.push(i);
    std::cout << v.top() << " ";
  }
  std::cout << std::endl;

  // Ожидаемый вывод: < >
  std::cout << "sample ";
  for (size_t i = 0; i < 6; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  //  v.push_back(6);
  for (size_t i = 6; i > 0; i--) v.pop();
  std::cout << "stack empty " << v.empty() << std::endl;

  //  q.push_back(6);
  for (size_t i = 6; i > 0; i--) q.pop();
  std::cout << "queue empty " << q.empty() << std::endl;

  return 0;
}
