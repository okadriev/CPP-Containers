namespace s21 {

// template <typename T>
// multiset<T>::multiset(std::initializer_list<T> const &items) : set<T>() {
//   for (const auto &item : items) insert(item);

//   this->m_size = items.size();
// }

// template <typename T>
// pair<typename multiset<T>::iterator, bool> multiset<T>::insert(
//     const_reference data) {
//   pair<iterator, bool> result;
//   result.first = this->tree_->insert(data);
//   result.second = true;
//   (this->m_size)++;

//   return result;
// };

template <typename T>
pair<typename multiset<T>::iterator, typename multiset<T>::iterator>
multiset<T>::equal_range(const_reference data) {
  auto range = this->tree_->equal_range(data);
  return {this->tree_->make_iterator(range.first),
          this->tree_->make_iterator(range.second)};
};

template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const_reference data) {
  return equal_range(data).first;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const_reference data) {
  return ++(equal_range(data).second);
}

template <typename T>
void multiset<T>::merge(multiset &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    this->insert(*it);
  }
}

}  // namespace s21