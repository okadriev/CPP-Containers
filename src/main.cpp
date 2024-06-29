// #include <deque>
#include <array>
#include <iostream>
#include <string>

#include "s21_list/s21_list.hpp"
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

  // //  v.push(6);
  // std::cout << "stack v: ";
  // for (size_t i = 0; i < 6; i++) {
  //   v.push(i);
  //   std::cout << v.top() << " ";
  // }
  // std::cout << std::endl;

  // // stack consrtructor
  // std::cout << "stack v1: " << v1.top() << std::endl;

  // std::cout << "stack v2: ";
  // for (size_t i = 0; i < 3; i++) {
  //   std::cout << v2.top() << " ";
  //   v2.pop();
  // }
  // std::cout << std::endl;

  // std::cout << "stack v3: ";
  // for (size_t i = 0; i < 3; i++) {
  //   std::cout << v3.top() << " ";
  //   v3.pop();
  // }
  // std::cout << std::endl;

  // //  v.push_back(6);
  // for (size_t i = 6; i > 0; i--) v.pop();
  // std::cout << "stack empty " << v.empty() << std::endl;

  stack<int, list<int>> sl;
  stack<int, list<int>> sl1(3);
  stack<int, list<int>> sl2{1, 2, 3};
  stack<int, list<int>> sl3(sl2);

  sl.push(6);
  std::cout << "stack sl: " << sl.top() << ' ';
  std::cout << sl.size() << ' ';
  sl.pop();
  std::cout << sl.empty() << std::endl;

  // queue<char, std::string> qFalse3;
  // queue<int, int> qFalse2;
  // queue<int, std::array<int, 10>> qFalse1;
  queue<int> q;
  queue<int> q1(1);
  queue<int> q2{1, 2, 3};
  queue<int> q3(q2);

  // //  q.push(6);
  // std::cout << "queue: ";
  // for (size_t i = 0; i < 6; i++) {
  //   q.push(i);
  //   std::cout << q.back() << " ";
  // }
  // std::cout << std::endl;

  // // queue consrtructor
  // std::cout << "queue q1: " << q1.front() << std::endl;

  // std::cout << "queue q2: ";
  // for (size_t i = 0; i < 3; i++) {
  //   std::cout << q2.front() << " ";
  //   q2.pop();
  // }
  // std::cout << std::endl;

  // std::cout << "queue q3: ";
  // for (size_t i = 0; i < 3; i++) {
  //   std::cout << q3.front() << " ";
  //   q3.pop();
  // }
  // std::cout << std::endl;

  // // Ожидаемый вывод: < >
  // std::cout << "sample ";
  // for (size_t i = 0; i < 6; ++i) {
  //   std::cout << i << " ";
  // }
  // std::cout << std::endl;

  // //  q.push_back(6);
  // for (size_t i = 6; i > 0; i--) q.pop();
  // std::cout << "queue empty " << q.empty() << std::endl;

  queue<int, list<int>> ql;
  queue<int, list<int>> ql1(3);
  queue<int, list<int>> ql2{1, 2, 3};
  queue<int, list<int>> ql3(ql2);

  ql.push(6);
  std::cout << "queue ql: " << ql.front() << ' ';
  std::cout << ql.size() << ' ';
  ql.pop();
  std::cout << ql.empty() << std::endl;

  // list<int> l;
  list<int> l1(6);
  // list<int> l2{1, 2, 3, 4, 5, 6};
  // list<int> l3(l2);
  // std::cout << "list l: ";
  // l.print_list();
  // std::cout << "list l1: ";
  // l1.print_list();
  // std::cout << "list l2: ";
  // l2.print_list();
  // std::cout << "list l3: ";
  // l3.print_list();

  // l.push_back(1);
  // std::cout << "list.push_back: " << l.back() << std::endl;
  // l.print_list();
  // l.push_front(2);
  // std::cout << "list.push_front: " << l.front() << std::endl;
  // l.print_list();
  // l.push_front(3);
  // std::cout << "list.push_front: " << l.front() << std::endl;
  // l.print_list();
  // l.insert(l.begin(), l.back());
  // std::cout << "list.insert: " << l.back() << std::endl;
  // l.print_list();
  // l.sort();
  // std::cout << "list.sort: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();
  // l.merge(l2);
  // std::cout << "list.merge: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();

  // l.reverse();
  // std::cout << "list.reverse: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();
  // l.splice(l.begin(), l2);
  // std::cout << "list.splice: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();
  // l.swap(l2);
  // std::cout << "list.swap: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();
  // l.erase(l.begin());
  // std::cout << "list.erase: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();
  // l.insert_many(l.begin(), 1, 2, 3);
  // std::cout << "list.insert_many: " << l.front() << ' ' << l.back()
  //           << std::endl;
  // l.print_list();
  // l.insert_many_back(1, 2, 3);
  // std::cout << "list.insert_many_back: " << l.front() << ' ' << l.back()
  //           << std::endl;
  // l.print_list();
  // l.insert_many_front(1, 2, 3);
  // std::cout << "list.insert_many_front: " << l.front() << ' ' << l.back()
  //           << std::endl;
  // l.print_list();
  // l.pop_back();
  // std::cout << "list.pop_back: " << l.back() << std::endl;
  // l.print_list();
  // l.unique();
  // std::cout << "list.unique: " << l.front() << ' ' << l.back() << std::endl;
  // l.print_list();
  // l.pop_front();
  // std::cout << "list.pop_front: " << l.front() << std::endl;
  // l.print_list();
  std::cout << "list.size: " << l.size() << std::endl;
  // std::cout << "list.empty: " << l.empty() << std::endl;

  return 0;
}
