#include "s21_vector.hpp"

using namespace s21;

int main() {
  /* test 1 */
  //  vector<int> v = {};
  //  v.insert(v.begin(), 15);
  //
  //  //  v.push_back(6);
  //  for (size_t i = 0; i < v.size(); i++) {
  //    std::cout << v.at(i) << " ";
  //  }
  //  std::cout << std::endl;
  //
  //  v.erase(v.begin());
  //
  //  // Ожидаемый вывод: < >
  //  for (size_t i = 0; i < v.size(); ++i) {
  //    std::cout << v.at(i) << " ";
  //  }
  //  std::cout << std::endl;

  /* test 2 */
  //  vector<int> v = {1, 2, 3, 4};
  //
  //  vector<int>::const_iterator it;
  //  it = v.begin();
  //  while (it != v.end()) {
  //    std::cout << *it << " " << std::endl;
  //    it++;
  //  }

  /* test 3 */
  //  vector<int> v;
  //
  //  v.insert_many(v.end(), 1, 2, 3, 4);
  //  std::cout << "Insert many";
  //  for (auto &el : v) {
  //    std::cout << " " << el;
  //  }
  //  std::cout << std::endl;
  // output: 1 2 3 4

  //  v.insert_many_back(5, 6, 7);
  //  std::cout << "Insert many back";
  //  for (auto &el : v) {
  //    std::cout << " " << el;
  //  }
  //  std::cout << std::endl;
  // output: 1 2 3 4 5 6 7

  //  v.insert_many(v.begin() + 1, 8, 9);
  //  std::cout << "Insert many";
  //  for (auto &el : v) {
  //    std::cout << " " << el;
  //  }
  //  std::cout << std::endl;
  // output: 1 8 9 2 3 4 5 6 7
}