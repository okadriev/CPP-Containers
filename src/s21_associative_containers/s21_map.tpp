#include "s21_map.hpp"

namespace s21 {

template <typename T1, typename T2>
s21::map<T1, T2>::map(std::initializer_list<value_type> const &items) {
  for (const auto &item : items) insert(item);
  m_size = items.size();
}

}  // namespace s21