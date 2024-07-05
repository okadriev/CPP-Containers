namespace s21 {
template <typename value_type>
sorted_container<value_type>::sorted_container(
    std::initializer_list<value_type> const &items, bool multi)
    : sorted_container(multi) {
  insert(items);
}

template <typename T>
bool s21::sorted_container<T>::insert_value(const value_type &value) {
  tree_->insert(value);
  m_size_++;
  return true;
}

template <typename T>
void sorted_container<T>::insert(std::initializer_list<T> items) {
  for (const auto &item : items) insert(item);
}

template <typename T>
pair<Iterator<T>, bool> sorted_container<T>::insert(value_type &&value) {
  bool result = false;
  if (multi_ || !contains(value)) {
    result = insert_value(std::move(value));
  }
  return {find(value), result};
}

template <typename T>
pair<Iterator<T>, bool> sorted_container<T>::insert(const value_type &value) {
  value_type rvalue(value);
  return insert(std::move(rvalue));
}

template <typename T>
typename sorted_container<T>::iterator sorted_container<T>::find(
    const value_type &key) {
  return iterator(this->tree_->search(key));
}

template <typename T>
bool sorted_container<T>::contains(const value_type &key) {
  return find(key) != end();
}

template <typename T>
void sorted_container<T>::erase(const value_type &key) {
  this->tree_->remove(key);
  this->m_size_--;
}

template <typename T>
void sorted_container<T>::clear() {
  this->tree_->delete_tree();
  this->m_size_ = 0;
  // while (this->begin() != this->end()) {
  //   erase((*this->begin()));
  // }
}

template <typename T>
void sorted_container<T>::merge(sorted_container &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    this->insert(*it);
  }
}

template <class T>
void sorted_container<T>::swap(sorted_container &other) noexcept {
  std::swap(this->tree_, other.tree_);
  std::swap(this->m_size_, other.m_size_);
}
}  // namespace s21