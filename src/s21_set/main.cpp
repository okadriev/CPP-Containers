#include <iostream>

#include "s21_multiset.hpp"
#include "s21_set.hpp"

using namespace s21;

int main() {
  multiset<int> test{15, 10, 16, 15, 15, 15};
  test.print();
  std::cout << "size = " << test.size() << std::endl;
  // test.erase(test.find(15));
  std::pair<set_iterator<int>, set_iterator<int>> range = test.equal_range(15);
  for (auto it = range.first; it != range.second; ++it) {
    std::cout << *it << "яя ";
  }
  std::cout << std::endl;
  std::cout << "count " << test.count(15) << " " << test.count(16) << std::endl;
  std::cout << "contains " << test.contains(15) << " " << std::endl;
  for (auto it = test.lower_bound(15); it != test.upper_bound(15); ++it) {
    std::cout << *it << "яя ";
  }
  std::cout << test.size() << std::endl;
  // std::cout << "before clear \n";
  // for (int n : test) std::cout << n << " ";
  // std::cout << "\nafter clear \n";
  // test.clear();
  // for (int n : test) std::cout << n << " ";
  // std::cout << std::endl;
  multiset<int> test2{1, 2, 3, 4, 11};
  multiset<int> test3(test);

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
  // test.print();

  // std::cout << "test " << std::endl;
  // test.print();

  test2 = test;
  test2.erase(test2.begin());
  std::pair<set_iterator<int>, bool> pair = test2.insert(15);
  // std::cout << "result = " << *(pair.first) << std::endl;

  // std::cout << "test1 " << std::endl;
  // test.print();
  // std::cout << "test2 " << std::endl;
  // test2.print();

  test.swap(test2);
  // std::cout << "test1 " << std::endl;
  // test.print();
  // std::cout << "test2 " << std::endl;
  // test2.print();

  test.merge(test2);
  // std::cout << "test1 " << std::endl;
  test.insert(1);
  test.insert(1);
  test.insert(1);
  // test.print();

  return 0;
}

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