namespace s21 {

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

}  // namespace s21