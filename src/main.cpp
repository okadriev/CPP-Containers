#include <iostream>

// #include "s21_queue/s21_queue.hpp"
#include "s21_stack/s21_stack.hpp"

using namespace s21;

int main() {
  stack<int> v;

  //  v.push_back(6);
  for (size_t i = 0; i < 6; i++) {
    v.push(i);
    std::cout << v.top() << " ";
  }
  std::cout << std::endl;

  // Ожидаемый вывод: < >
  for (size_t i = 0; i < 6; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  //  v.push_back(6);
  for (size_t i = 6; i > 0; i--) {
    v.pop();
    std::cout << v.top() << " ";
  }
  std::cout << std::endl;

  for (size_t i = 6; i > 0; i--) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}

//  g++ -Wall -Werror -Wextra main.cpp s21_vector/s21_vector.tpp s21_stack/s21_stack.tpp 