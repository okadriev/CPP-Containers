#include "s21_vector.hpp"

using namespace s21;

int main() {
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

  vector<int> v = {1, 2, 3, 4};

  vector<int>::const_iterator it;
  it = v.begin();
  while (it != v.end()) {
    std::cout << *it << " " << std::endl;
    it++;
  }
}