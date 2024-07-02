// #include "s21_map.hpp"

namespace s21 {

template <class T1, class T2>
void map<T1, T2>::merge(map &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    this->insert(*it);
  }
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::find(const key_type &key) {
  value_type data(key, data_type());
  return container::find(data);
}

template <typename T1, typename T2>
std::size_t map<T1, T2>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <class T1, class T2>
void map<T1, T2>::swap(map &other) noexcept {
  std::swap(this->tree_, other.tree_);
  std::swap(this->m_size_, other.m_size_);
}

}  // namespace s21
