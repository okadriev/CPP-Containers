namespace s21 {

template <typename T>
multiset<T>::multiset(std::initializer_list<T> const &items) : set<T>() {
  for (const auto &item : items) insert(item);

  this->m_size = items.size();
}

template <typename T>
std::pair<set_iterator<T>, bool> multiset<T>::insert(const_reference data) {
  std::pair<iterator, bool> result;
  result.first = this->tree->insert(data);
  result.second = true;
  (this->m_size)++;

  return result;
};

template <typename T>
std::pair<set_iterator<T>, set_iterator<T>> multiset<T>::equal_range(
    const_reference data) {
  return this->tree->equal_range(data);
};

template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const_reference data) {
  return equal_range(data).first;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const_reference data) {
  return ++(equal_range(data).second);
}

}  // namespace s21