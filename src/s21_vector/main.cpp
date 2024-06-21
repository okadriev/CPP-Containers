#include "s21_vector.hpp"

using namespace s21;

int main() {
  vector<int> v = {};
  v.insert(v.begin(), 15);

  //  v.push_back(6);
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v.at(i) << " ";
  }
  std::cout << std::endl;

  v.erase(v.begin());

  // Ожидаемый вывод: < >
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << v.at(i) << " ";
  }
  std::cout << std::endl;
}