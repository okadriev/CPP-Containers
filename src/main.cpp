// #include <deque>
#include <array>
#include <iostream>
#include <string>

#include "s21_queue/s21_queue.hpp"
#include "s21_stack/s21_stack.hpp"

using namespace s21;

int main() {
  // stack<char, std::string> vFalse3;
  // stack<int, int> vFalse2;
  // stack<int, std::array<int, 10>> vFalse1;
  stack<int> v;
  stack<int> v1(1);
  stack<int> v2{1, 2, 3};
  stack<int> v3(v2);

  // queue<char, std::string> qFalse3;
  // queue<int, int> qFalse2;
  // queue<int, std::array<int, 10>> qFalse1;
  queue<int> q;
  queue<int> q1(1);
  queue<int> q2{1, 2, 3};
  queue<int> q3(q2);

  //  v.push(6);
  std::cout << "stack v: ";
  for (size_t i = 0; i < 6; i++) {
    v.push(i);
    std::cout << v.top() << " ";
  }
  std::cout << std::endl;

  // stack consrtructor
  std::cout << "stack v1: " << v1.top() << std::endl;

  std::cout << "stack v2: ";
  for (size_t i = 0; i < 3; i++) {
    std::cout << v2.top() << " ";
    v2.pop();
  }
  std::cout << std::endl;

  std::cout << "stack v3: ";
  for (size_t i = 0; i < 3; i++) {
    std::cout << v3.top() << " ";
    v3.pop();
  }
  std::cout << std::endl;

  //  q.push(6);
  std::cout << "queue: ";
  for (size_t i = 0; i < 6; i++) {
    q.push(i);
    std::cout << q.back() << " ";
  }
  std::cout << std::endl;

  // queue consrtructor
  std::cout << "queue q1: " << q1.front() << std::endl;

  std::cout << "queue q2: ";
  for (size_t i = 0; i < 3; i++) {
    std::cout << q2.front() << " ";
    q2.pop();
  }
  std::cout << std::endl;

  std::cout << "queue q3: ";
  for (size_t i = 0; i < 3; i++) {
    std::cout << q3.front() << " ";
    q3.pop();
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
