namespace s21 {

template <typename T>
multiset<T>::multiset(std::initializer_list<T> const &items) : set<T>() {
  for (const auto &item : items) insert(item);

  this->m_size = items.size();
}

template <typename value_type>
std::pair<typename s21::set_iterator<value_type>, bool>
multiset<value_type>::insert(const_reference data) {
  std::pair<iterator, bool> result;
  result.first = this->tree->insert(data);
  result.second = true;
  (this->m_size)++;

  return result;
};

template <typename T>
std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const_reference data) {
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