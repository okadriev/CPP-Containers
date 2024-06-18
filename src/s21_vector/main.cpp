#include "s21_vector.hpp"

using namespace s21;

int main() {
  s21_vector<int> v = {};
  v.insert(v.begin(), 15);

  //  v.push_back(6);
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v.at(i) << " ";
  }
  std::cout << std::endl;

  v.erase(v.begin());

  // Ожидаемый вывод: 1 2 3 4 5 6 7 8 9
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v.at(i) << " ";
  }
  std::cout << std::endl;
}